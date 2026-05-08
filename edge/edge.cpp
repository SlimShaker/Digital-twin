#include "edge.hpp"

edgeNode::edgeNode(const std::string& broker, const std::string& type, const std::string& topic)
    : edge_type(type), topic_name(topic), counter(0), cb(type) {
    client = std::make_unique<mqtt::async_client>(broker, "edge_"+edge_type);
    laneClient = std::make_unique<mqtt::async_client>(config::CLOUD_BROKER, "lane_"+edge_type);
    cb.setActiveHandler([this](bool a) {
        active = a;
        if (a)
            counter=0;
        std::cout << "[EDGE " << edge_type << "] active=" << a << std::endl;
    });
    client->set_callback(cb);
    laneClient->set_callback(cb);
}

void edgeNode::start() {
    while (!client->is_connected()) {
        try {
            client->connect()->wait();
        } catch (...) {
            std::cout << "[EDGE] retrying broker...\n";
            std::this_thread::sleep_for(std::chrono::seconds(2));
        }
    }
    while (!laneClient->is_connected()) {
        try {
            laneClient->connect()->wait();
        } catch (...) {
            std::this_thread::sleep_for(std::chrono::seconds(2));
        }
    }
    laneClient->subscribe(config::TOPIC_LANE, 1)->wait();
    std::cout << "[EDGE] started: " << edge_type << std::endl;
    std::mt19937 gen(std::random_device{}());
    std::uniform_int_distribution<> dist(0, 100);
    while (true) {
        std::this_thread::sleep_for(std::chrono::seconds(2));
        if (!active) continue;
        if (!client->is_connected()) continue;
        nlohmann::json j;
        j["edgeNode"] = edge_type;
        j["id"] = counter++;
        j["weight"] = dist(gen);
        j["trace"]["edge_sent"] = rep.getEpochMs();
        std::string pub_topic;
        if (edge_type == config::HOME_EDGE_TYPE)
            pub_topic = config::TOPIC_HOME;
        else if (edge_type == config::WORK_EDGE_TYPE)
            pub_topic = config::TOPIC_WORK;
        else
            pub_topic = config::TOPIC_TWIN;
        try {
            client->publish(pub_topic, j.dump().c_str(), j.dump().size(), 1, false);
            std::cout << "[EDGE] sent from " << edge_type << std::endl;
        } catch (...) {
            std::cout << "[EDGE] publish failed\n";
        }
    }
}
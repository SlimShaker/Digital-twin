// Created by Hussein on 2026-04-12.
#include "edge.hpp"

edgeNode::edgeNode(const std::string& broker, const std::string& type, const std::string& topic) : client(broker, "edge_" + type), edge_type(type),topic_name(topic), counter(0), currentBroker(broker) {}

void edgeNode::start() {
    cb.setRouteHandler([this](const std::string& route) {
        handleRoute(route);
    });
    client.set_callback(cb);

    while (!client.is_connected()) {
        try {
            client.connect()->wait();
        } catch (...) {
            std::cout << "[EDGE] retrying broker...\n";
            std::this_thread::sleep_for(std::chrono::seconds(2));
        }
    }
    client.subscribe(config::TOPIC_LANE, 1)->wait();
    std::cout << "[EDGE] started: " << edge_type << std::endl;
    std::mt19937 gen(std::random_device{}());
    std::uniform_int_distribution<> dist(0, 100);
    while (true) {
        std::this_thread::sleep_for(std::chrono::seconds(2));
        nlohmann::json j;
        j["edgeNode"] = edge_type;
        j["id"] = counter++;
        j["weight"] = dist(gen);
        j["trace"]["edge_sent"]=rep.getEpochMs();

        client.publish(config::TOPIC_TWIN, j.dump().c_str(), j.dump().size(), 1, false);
        std::cout << "[EDGE] sent from " << edge_type << "\n";
    }
}
void edgeNode::handleRoute(const std::string& route) {
    std::string newBroker=resolveBroker(route);
    if (newBroker==currentBroker) {
        return;
    }
    std::cout<<"EDGE Switching broker ->" << newBroker<<std::endl;
    try {
        client.disconnect()->wait();
    }catch (...) {}

    currentBroker=newBroker;
    client=mqtt::async_client(currentBroker,"edge_"+edge_type);
    client.set_callback(cb);

    while (!client.is_connected()) {
        try {
            client.connect()->wait();
        }catch (...) {
            std::cout << "[EDGE] reconncet retry..." << std::endl;
            std::this_thread::sleep_for(std::chrono::seconds(2));
        }
    }
    client.subscribe(config::TOPIC_LANE, 1)->wait();
}

std::string edgeNode::resolveBroker(const std::string& route) {
    if (route == "fog1")
        return config::FOG1_BROKER;
    if (route == "fog2")
        return config::FOG2_BROKER;
    return config::CLOUD_BROKER;
}
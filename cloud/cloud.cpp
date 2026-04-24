#include "cloud.hpp"

cloud::cloud() : client("tcp://cloud_broker:1883", "cloud_logger") {}

void cloud::start() {
    cloudCallBack cb(rep);
    client.set_callback(cb);
    client.connect()->wait();
    client.subscribe("cloud/data", 1)->wait();
    std::cout << "Cloud running...\n";
    while (true) {
        std::this_thread::sleep_for(std::chrono::seconds(10));
    }
}
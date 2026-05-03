#include "cloud.hpp"

cloud::cloud(const std::string& b) : client(b, "cloud_logger") {}

void cloud::start() {
    cloudCallBack cb(rep);
    client.set_callback(cb);
    client.connect()->wait();
    client.subscribe("twin/data",1)->wait();
    std::cout << "cloud logger statred" << std::endl;
    while (true) {
        std::this_thread::sleep_for(std::chrono::seconds(10));
    }
}
//Created by Hussein 2026-04-17
#pragma once
#include <string>
namespace config {
    //Brokers
    const std::string CLOUD_BROKER="tcp://192.168.1.217:1883";
    const std::string FOG1_BROKER="tcp://192.168.1.187:1883";
    const std::string FOG2_BROKER="tcp://192.168.1.222:1883";

    //types
    const std::string HOME_EDGE_TYPE   = "home";
    const std::string MOBILE_EDGE_TYPE = "mobile";
    const std::string WORK_EDGE_TYPE   = "work";

    //Ids
    const std::string FOG1_ID = "smart_router";
    const std::string FOG2_ID = "local_server";

    //topics
    const std::string TOPIC_TWIN  = "twin/data";
    const std::string TOPIC_LANE  = "system/lane";
    const std::string TOPIC_HOME   = "human/home";
    const std::string TOPIC_WORK   = "human/work";
    const std::string TOPIC_MOBILE = "human/mobile";
}
//Created by Hussein 2026-04-17
#pragma once
#include <string>
namespace config {

    const std::string CLOUD_BROKER="tcp://cloud_broker:1883";
    const std::string FOG1_BROKER="tcp://smart_router_broker:1883";
    const std::string FOG2_BROKER="tcp://local_server_broker:1883";

    //node Ids
    const std::string HOME_EDGE_ID   = "home";
    const std::string MOBILE_EDGE_ID = "mobile";
    const std::string WORK_EDGE_ID   = "work";

    const std::string FOG1_ID = "smart_router";
    const std::string FOG2_ID = "local_server";

    //topics
    const std::string TOPIC_TWIN  = "twin/data";
    const std::string TOPIC_LANE  = "system/lane";
    const std::string TOPIC_HOME   = "human/home";
    const std::string TOPIC_WORK   = "human/work";
    const std::string TOPIC_MOBILE = "human/mobile";

}
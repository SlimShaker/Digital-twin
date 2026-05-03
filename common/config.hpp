//Created by Hussein 2026-04-17
#pragma once
#include <string>
namespace config {

    const std::string BROKER="tcp://mosquitto:1883";
    const std::string FOG_BROKER="tcp://smart_router:1883";

    //node Ids
    const std::string HOME_EDGE_ID   = "edge_home";
    const std::string MOBILE_EDGE_ID = "edge_mobile";
    const std::string WORK_EDGE_ID   = "edge_work";

    const std::string FOG1_ID = "smart_router";
    const std::string FOG2_ID = "local_server";

    //topics
    const std::string TOPIC_TWIN  = "twin/data";
    const std::string TOPIC_LANE  = "system/lane";


}
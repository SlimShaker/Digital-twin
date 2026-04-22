//Created by Hussein 2026-04-17
#pragma once
#include <string>
namespace config {

    //brokers
    const std::string FOG1_BROKER  = "tcp://fog_one_broker:1883";
    const std::string FOG2_BROKER  = "tcp://fog_two_broker:1883";
    const std::string CLOUD_BROKER = "tcp://cloud_broker:1883";

    //node Ids
    const std::string HOME_EDGE_ID   = "edge_home";
    const std::string MOBILE_EDGE_ID = "edge_mobile";
    const std::string WORK_EDGE_ID   = "edge_work";

    const std::string FOG1_ID = "fog1_node";
    const std::string FOG2_ID = "fog2_node";

    //edge node types
    const std::string HOME_NODE = "home";
    const std::string MOBILE_NODE = "mobile";
    const std::string WORK_NODE = "work";
    //topics
    const std::string TOPIC_HOME   = "human/home";
    const std::string TOPIC_MOBILE = "human/mobile";
    const std::string TOPIC_WORK   = "human/work";

    const std::string TOPIC_MIGRATION = "system/migration";


}
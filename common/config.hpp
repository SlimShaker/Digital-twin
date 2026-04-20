//Created by Hussein 2026-04-17
#pragma once
#include <string>

namespace config {

    // Brokers
    const std::string FOG1_BROKER  = "tcp://fog1:1883";
    const std::string FOG2_BROKER  = "tcp://fog2:1883";
    const std::string CLOUD_BROKER = "tcp://cloud:1883";

    // Node IDs
    const std::string HOME_EDGE_ID   = "edge_home";
    const std::string MOBILE_EDGE_ID = "edge_mobile";
    const std::string WORK_EDGE_ID   = "edge_work";

    const std::string FOG1_ID = "fog1_node";
    const std::string FOG2_ID = "fog2_node";

    // Topics
    const std::string TOPIC_HOME   = "human/home";
    const std::string TOPIC_MOBILE = "human/mobile";
    const std::string TOPIC_WORK   = "human/work";

    const std::string TOPIC_MIGRATION = "system/migration";

    // Timing
    const int SAMPLE_INTERVAL_MS = 500;

}
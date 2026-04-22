#include "fogCallBack.hpp"



fogCallBack::fogCallBack(digital_human& t, const std::string& id) : twin(t), fogId(id) {}

void fogCallBack::message_arrived(mqtt::const_message_ptr msg) {
    try {
        auto j=nlohmann::json::parse(msg->to_string());
        float weight=j["weight"];
        long timeSentRaw=j["timeSentRaw"];
        j["timeReceivedRaw"]=rep.getEpochMs();
        twin.updateWeight(weight);
        j["fogNode"]=fogId;
        std::cout<<"Fog "<<fogId<<" delay: "<< (rep.getEpochMs() - timeSentRaw)<< " ms\n";
        if (forward) {
            forward(j.dump());
        }
    }catch (const std::exception& e) {
        std::cerr<<"fog json error: "<<e.what()<<std::endl;
    }
}
void fogCallBack::setForwarder(std::function<void(const std::string&)> f) {
    forward = f;
}
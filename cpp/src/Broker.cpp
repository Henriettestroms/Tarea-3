#include "Broker.h"
#include "Topic.h"
#include "Subscriber.h"

Broker::Broker() {}

Topic* Broker::createTopic(const std::string& topicName){
    Topic* topic = findTopic(topicName);
    if(!topic){
        topic = new Topic(topicName);
        topics.push_back(topic);
    }
    return topic;
}

bool Broker::subscribe(Subscriber* sub){
    if(!sub)
        return false;
    Topic* topic = createTopic(sub->getTopicName());
    if(topic){
        topic->subscribe(sub);
        return true;
    }
    return false;
}

Topic* Broker::findTopic(const std::string& topicName){
    for(auto* t : topics){
        if(t->hasThisName(topicName))
            return t;
    }
    return nullptr;
}

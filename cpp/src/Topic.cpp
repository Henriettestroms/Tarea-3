#include "Topic.h"
#include "Subscriber.h"

Topic::Topic(const std::string& name) : topicName(name) {}

void Topic::subscribe(Subscriber* sub){
    subscribers.push_back(sub);
}

void Topic::notify(const std::string& message){
    for(auto* s : subscribers){
        if(s) s->update(message);
    }
}

bool Topic::hasThisName(const std::string& name) const{
    return topicName == name;
}

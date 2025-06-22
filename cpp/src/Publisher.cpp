#include "Publisher.h"
#include "Broker.h"
#include "Topic.h"

Publisher::Publisher(const std::string& name, Broker& broker, const std::string& topicName)
    : Component(name, topicName)
{
    topic = broker.createTopic(topicName);
}

void Publisher::publishNewEvent(const std::string& message){
    if(topic) topic->notify(message);
}

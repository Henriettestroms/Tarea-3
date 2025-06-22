#ifndef PUBLISHER_H
#define PUBLISHER_H
#include "Component.h"
class Broker;
class Topic;
class Publisher : public Component {
protected:
    Publisher() = default;
public:
    Publisher(const std::string& name, Broker& broker, const std::string& topicName);
protected:
    void publishNewEvent(const std::string& message);
    Topic* topic{nullptr};
};
#endif

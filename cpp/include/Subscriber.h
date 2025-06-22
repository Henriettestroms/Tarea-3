#ifndef SUBSCRIBER_H
#define SUBSCRIBER_H
#include "Component.h"
class Subscriber : public Component {
protected:
    Subscriber() = default;
public:
    Subscriber(const std::string& name, const std::string& topicName);
    virtual void update(const std::string& message) = 0;
};
#endif

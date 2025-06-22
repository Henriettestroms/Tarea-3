#include "Component.h"

Component::Component(const std::string& name, const std::string& topic)
    : name(name), topicName(topic) {}

const std::string& Component::getName() const { return name; }
const std::string& Component::getTopicName() const { return topicName; }

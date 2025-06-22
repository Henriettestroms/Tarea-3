#ifndef COMPONENT_H
#define COMPONENT_H
#include <string>
class Component {
protected:
    Component() = default;
    Component(const std::string& name, const std::string& topic);
public:
    const std::string& getName() const;
    const std::string& getTopicName() const;
protected:
    std::string name;
    std::string topicName;
};
#endif

#ifndef TOPIC_H
#define TOPIC_H
#include <vector>
#include <string>
class Subscriber;
class Topic {
public:
    explicit Topic(const std::string& name);
    void subscribe(Subscriber* sub);
    void notify(const std::string& message);
    bool hasThisName(const std::string& name) const;
private:
    std::string topicName;
    std::vector<Subscriber*> subscribers;
};
#endif

#ifndef BROKER_H
#define BROKER_H
#include <vector>
#include <string>
class Topic;
class Subscriber;
class Broker {
public:
    Broker();
    Topic* createTopic(const std::string& topicName);
    bool subscribe(Subscriber* sub);
private:
    Topic* findTopic(const std::string& topicName);
    std::vector<Topic*> topics;
};
#endif

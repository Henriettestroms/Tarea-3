#ifndef VIDEOPUBLISHER_H
#define VIDEOPUBLISHER_H
#include "Publisher.h"
#include <QWidget>
class QLineEdit;
class VideoPublisher : public Publisher {
public:
    VideoPublisher(const std::string& name, Broker& broker, const std::string& topicName);
    QWidget* getView();
private:
    QWidget* view{nullptr};
    QLineEdit* message{nullptr};
};
#endif

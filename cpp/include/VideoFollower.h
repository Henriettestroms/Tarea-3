#ifndef VIDEOFOLLOWER_H
#define VIDEOFOLLOWER_H
#include "Subscriber.h"
#include <QWidget>
#include <QString>
class QPushButton;
class QSlider;
class VideoFollower : public Subscriber {
public:
    VideoFollower(const std::string& name, const std::string& topicName);
    void update(const std::string& message) override;
    QWidget* getView();

private:
    QWidget* view{nullptr};
    QPushButton* video{nullptr};
    QSlider* volumeSlider{nullptr};
    QString lastUrl;
};
#endif

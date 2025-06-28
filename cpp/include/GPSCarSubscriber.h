#ifndef GPSCARSUBSCRIBER_H
#define GPSCARSUBSCRIBER_H

#include "Subscriber.h"
#include <QWidget>

class QLabel;
class GPSCarSubscriber : public Subscriber {
public:
    GPSCarSubscriber(const std::string& name, const std::string& topicName);
    void update(const std::string& message) override;
    QWidget* getView();

private:
    QWidget* view{nullptr};
    QLabel* timeLabel{nullptr};
    QLabel* xLabel{nullptr};
    QLabel* yLabel{nullptr};
};

#endif
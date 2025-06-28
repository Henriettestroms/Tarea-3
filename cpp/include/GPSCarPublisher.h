#ifndef GPSCARPUBLISHER_H
#define GPSCARPUBLISHER_H

#include "Publisher.h"
#include <QObject>
#include <QWidget>
#include <QVector>
#include <QPointF>

class QPushButton;
class QTimer;

class GPSCarPublisher : public QObject, public Publisher {
    Q_OBJECT
public:
    GPSCarPublisher(const std::string& name, Broker& broker, const std::string& topicName);
    QWidget* getView();

private slots:
    void start();

private:
    QWidget* view{nullptr};
    QPushButton* startButton{nullptr};
    QTimer* timer{nullptr};
    QVector<QPointF> points;
    int index{0};
};

#endif
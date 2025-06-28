#include "GPSCarSubscriber.h"
#include <QVBoxLayout>
#include <QLabel>
#include <sstream>

GPSCarSubscriber::GPSCarSubscriber(const std::string& name, const std::string& topicName)
    : Subscriber(name, topicName)
{
    view = new QWidget;
    auto* layout = new QVBoxLayout(view);
    layout->addWidget(new QLabel(QString::fromStdString(name)));
    timeLabel = new QLabel("t=0");
    xLabel = new QLabel("x=0");
    yLabel = new QLabel("y=0");
    layout->addWidget(timeLabel);
    layout->addWidget(xLabel);
    layout->addWidget(yLabel);
}

void GPSCarSubscriber::update(const std::string& message)
{
    std::istringstream iss(message);
    double t,x,y;
    if(!(iss >> t >> x >> y))
        return;
    timeLabel->setText(QString("t=%1").arg(t));
    xLabel->setText(QString("x=%1").arg(x));
    yLabel->setText(QString("y=%1").arg(y));
}

QWidget* GPSCarSubscriber::getView()
{
    return view;
}
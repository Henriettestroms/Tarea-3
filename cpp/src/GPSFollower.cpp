#include "GPSFollower.h"
#include <QVBoxLayout>
#include <QLabel>
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QGraphicsEllipseItem>
#include <sstream>

GPSFollower::GPSFollower(const std::string& name, const std::string& topicName)
    : Subscriber(name, topicName)
{
    view = new QWidget;
    auto* layout = new QVBoxLayout(view);
    info = new QLabel("Waiting...");
    layout->addWidget(info);

    canvas = new QGraphicsView;
    scene = new QGraphicsScene(0,0,400,400,canvas);
    canvas->setScene(scene);
    circle = scene->addEllipse(0,0,10,10, QPen(Qt::blue), QBrush(Qt::blue));
    layout->addWidget(canvas);
}

void GPSFollower::update(const std::string& message){
    std::istringstream iss(message);
    double t,x,y;
    if(!(iss >> t >> x >> y))
        return;
    info->setText(QString("t=%1 x=%2 y=%3").arg(t).arg(x).arg(y));
    circle->setRect(x, y, 10, 10);
}

QWidget* GPSFollower::getView(){
    return view;
}
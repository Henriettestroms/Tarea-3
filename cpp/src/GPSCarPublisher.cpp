#include "GPSCarPublisher.h"
#include "Broker.h"
#include <QVBoxLayout>
#include <QLabel>
#include <QPushButton>
#include <QFileDialog>
#include <QFile>
#include <QTextStream>
#include <QTimer>

GPSCarPublisher::GPSCarPublisher(const std::string& name, Broker& broker, const std::string& topicName)
    : Publisher(name, broker, topicName)
{
    view = new QWidget;
    auto* layout = new QVBoxLayout(view);
    layout->addWidget(new QLabel(QString::fromStdString(name)));
    startButton = new QPushButton("Start");
    layout->addWidget(startButton);

    QString fileName = QFileDialog::getOpenFileName(view, "Open GPS file", "", "Text Files (*.txt)");
    if(!fileName.isEmpty()){
        QFile file(fileName);
        if(file.open(QIODevice::ReadOnly | QIODevice::Text)){
            QTextStream in(&file);
            while(!in.atEnd()){
                double t,x,y;
                in >> t >> x >> y;
                points.append(QPointF(x, y));
            }
        }
    }

    timer = new QTimer(this);
    QObject::connect(startButton, &QPushButton::clicked, this, &GPSCarPublisher::start);
    QObject::connect(timer, &QTimer::timeout, this, &GPSCarPublisher::publishNext);
}

void GPSCarPublisher::start(){
    timer->stop();
    index = 0;
    publishNext();
}

void GPSCarPublisher::publishNext(){
    if(index < points.size()){
        QPointF p = points[index++];
        QString msg = QString("%1 %2 %3").arg(index).arg(p.x()).arg(p.y());
        publishNewEvent(msg.toStdString());
        if(!timer->isActive())
            timer->start(1000);
    } else {
        timer->stop();
        index = 0;
    }
}

QWidget* GPSCarPublisher::getView(){
    return view;
}
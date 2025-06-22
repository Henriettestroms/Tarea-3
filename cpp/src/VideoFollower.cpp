#include "VideoFollower.h"
#include <QHBoxLayout>
#include <QPushButton>

VideoFollower::VideoFollower(const std::string& name, const std::string& topicName)
    : Subscriber(name, topicName)
{
    view = new QWidget;
    auto* layout = new QHBoxLayout(view);
    video = new QPushButton(QString::fromStdString(name));
    layout->addWidget(video);
}

void VideoFollower::update(const std::string& message){
    video->setText(QString::fromStdString(message));
}

QWidget* VideoFollower::getView(){
    return view;
}

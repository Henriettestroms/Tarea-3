#include "VideoFollower.h"
#include <QHBoxLayout>
#include <QPushButton>
#include <QMediaPlayer>
#include <QVideoWidget>
#include <QUrl>

VideoFollower::VideoFollower(const std::string& name, const std::string& topicName)
    : Subscriber(name, topicName)
{
    view = new QWidget;
    auto* layout = new QHBoxLayout(view);
    video = new QPushButton(QString::fromStdString(name));
    layout->addWidget(video);
    
    QObject::connect(video, &QPushButton::clicked, [this]() {
        if(lastUrl.isEmpty())
            return;

        auto* player = new QMediaPlayer;
        auto* widget = new QVideoWidget;
        player->setVideoOutput(widget);
        player->setSource(QUrl(lastUrl));
        widget->setAttribute(Qt::WA_DeleteOnClose);
        widget->resize(640, 480);
        widget->show();
        player->play();
    });
}

void VideoFollower::update(const std::string& message){
    lastUrl = QString::fromStdString(message);
    video->setText(lastUrl);
}

QWidget* VideoFollower::getView(){
    return view;
}

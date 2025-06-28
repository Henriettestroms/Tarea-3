#include "VideoFollower.h"
#include <QVBoxLayout>
#include <QPushButton>
#include <QMediaPlayer>
#include <QAudioOutput>
#include <QVideoWidget>
#include <QUrl>
#include <QSlider>

VideoFollower::VideoFollower(const std::string& name, const std::string& topicName)
    : Subscriber(name, topicName)
{
    view = new QWidget;
    auto* layout = new QVBoxLayout(view);
    video = new QPushButton(QString::fromStdString(name));
    layout->addWidget(video);

    volumeSlider = new QSlider(Qt::Horizontal);
    volumeSlider->setRange(0, 100);
    volumeSlider->setValue(50);
    layout->addWidget(volumeSlider);

    QObject::connect(video, &QPushButton::clicked, [this]() {
        if(lastUrl.isEmpty())
            return;

        auto* player = new QMediaPlayer;
        auto* audio = new QAudioOutput(player);
        auto* widget = new QVideoWidget;
        player->setVideoOutput(widget);
        player->setAudioOutput(audio);
        player->setSource(QUrl(lastUrl));
        audio->setVolume(volumeSlider->value() / 100.0);
        QObject::connect(volumeSlider, &QSlider::valueChanged, [audio](int value){
            audio->setVolume(value / 100.0);
        });
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

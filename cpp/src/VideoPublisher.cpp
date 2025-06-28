#include "VideoPublisher.h"
#include "Broker.h"
#include <QHBoxLayout>
#include <QLineEdit>
#include <QLabel>

VideoPublisher::VideoPublisher(const std::string& name, Broker& broker, const std::string& topicName)
    : Publisher(name, broker, topicName)
{
    view = new QWidget;
    auto* layout = new QHBoxLayout(view);
    layout->addWidget(new QLabel(QString::fromStdString(name)));
    message = new QLineEdit;
    layout->addWidget(message);
    QObject::connect(message, &QLineEdit::returnPressed, [this]() {
        QString text = message->text();
        if(!text.isEmpty()){
            publishNewEvent(text.toStdString());
            message->clear();
        }
    });
}

QWidget* VideoPublisher::getView(){
    return view;
}

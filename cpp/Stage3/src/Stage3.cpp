#include <QApplication>
#include <QMenuBar>
#include <QMenu>
#include <QAction>
#include <QInputDialog>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QWidget>
#include "Broker.h"
#include "VideoPublisher.h"
#include "VideoFollower.h"
#include "GPSCarPublisher.h"
#include "GPSCarSubscriber.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    Broker broker;
    QWidget window;
    QMenuBar* menuBar = new QMenuBar(&window);
    QMenu* menuPublisher = menuBar->addMenu("Publisher");
    QMenu* menuSubscriber = menuBar->addMenu("Subscriber");
    QAction* menuItemVideoPub = menuPublisher->addAction("Video");
    QAction* menuItemGPSPub = menuPublisher->addAction("GPS");
    QAction* menuItemVideoSubs = menuSubscriber->addAction("Video");
    QAction* menuItemGPSSubs = menuSubscriber->addAction("GPS");

    QHBoxLayout* mainLayout = new QHBoxLayout;
    QVBoxLayout* left = new QVBoxLayout;
    QVBoxLayout* right = new QVBoxLayout;
    mainLayout->addLayout(left);
    mainLayout->addLayout(right);

    QWidget* central = new QWidget;
    central->setLayout(mainLayout);
    QVBoxLayout* containerLayout = new QVBoxLayout(&window);
    containerLayout->addWidget(menuBar);
    containerLayout->addWidget(central);

    QObject::connect(menuItemVideoPub, &QAction::triggered, [&](){
        QString name = QInputDialog::getText(&window, "Video Publisher Name", "Video Publisher Name:");
        QString topic = QInputDialog::getText(&window, "Video Publisher Topic", "Video Publisher Topic:");
        auto* pub = new VideoPublisher(name.toStdString(), broker, topic.toStdString());
        left->addWidget(pub->getView());
    });

    QObject::connect(menuItemVideoSubs, &QAction::triggered, [&](){
        QString name = QInputDialog::getText(&window, "Video Subscriber Name", "Video Subscriber Name:");
        QString topic = QInputDialog::getText(&window, "Video Subscriber Topic", "Video Subscriber Topic:");
        auto* sub = new VideoFollower(name.toStdString(), topic.toStdString());
        if(broker.subscribe(sub))
            right->addWidget(sub->getView());
    });

    QObject::connect(menuItemGPSPub, &QAction::triggered, [&](){
        QString name = QInputDialog::getText(&window, "GPS Publisher Name", "GPS Publisher Name:");
        QString topic = QInputDialog::getText(&window, "GPS Publisher Topic", "GPS Publisher Topic:");
        auto* pub = new GPSCarPublisher(name.toStdString(), broker, topic.toStdString());
        left->addWidget(pub->getView());
    });

    QObject::connect(menuItemGPSSubs, &QAction::triggered, [&](){
        QString name = QInputDialog::getText(&window, "GPS Subscriber Name", "GPS Subscriber Name:");
        QString topic = QInputDialog::getText(&window, "GPS Subscriber Topic", "GPS Subscriber Topic:");
        auto* sub = new GPSCarSubscriber(name.toStdString(), topic.toStdString());
        if(broker.subscribe(sub))
            right->addWidget(sub->getView());
    });

    window.show();
    return app.exec();
}
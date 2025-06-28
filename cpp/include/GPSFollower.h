#ifndef GPSFOLLOWER_H
#define GPSFOLLOWER_H
#include "Subscriber.h"
#include <QWidget>
#include <QPointF>
class QLabel;
class QGraphicsView;
class QGraphicsEllipseItem;
class QGraphicsScene;

class GPSFollower : public Subscriber {
public:
    GPSFollower(const std::string& name, const std::string& topicName);
    void update(const std::string& message) override;
    QWidget* getView();

private:
    QWidget* view{nullptr};
    QLabel* info{nullptr};
    QGraphicsView* canvas{nullptr};
    QGraphicsScene* scene{nullptr};
    QGraphicsEllipseItem* circle{nullptr};
};
#endif
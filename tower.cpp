#include "tower.h"
#include <QVector>

Tower::Tower(QGraphicsPixmapItem* parent )
    : QGraphicsPixmapItem(parent)
{
    //set the graphics
    setPixmap(QPixmap(":/images/images/tower.png").scaled(QSize(100, 100)));

    //Get the point vector
    QVector<QPointF> points;
    points << QPointF(1, 0) << QPointF(2, 0) << QPointF(3, 1) << QPointF(3, 2)
           << QPointF(2, 3) << QPointF(1, 3) << QPointF(0, 2) << QPointF(0, 1);

    //scale the point vector
    const int SCALE_FACTOR = 65;
    std::transform(points.begin(), points.end(), points.begin(), [SCALE_FACTOR](QPointF d) -> QPointF { return d * SCALE_FACTOR; });

    //create polygon from point vector
    QPolygonF polygon(points);

    //create polygon display area
    m_attackArea = new QGraphicsPolygonItem(points, this);

    //map polygon to tower
    QPointF polyCenter(1.5, 1.5);
    polyCenter *= SCALE_FACTOR;

    QPointF towerCenter(x() + 50, y() + 50);

    QLineF ln(polyCenter, towerCenter);
    m_attackArea->setPos(x() + ln.dx(), y() + ln.dy());
}

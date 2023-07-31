#include "tower.h"
#include <QVector>
#include <QTimer>
#include "bullet.h"
#include "game.h"

extern Game* game;

Tower::Tower(QGraphicsItem* parent )
    :QObject()
    ,QGraphicsPixmapItem(parent)
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

    //Timer to attack target
    QTimer* timer = new QTimer();
    connect(timer, SIGNAL(timeout()), this, SLOT(attackTarget()));
    timer->start(1000);

}

void Tower::attackTarget()
{
    //Create bullet to attack target
    Bullet* bullet = new Bullet();
    QPointF towerCenter(x() + 50, y() + 50);
    bullet->setPos(towerCenter);

    //Finding angle of bullet
    QLineF ln(towerCenter, m_TargetCenter);
    int angle = -1  * ln.angle();
    bullet->setRotation(angle);
    game->m_Scene->addItem(bullet);

}

#include "bullet.h"
#include <QTimer>
#include <QtMath>

Bullet::Bullet(QGraphicsPixmapItem *parent)
    :QGraphicsPixmapItem{parent}
    ,QObject()
{
    setPixmap(QPixmap(":/images/images/arrow.png").scaled(QSize(40, 20)));
    QTimer* timer = new QTimer;
    connect(timer, SIGNAL(timeout()), this, SLOT(move()));
    timer->start(50);
}

void Bullet::move()
{
    int STEP_SIZE = 30;
    double theta = rotation();

    double dy = qSin(qDegreesToRadians(theta)) * STEP_SIZE;
    double dx = qCos(qDegreesToRadians(theta)) * STEP_SIZE;

    setPos(x() + dx, y() + dy);
}

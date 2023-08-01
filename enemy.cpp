#include "enemy.h"
#include <QTimer>

Enemy::Enemy(QGraphicsItem *parent)
    :QObject()
    ,QGraphicsPixmapItem{parent}
{
    //set enemy image
    setPixmap(QPixmap(":/images/images/enemy.png").scaled(QSize(40, 40)));

    //set destination points
    m_DestList << QPointF(200,200) << QPointF(400, 200);
    m_PointIndex = 0;
    rotateToDestination(m_DestList[0]);

    //set timer
    QTimer* timer = new QTimer;
    connect(timer, SIGNAL(timeout()), this, SLOT(moveDestination()));
    timer->start(150);
}

void Enemy::rotateToDestination(QPointF point)
{
    QLineF ln(pos(), point);
    int angle = -1 * ln.angle();
    setRotation(angle);
}

void Enemy::moveDestination()
{
    if(m_PointIndex >= m_DestList.size()) {
        return;
    }
    int STEP_SIZE = 10;
    double theta = rotation();

    // change movement if distance is less
    QLineF ln(pos(), m_DestList[m_PointIndex]);
    if(ln.length() < 5) {
        m_PointIndex++;
        if(m_PointIndex >= m_DestList.size()) {
            return;
        }

        rotateToDestination(m_DestList[m_PointIndex]);
    }


    double dy = qSin(qDegreesToRadians(theta)) * STEP_SIZE;
    double dx = qCos(qDegreesToRadians(theta)) * STEP_SIZE;

    setPos(QPointF(x() + dx, y() + dy));

}

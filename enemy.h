#ifndef ENEMY_H
#define ENEMY_H

#include <QObject>
#include <QGraphicsPixmapItem>

class Enemy : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    explicit Enemy(QList<QPointF>pointsToFollow, QGraphicsItem *parent = nullptr);
    void rotateToDestination(QPointF point);

public slots:
    void moveDestination();

private:
    QList<QPointF>m_DestList;
    int m_PointIndex;
    int m_Health;

};

#endif // ENEMY_H

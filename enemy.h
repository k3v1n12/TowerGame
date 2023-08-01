#ifndef ENEMY_H
#define ENEMY_H

#include <QObject>
#include <QGraphicsPixmapItem>

class Enemy : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    explicit Enemy(QGraphicsItem *parent = nullptr);
    void rotateToDestination(QPointF point);

public slots:
    void moveDestination();

private:
    QList<QPointF>m_DestList;
    QPointF m_EnemyPos;
    int m_PointIndex;

};

#endif // ENEMY_H

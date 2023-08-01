#ifndef TOWER_H
#define TOWER_H

#include <QGraphicsPixmapItem>
#include <QObject>

class Tower : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    Tower(QGraphicsItem* parent = nullptr);
    double distanceToTower(QPointF point);
    void attackTarget();

public slots:
    void acquireTarget();

private:
    QGraphicsPolygonItem* m_attackArea;
    QPointF m_TargetCenter;
    bool m_TargetAcquired;
};

#endif // TOWER_H

#ifndef TOWER_H
#define TOWER_H

#include <QGraphicsPixmapItem>
#include <QObject>
#include "Util.h"


class Tower : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    Tower(TowerType type, QString imagePath, QGraphicsItem* parent = nullptr);
    double distanceToTower(QPointF point);
    void attackTarget();
    void createBullet(TowerType type, QPointF pos, int angle);

public slots:
    void acquireTarget();

private:
    QGraphicsPolygonItem* m_attackArea;
    QPointF m_TargetCenter;
    bool m_TargetAcquired;
    TowerType m_Type;
};

#endif // TOWER_H

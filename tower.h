#ifndef TOWER_H
#define TOWER_H

#include <QGraphicsPixmapItem>
#include <QObject>

class Tower : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    Tower(QGraphicsItem* parent = nullptr);

public slots:
    void attackTarget();

private:
    QGraphicsPolygonItem* m_attackArea;
    QPointF m_TargetCenter;
};

#endif // TOWER_H

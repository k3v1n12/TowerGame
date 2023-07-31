#ifndef TOWER_H
#define TOWER_H

#include <QGraphicsPixmapItem>

class Tower : public QGraphicsPixmapItem
{
public:
    Tower(QGraphicsPixmapItem* parent = nullptr);

private:
    QGraphicsPolygonItem* m_attackArea;
};

#endif // TOWER_H

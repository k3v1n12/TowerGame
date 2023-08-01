#ifndef BUILDTOWER_H
#define BUILDTOWER_H

#include <QGraphicsPixmapItem>
#include <QMouseEvent>

class BuildTower : public QGraphicsPixmapItem
{
public:
    BuildTower(QGraphicsItem* parent = nullptr);
    void mousePressEvent(QGraphicsSceneMouseEvent* event);

    bool m_IconClicked;
};

#endif // BUILDTOWER_H

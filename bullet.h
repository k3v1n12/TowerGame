#ifndef BULLET_H
#define BULLET_H

#include <QObject>
#include <QGraphicsPixmapItem>
#include "Util.h"

class Bullet : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    Bullet(TowerType type, QGraphicsItem *parent = nullptr);

public slots:
    void move();

signals:

};

#endif // BULLET_H

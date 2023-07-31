#ifndef GAME_H
#define GAME_H

#include<QGraphicsView>
#include<QMouseEvent>
#include "tower.h"

class Game: public QGraphicsView
{
public:
    Game(QGraphicsView* parent = nullptr);

    void mousePressEvent(QMouseEvent* event);

    QGraphicsScene* m_Scene;
    Tower* m_Tower;
};

#endif // GAME_H

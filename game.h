#ifndef GAME_H
#define GAME_H

#include<QGraphicsView>
#include<QMouseEvent>
#include "tower.h"
#include "enemy.h"
#include "buildtower.h"

class Game: public QGraphicsView
{
public:
    Game(QGraphicsView* parent = nullptr);
    void buildTowerStart();

    void mousePressEvent(QMouseEvent* event);
    void mouseMoveEvent(QMouseEvent* event);

    void setCursor(QString path);
    void deleteCursor();

    QGraphicsScene* m_Scene;
    Tower* m_Tower;
    Enemy* m_Enemy;
    BuildTower* m_BuildTower;

private:
    Tower* m_Build;
    QGraphicsPixmapItem* m_Cursor;
};

#endif // GAME_H

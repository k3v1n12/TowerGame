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
    void createTowerOnClick(QPointF pos);

    QGraphicsScene* m_Scene;
    Enemy* m_Enemy;
    BuildTower* m_BrownBuildTower;
    BuildTower* m_GreenBuildTower;
    BuildTower* m_BlueBuildTower;

private:
    Tower* m_Tower;
    QGraphicsPixmapItem* m_Cursor;
};

#endif // GAME_H

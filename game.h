#ifndef GAME_H
#define GAME_H

#include<QGraphicsView>
#include<QMouseEvent>
#include "tower.h"
#include "enemy.h"
#include "buildtower.h"
#include <QObject>
#include <QTimer>

class Game: public QGraphicsView
{
    Q_OBJECT
public:
    Game(QGraphicsView* parent = nullptr);
    void buildTowerStart();

    void mousePressEvent(QMouseEvent* event);
    void mouseMoveEvent(QMouseEvent* event);

    void setCursor(QString path);
    void deleteCursor();
    void createTowerOnClick(QPointF pos);
    void createEnemy(int numberofEnemies);
    void createRoad();

    QGraphicsScene* m_Scene;
    BuildTower* m_BrownBuildTower;
    BuildTower* m_GreenBuildTower;
    BuildTower* m_BlueBuildTower;

public slots:
    void spawnEnemy();

private:
    Tower* m_Tower;
    QGraphicsPixmapItem* m_Cursor;
    QTimer* m_Timer;
    QList<QPointF> pointsToFollow;
    int m_SpawnedEnemy;
    int m_MaxEnemy;
};

#endif // GAME_H

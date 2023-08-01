#include "buildtower.h"
#include "game.h"
#include <QDebug>

extern Game* game;

BuildTower::BuildTower(QGraphicsItem* parent)
    :QGraphicsPixmapItem(parent)
    ,m_IconClicked(false)
{
    setPixmap(QPixmap(":images/images/towerIcon.png").scaled(QSize(50, 50)));
}

void BuildTower::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    qDebug() <<"mousepress";
    if(!m_IconClicked)
    {
        m_IconClicked = true;
        game->buildTowerStart();
    }
}

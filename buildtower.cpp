#include "buildtower.h"
#include "game.h"

extern Game* game;

BuildTower::BuildTower(QString iconPath, QGraphicsItem* parent)
    :QGraphicsPixmapItem(parent)
    ,m_IconClicked(false)
{
    setPixmap(QPixmap(iconPath).scaled(QSize(50, 50)));
}

void BuildTower::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    if(!m_IconClicked)
    {
        m_IconClicked = true;
        game->buildTowerStart();
    }
}

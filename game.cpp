#include "game.h"
#include "bullet.h"

Game::Game(QGraphicsView* parent)
    : QGraphicsView(parent)
{
    //setAcceptedMouseButtons(Qt::AllButtons);
    setMouseTracking(true);
    //set the scene
    m_Scene = new QGraphicsScene(this);
    m_Scene->setSceneRect(0, 0, 800, 600);

    //visualise the scene
    setScene(m_Scene);
    setFixedSize(800, 600);

    //Add Tower
    m_Tower = new Tower();
    m_Tower->setPos(300, 300);
    m_Scene->addItem(m_Tower);

    //disable scrollbar
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);


}

void Game::mousePressEvent(QMouseEvent *event)
{
    //create bullet
    Bullet* bullet = new Bullet();
    bullet->setRotation(40);
    bullet->setPos(event->pos());
    m_Scene->addItem(bullet);
}

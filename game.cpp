#include "game.h"

Game::Game(QGraphicsView* parent)
    : QGraphicsView(parent)
{
    //set the scene
    m_Scene = new QGraphicsScene(this);

    //visualise the scene
    setScene(m_Scene);
    setFixedSize(800, 600);

    //Add Tower
    m_Tower = new Tower();
    m_Scene->addItem(m_Tower);


}

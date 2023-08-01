#include "game.h"

Game::Game(QGraphicsView* parent)
    : QGraphicsView(parent)
    , m_Build(nullptr)
    , m_Cursor(nullptr)
{
    //mouse tracking
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

    // Add Enemy
    m_Enemy = new Enemy();
    m_Scene->addItem(m_Enemy);

    //Add Tower Icon
    m_BuildTower = new BuildTower();
    m_Scene->addItem(m_BuildTower);

    //disable scrollbar
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);


}

void Game::buildTowerStart()
{
    setCursor(QString(":images/images/tower.png"));
}

void Game::mousePressEvent(QMouseEvent *event)
{
    if(m_BuildTower->m_IconClicked) {
        m_Build = new Tower();
        m_Scene->addItem(m_Build);
        m_Build->setPos(event->pos());
        m_Build = nullptr;
        deleteCursor();
        m_Cursor = nullptr;
        m_BuildTower->m_IconClicked = false;
    }
    QGraphicsView::mousePressEvent(event);
}

void Game::mouseMoveEvent(QMouseEvent *event)
{
    if(m_Cursor) m_Cursor->setPos(event->pos());
}

void Game::setCursor(QString path)
{
    deleteCursor();
    m_Cursor = new QGraphicsPixmapItem();
    m_Cursor->setPixmap(QPixmap(path).scaled(20,20));
    m_Scene->addItem(m_Cursor);
}

void Game::deleteCursor()
{
    if(m_Cursor) {
        m_Scene->removeItem(m_Cursor);
        delete m_Cursor;
    }
}

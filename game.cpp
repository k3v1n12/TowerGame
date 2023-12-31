#include "game.h"

Game::Game(QGraphicsView* parent)
    : QGraphicsView(parent)
    , m_Tower(nullptr)
    , m_Cursor(nullptr)
    ,m_SpawnedEnemy(0)
    ,m_MaxEnemy(0)
{
    //mouse tracking
    setMouseTracking(true);
    //set the scene
    m_Scene = new QGraphicsScene(this);
    m_Scene->setSceneRect(0, 0, 800, 600);

    //visualise the scene
    setScene(m_Scene);
    setFixedSize(800, 600);

    //Create road
    pointsToFollow << QPointF(800, 0) << QPointF(450, 450) << QPointF(0, 600);
    createRoad();

    // Add Enemy
    m_Timer = new QTimer();
    createEnemy(5);

    //Add Tower Icons
    m_BrownBuildTower = new BuildTower(":images/images/brownTowerIcon");

    m_GreenBuildTower = new BuildTower(":images/images/GreenTowerIcon");
    m_GreenBuildTower->setPos(x() + 50, y());

    m_BlueBuildTower = new BuildTower(":images/images/BlueTowerIcon");
    m_BlueBuildTower->setPos(x() + 100, y());

    m_Scene->addItem(m_BrownBuildTower);
    m_Scene->addItem(m_GreenBuildTower);
    m_Scene->addItem(m_BlueBuildTower);

    //disable scrollbar
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);


}

void Game::buildTowerStart()
{
    if(m_BrownBuildTower->m_IconClicked)
    {
        setCursor(QString(":images/images/BrownTower.png"));
    }
    else if(m_GreenBuildTower->m_IconClicked)
    {
        setCursor(QString(":images/images/GreenTower.png"));
    }
    else if(m_BlueBuildTower->m_IconClicked)
    {
        setCursor(QString(":images/images/BlueTower.png"));
    }
}

void Game::mousePressEvent(QMouseEvent *event)
{
    if(m_BrownBuildTower->m_IconClicked) {
        m_Tower = new Tower(brown, ":images/images/BrownTower.png");
        createTowerOnClick(event->pos());
        m_BrownBuildTower->m_IconClicked = false;
    }
    else if(m_GreenBuildTower->m_IconClicked) {
        m_Tower = new Tower(green, ":images/images/GreenTower.png");
        createTowerOnClick(event->pos());
        m_GreenBuildTower->m_IconClicked = false;
    }
    else if(m_BlueBuildTower->m_IconClicked) {
        m_Tower = new Tower(blue, ":images/images/BlueTower.png");
        createTowerOnClick(event->pos());
        m_BlueBuildTower->m_IconClicked = false;
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

void Game::createTowerOnClick(QPointF pos)
{
    m_Scene->addItem(m_Tower);
    m_Tower->setPos(pos);
    m_Tower = nullptr;
    deleteCursor();
    m_Cursor = nullptr;
}

void Game::createEnemy(int numberofEnemies)
{
    m_SpawnedEnemy = 0;
    m_MaxEnemy = numberofEnemies;
    connect(m_Timer, SIGNAL(timeout()), this, SLOT(spawnEnemy()));
    m_Timer->start(1000);
}

void Game::createRoad()
{
    int n = pointsToFollow.size() - 1;
    for(auto i = 0; i < n; i++) {
        QLineF ln(pointsToFollow[i], pointsToFollow[i + 1]);
        QPen pen;
        pen.setWidth(15);
        pen.setColor(Qt::darkGray);
        QGraphicsLineItem* line = new QGraphicsLineItem();
        line->setLine(ln);
        line->setPen(pen);
        m_Scene->addItem(line);
    }
}

void Game::spawnEnemy()
{
    Enemy* enemy = new Enemy(pointsToFollow);
    enemy->setPos(pointsToFollow[0]);
    m_Scene->addItem(enemy);
    m_SpawnedEnemy++;

    if(m_SpawnedEnemy >= m_MaxEnemy)
    {
        disconnect(m_Timer, SIGNAL(timeout()), this, SLOT(spawnEnemy()));
    }
}

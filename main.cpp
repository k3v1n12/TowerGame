#include <QApplication>
#include "game.h"

Game* game;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    //show view
    game = new Game();
    game->show();

    return a.exec();
}

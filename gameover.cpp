#include "gameover.h"

#include <QFont>

GameOver::GameOver(QGraphicsItem *parent) : QGraphicsTextItem(parent)
{
    setPlainText(QString(""));
    setDefaultTextColor(Qt::blue);
}

void GameOver::victoire()
{
    setPlainText(QString("Vous avez gagné !!"));
    setDefaultTextColor(Qt::green);
    setFont(QFont("Times",20));
}

void GameOver::defaite()
{
    setPlainText(QString("Vous avez perdu"));
    setDefaultTextColor(Qt::red);
    setFont(QFont("Times",20));
}

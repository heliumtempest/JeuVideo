#include "joueur.h"
#include <QDebug>

Joueur::Joueur(QObject *parent) : QObject(parent)
{
    //Dimension fenêtre 800-600
    //this->setRect(0,0,50,50); //Version RectItem
    this->setPixmap(QPixmap(":/sprites/blackjack.png"));
    this->setFlag(QGraphicsItem::ItemIsFocusable);
    this->setFocus();
    this->setPos(800/2 + 50/2 , 600 - 50);

    pewpewPlayer = new QMediaPlayer();
    pewpewPlayer->setMedia(QUrl("qrc:/sfx/laser.wav"));
}

void Joueur::keyPressEvent(QKeyEvent * event)
{
    if(event->key() == Qt::Key_Left){
        if(pos().x() > 0){
            setPos(x() - 10 , y());
        }

    }
    else if(event->key() == Qt::Key_Right){
        if(pos().x() < 800 - 50) {
            setPos(x() + 10 , y());
        }
    }
    if(event->key() == Qt::Key_Space){
        //Pew pew pew
        Laser * tir = new  Laser();
        connect(tir, SIGNAL(victoire()), this, SLOT(victoire()));
        tir->setPos(x() + 50/2, y()); //50 represente 'width', /2 pour centrer
        scene()->addItem(tir);

        //Faire "pew pew"
        if(pewpewPlayer->state() == QMediaPlayer::PlayingState){
            pewpewPlayer->setPosition(0);
        }
        pewpewPlayer->play();
    }
}

void Joueur::victoire()
{
    qDebug() << "Emission du signal ennemisDetruits de joueur";
    emit ennemisDetruits();
}


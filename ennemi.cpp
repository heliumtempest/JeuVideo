#include "ennemi.h"
#include <QDebug>

int Ennemi::compteurEnnemis = 0;

Ennemi::Ennemi(QObject *parent) : QObject(parent)
{
    //Version RectItem
    //this->setRect(0,0,50,50);

    setPixmap(QPixmap(":/sprites/pact_elite.png"));

    QTimer * timer = new QTimer();
    connect(timer, SIGNAL(timeout()), this, SLOT(deplacement()));
    timer->start(1500); //1.5s

    compteurEnnemis++;
}

void Ennemi::deplacement()
{
    if(compteurDeplacement % 6 == 0){
        this->setPos(x(), y() + 50); //L'axe des ordonnées est orienté vers le bas (d'où le +)
        deplacementHorizontalTaille = - deplacementHorizontalTaille; //Changement de direction horizontale
    }
    else {
        this->setPos(x() + deplacementHorizontalTaille, y());
    }
    compteurDeplacement = compteurDeplacement + 1;

    if(this->y() +50 > 550){ //+50 parceque le bas du de la hitbox //550 car au même niveau que le joueur
        qDebug() << "Vous avez perdu";
        emit defaite();

        delete this;
        return;
    }

}

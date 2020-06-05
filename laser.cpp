#include "laser.h"
#include <QtDebug>

Laser::Laser()
{
    //Définir la taille
    //this->setRect(0,0,3,10); //S'il s'agissait d'un QGraphicsRectItem
    setPixmap(QPixmap(":/sprites/laser_pulse.png"));
    setRotation(90);

    //Connexion avec un timer pour un déplacement temporel
    QTimer * timer = new QTimer();
    connect(timer, SIGNAL(timeout()), this, SLOT(deplacer()));

    explosion = new QMediaPlayer();
    explosion->setMedia(QUrl("qrc:/sfx/explosion1.wav"));

    timer->start(50);
}

void Laser::deplacer()
{
    //Vérifie si le laser a touché un ennemi
    QList<QGraphicsItem *> objet_collision = collidingItems();
    int n = objet_collision.size();
    for(int i = 0; i < n; i++){
        if(typeid (*(objet_collision[i])) == typeid (Ennemi)){
            //En cas de collision avec un ennemi, supprimer l'ennemi et le laser
            qDebug() << "Ennemi détruit";
            Ennemi::compteurEnnemis--;
            scene() -> removeItem(objet_collision[i]);
            scene() -> removeItem(this);

            //Entendre une explosion
            if(explosion->state() == QMediaPlayer::PlayingState){
                explosion->setPosition(0);
            }
            explosion->play();

            //Vérifie si la partie est terminée
            if(Ennemi::compteurEnnemis == 0){
                emit victoire();
            }
            //Libérer la mémoire
            delete objet_collision[i];
            delete this;

            return;
        }
    }

    //Deplacement du laser
    setPos(x(), y() - 20);

    //Suppression du laser s'il sort de l'écran
    if(this->pos().y() - 10 < 0) {
        this->scene()->removeItem(this);
        delete this;
    }
}


#include "jeu.h"

#include<QUrl>

Jeu::Jeu()
{
    //Création de la scene
    this->scene = new QGraphicsScene();
    this->scene->setSceneRect(0,0,800,600);
    QImage * background = new QImage(":/backgroung/cera.jpg");
    this->scene->setBackgroundBrush(QBrush(*background));

    //Création d'une vue
    QGraphicsView  * view = new QGraphicsView(scene);
    view->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view->setFixedSize(800,600);

    //Création et ajout du joueur dans le jeu
    this->joueur = new Joueur();
    scene->addItem(joueur);

    //Création et ajout du "Game Over"
    gameover = new GameOver();
    scene->addItem(gameover);

    //Création des ennemis

    for(int i = 0; i < 6; i++){ //6 ennemis par lignes
        for(int j = 0; j < 4; j++){
            Ennemi * ennemi = new Ennemi();
            ennemi->setPos(i*100, -50 + j*100); //Le 1er mouvement est vertical
            scene->addItem(ennemi);

            connect(ennemi, SIGNAL(defaite()), this, SLOT(ennemisVainqueurs()));
       }
    }

//    Ennemi * ennemi = new Ennemi();
//    ennemi->setPos(400,200);
//    scene->addItem(ennemi);
//    connect(ennemi, SIGNAL(defaite()), this, SLOT(ennemisVainqueurs()));

    //Connexion des signaux pour informer la fin d'une partie

    connect(joueur, SIGNAL(ennemisDetruits()), this, SLOT(ennemisDetruits()));

    //Un peu de musique
    bgPlayer = new QMediaPlayer();
    bgPlayer->setMedia(QUrl("qrc:/music/Driving_the_Top_Down.mp3"));
    bgPlayer->play();

    view->show();
}

void Jeu::ennemisDetruits()
{
    bgPlayer->stop();
    gameover->victoire();
    scene->removeItem(joueur);
}

void Jeu::ennemisVainqueurs()
{
    bgPlayer->stop();
    gameover->defaite();
    scene->removeItem(joueur);
    //scene->deleteLater(); //Il n'y a plus rien

}


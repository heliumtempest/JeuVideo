#ifndef JEU_H
#define JEU_H

#include "joueur.h"
#include "ennemi.h"
#include "gameover.h"

#include <QApplication>
#include <QGraphicsScene>
#include <QGraphicsItem>
#include <QGraphicsView>
#include <QMediaPlayer>
#include <QImage>

class Jeu : public QObject
{
    Q_OBJECT
public:
    /**
     * @brief Jeu Effectue toute la mise en place pour le jeu
     */
    Jeu();

    QGraphicsScene * scene;
    Joueur * joueur;
    GameOver * gameover;
    QMediaPlayer * bgPlayer;

public slots:
    /**
     * @brief ennemisDetruits Recçoit le signal lorsque tous les ennemis sont détruits
     */
    void ennemisDetruits();

    /**
     * @brief ennemisVainqueurs Reçoit un signal lorsque le joueur a perdu
     */
    void ennemisVainqueurs();
};

#endif // JEU_H

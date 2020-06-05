#ifndef JOUEUR_H
#define JOUEUR_H

#include <QGraphicsRectItem>
#include <QKeyEvent>
#include <QGraphicsScene>
#include <QObject>
#include <QMediaPlayer>
#include <QGraphicsPixmapItem>

#include "laser.h"

class Joueur : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    Joueur(QObject *parent = nullptr);

    /**
     * @brief keyPressEvent Effectue le déplacement et les tirs du joueur à partir du clavier
     * @param keyevent
     */
    void keyPressEvent(QKeyEvent * keyevent);

private:
    /**
     * @brief pewpewPlayer Player qui diffuse le bruit d'un tir de laser du joueur
     */
    QMediaPlayer * pewpewPlayer;

signals:
    /**
     * @brief ennemisDetruits Signal envoyé lorsqu'il n'y a plus d'ennemis
     */
    void ennemisDetruits();
public slots:
    void victoire();

};

#endif // JOUEUR_H

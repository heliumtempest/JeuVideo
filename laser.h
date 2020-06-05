#ifndef LASER_H
#define LASER_H

#include <QGraphicsRectItem>
#include <QObject>
#include <QTimer>
#include <QGraphicsScene>
#include <QFont>
#include <QList>
#include <QMediaPlayer>
#include <QGraphicsPixmapItem>

#include "ennemi.h"


class Laser : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT

public:
    Laser();

private:
    /**
     * @brief explosion Player qui diffuse le bruit de l'explosion d'un ennemi touché par un tir de laser
     */
    QMediaPlayer * explosion;

public slots:
    /**
     * @brief deplacer Effectue le déplacement du tir laser. Contrôle si le tir touche un ennemi ou sort de l'écran
     */
    void deplacer();

signals:
    /**
     * @brief victoire Signal émis lorsque tous les ennemis sont détruits
     */
    void victoire();

};

#endif // LASER_H

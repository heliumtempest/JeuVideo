#ifndef ENNEMI_H
#define ENNEMI_H

#include <QObject>
#include <QGraphicsRectItem>
#include <QTimer>
#include <QGraphicsPixmapItem>

class Ennemi : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    explicit Ennemi(QObject *parent = nullptr);

    /**
     * @brief compteurEnnemis Nombre total d'ennemis présents en jeu
     */
    static int compteurEnnemis;

public slots:
    /**
     * @brief deplacement Effectue le déplacement d'un ennemi à intervalle régulier
     */
    void deplacement();

signals:
    void defaite();

private:

    /**
     * @brief compteurDeplacement Compte le nombre de déplacement d'un ennemi
     */
    int compteurDeplacement = 0;

    /**
     * @brief deplacementHorizontalTaille Définit le nombre de pixel effectué par un déplacement horizontal
     */
    int deplacementHorizontalTaille = - 50;

};

#endif // ENNEMI_H

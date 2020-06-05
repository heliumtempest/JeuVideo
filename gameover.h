#ifndef GAMEOVER_H
#define GAMEOVER_H

#include <QGraphicsTextItem>

class GameOver : public QGraphicsTextItem
{
public:
    GameOver(QGraphicsItem * parent = 0);

    /**
     * @brief victoire Affiche l'écran de GameOver en cas de victoire
     */
    void victoire();

    /**
     * @brief defaite Affiche l'écran de GameOver en cas de défaite
     */
    void defaite();

};

#endif // GAMEOVER_H

#include "jeu.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    new Jeu();

    return a.exec();
}

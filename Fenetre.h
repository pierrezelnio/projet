//
// Created by zelnio.pierre on 25/05/2020.
//

#ifndef TP5_FENETRE_H
#define TP5_FENETRE_H

#include "SFML/Graphics.hpp"


class Fenetre : public sf::RenderWindow {
protected:
    int largeur;
    int hauteur;
public:
    Fenetre(int _largeur, int _hauteur);
    void run();
};


#endif //TP5_FENETRE_H

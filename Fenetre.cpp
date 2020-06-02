//
// Created by zelnio.pierre on 25/05/2020.
//

#include <iostream>
#include "Fenetre.h"

Fenetre::Fenetre(int _largeur, int _hauteur) : largeur(_largeur), hauteur(_hauteur),
                                               sf::RenderWindow(sf::VideoMode(_largeur * 29, _hauteur * 29),
                                                                "Le Labyrinthe Du Renard") {

}

void Fenetre::run() {
std::cout << "bjr" << std::endl;
}

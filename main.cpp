#include <iostream>
#include <vector>
#include "SFML/Graphics.hpp"
#include "shape.h"
#include "Fenetre.h"

int main() {
    double px1 = 36;
    double py1 = 36;
    double px2 = 574;
    double py2 = 36;
    double variable_intermediaire_x;
    double variable_intermediaire_y;
    int longueur = 32;
    int hauteur = 32;
    int taille_map = 29;
    float vitesse_deplacement = 0.8;
    sf::Vector2f before_p1;
    sf::Vector2f before_p2;
    sf::Texture personnage_1;
    sf::Texture personnage_2;
    sf::Sprite sprite_personnage_1;
    sf::Sprite sprite_personnage_2;
    sf::Texture commandes;
    sf::Sprite sprite_commandes;
    sf::Font font;
    sf::Text text;

    Fenetre window(longueur, hauteur);
    window.run();


    std::cout << "Lancement du jeu" << std::endl;




    int tabmap[31][31] = //CORRESPOND A MA MAP
            {
                    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
                    {1, 0, 0, 1, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
                    {1, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
                    {1, 0, 0, 1, 0, 1, 1, 0, 0, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
                    {1, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
                    {1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
                    {1, 0, 0, 1, 0, 1, 0, 0, 1, 1, 1, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
                    {1, 0, 0, 1, 1, 1, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
                    {1, 4, 0, 0, 0, 0, 0, 0, 1, 0, 0, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
                    {1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
                    {1, 1, 1, 0, 2, 1, 1, 1, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
                    {1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
                    {1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
                    {1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
                    {1, 3, 3, 1, 1, 1, 1, 1, 1, 1, 2, 2, 2, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
                    {1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
                    {1, 0, 0, 0, 1, 0, 1, 1, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
                    {1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
                    {1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
                    {1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
                    {1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
                    {1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
                    {1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
                    {1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
                    {1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
                    {1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
                    {1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
                    {1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
                    {1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
                    {1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
                    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1}


            };

    std::vector<sf::RectangleShape> mur_vnr;

    for (int y = 0; y < taille_map; y++) {
        for (int x = 0; x < taille_map; x++) {
            if (tabmap[y][x] == 1) { //Creation de carre 32x32 couleur verte a chaque 1 dans le tabmap
                sf::RectangleShape mur(sf::Vector2f(longueur, hauteur));
                mur.setFillColor(sf::Color(0, 230, 0));
                mur.setPosition(sf::Vector2f(x * longueur, y * hauteur));
                mur_vnr.push_back(mur);
            } else if (tabmap[y][x] == 2) { //Creation de carre 32x32 couleur bleu a chaque 2 dans le tabmap
                sf::RectangleShape mur(sf::Vector2f(longueur, hauteur));
                mur.setFillColor((sf::Color::Blue));
                mur.setPosition(sf::Vector2f(x * longueur, y * hauteur));
                mur_vnr.push_back(mur);
            } else if (tabmap[y][x] == 3) { //Creation de carre 32x32 couleur rouge a chaque 3 dans le tabmap
                sf::RectangleShape mur(sf::Vector2f(longueur, hauteur));
                mur.setFillColor((sf::Color::Red));
                mur.setPosition(sf::Vector2f(x * longueur, y * hauteur));
                mur_vnr.push_back(mur);
            } else if (tabmap[y][x] == 4){
                sf::RectangleShape mur(sf::Vector2f(longueur, hauteur));
                mur.setFillColor((sf::Color::Yellow));
                mur.setPosition(sf::Vector2f(x * longueur,y * hauteur));
                mur_vnr.push_back(mur);
            }
        }
    }


    if (!personnage_1.loadFromFile("res/fox_vi12.png", //Sprite de base du perso 1
                                   sf::IntRect(128, 0, 32, 32))) {
        std::cout << "echec du sprite" << std::endl;
    }

    if (!personnage_2.loadFromFile("res/img/fox_vi12.png", //Sprite de base du perso 2
                                   sf::IntRect(224, 0, 32, 32))) {
        std::cout << "echec du sprite" << std::endl;
    }

    if (!commandes.loadFromFile("res/img/commandes_de_jeu.PNG")) { //Sprite des commandes
        std::cout << "echec du sprite des commandes" << std::endl;

    }

    if (!font.loadFromFile("res/font/ALBAM.TTF")){ //Police d'ecriture
        std::cout << "echec de la police d'ecriture" << std::endl;
    }

    text.setFont(font);      //Proprietes de ma police d'ecriture
    text.setString("ZelnioGame");
    text.setPosition(200, -5);
    text.setOutlineColor(sf::Color(255, 179, 71));
    text.setOutlineThickness(2);

    sprite_commandes.setPosition(0, 200);

    sprite_personnage_1.setTexture(personnage_1);
    sprite_personnage_2.setTexture(personnage_2);
    sprite_commandes.setTexture(commandes);

    while (window.isOpen()) {
        sf::Event event{};
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();

            }
            if(event.type == sf::Event::KeyPressed){
                if (event.key.code == sf::Keyboard::T){

                    variable_intermediaire_x = px1;
                    variable_intermediaire_y = py1;
                    px1 = px2;
                    py1 = py2;
                    px2= variable_intermediaire_x;
                    py2= variable_intermediaire_y;
                    std::cout << "switch" << std::endl;

                }
            }
        }

        before_p1.x = px1;
        before_p1.y = py1;
        before_p2.x = px2;
        before_p2.y = py2;

        //DEPLACEMENT AU CLAVIER P1

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
            py1 = py1 - vitesse_deplacement;
            personnage_1.loadFromFile("res/img/fox_vi12.png",
                                        sf::IntRect(128, 96, 32, 32)); }
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)){
            py1 = py1 + vitesse_deplacement;
            personnage_1.loadFromFile("res/img/fox_vi12.png",
                                      sf::IntRect(128, 0, 32, 32));
        }
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)){
            px1 = px1 - vitesse_deplacement;
            personnage_1.loadFromFile("res/img/fox_vi12.png",
                                      sf::IntRect(128, 32, 32, 32));
        }
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)){
            px1 = px1 + vitesse_deplacement;
            personnage_1.loadFromFile("res/img/fox_vi12.png",
                                      sf::IntRect(128, 64, 32, 32));
        }
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::B)) {
            px1 = 35, py1 = 35;
        }

        //DEPLACEMENT AU CLAVIER P2

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Z)){
            py2 = py2 - vitesse_deplacement;
            personnage_2.loadFromFile("res/img/fox_vi12.png",
                                      sf::IntRect(224, 96, 32, 32)); }
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)){
            py2 = py2 + vitesse_deplacement;
            personnage_2.loadFromFile("res/img/fox_vi12.png",
                                      sf::IntRect(224, 0, 32, 32));
        }
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q)){
            px2 = px2 - vitesse_deplacement;
            personnage_2.loadFromFile("res/img/fox_vi12.png",
                                      sf::IntRect(224, 32, 32, 32));
        }
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)){
            px2 = px2 + vitesse_deplacement;
            personnage_2.loadFromFile("res/img/fox_vi12.png",
                                      sf::IntRect(224, 64, 32, 32));}
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::R)) {
            px2 = 574, py2 = 36;
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter)){
            commandes.loadFromFile("res/img/fond_transparent.png");
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::C)){
            commandes.loadFromFile("res/img/commandes_de_jeu.PNG");
        }

        sprite_personnage_1.setPosition(sf::Vector2f(px1, py1));
        sprite_personnage_2.setPosition(sf::Vector2f(px2, py2));

        for (int y = 0; y < 29; y++) {
            for (int x = 0; x < 29; x++) {
                int top = y * hauteur + 3;
                int bottom = y * hauteur + hauteur - 3;
                int left = x * longueur + 3;
                int right = x * longueur + longueur - 3;

                if (tabmap[y][x] == 1 && py1 <= bottom && py1 + hauteur >= top && px1 <= right &&
                    px1 + longueur >= left) {
                    px1 = before_p1.x;
                    py1 = before_p1.y;
                } else if (tabmap[y][x] == 1 && py2 <= bottom && py2 + hauteur >= top && px2 <= right &&
                           px2 + longueur >= left) {
                    px2 = before_p2.x;
                    py2 = before_p2.y;
                } else if (tabmap[y][x] == 2 && py2 <= bottom && py2 + hauteur >= top && px2 <= right &&
                           px2 + longueur >= left) {
                    px2 = before_p2.x;
                    py2 = before_p2.y;
                } else if (tabmap[y][x] == 3 && py1 <= bottom && py1 + hauteur >= top && px1 <= right &&
                           px1 + longueur >= left) {
                    px1 = before_p1.x;
                    py1 = before_p1.y;

                } else if (tabmap[y][x] == 4 && py1 <= bottom && py1 + hauteur >= top && px1 <= right &&
                           px1 + longueur >= left) {

                }
            }

        }

        window.clear(sf::Color(182, 230, 130));

        for (int i = 0; i < mur_vnr.size(); i++)
            window.draw(mur_vnr[i]);


        window.draw(sprite_personnage_1);
        window.draw(sprite_personnage_2);
        window.draw(sprite_commandes);
        window.draw(text);
        window.display();
    }
    std::cout << "Fermeture du jeu, a la prochaine!" << std::endl;

    return 0;

}

#include <iostream>
#include <fstream>
#include <vector>
#include "SFML/Graphics.hpp"
#include "shape.h"
#include "Fenetre.h"
#include "windows.h"

int main() {
    float longueur = 32;
    float hauteur = 32;
    double px1 = longueur;
    double py1 = hauteur;
    double px2 = longueur * 27;
    double py2 = hauteur;
    double variable_intermediaire_x;
    double variable_intermediaire_y;
    int taille_map = 29;
    float vitesse_deplacement = 0.8;
    sf::Vector2f before_p1;
    sf::Vector2f before_p2;
    sf::Texture personnage_1;
    sf::Texture personnage_2;
    sf::Sprite sprite_personnage_1;
    sf::Sprite sprite_personnage_2;
    sf::Texture piece;
    sf::Sprite sprite_piece_1;
    sf::Sprite sprite_piece_2;
    sf::Sprite sprite_piece_3;
    sf::Sprite sprite_piece_4;
    sf::Sprite sprite_piece_5;
    sf::Sprite sprite_piece_6;
    sf::Sprite sprite_piece_7;
    sf::Sprite sprite_piece_8;
    sf::Sprite sprite_piece_9;
    sf::Sprite sprite_piece_10;
    sf::Font font;
    sf::Text texte_piece_1;
    sf::Text texte_piece_2;
    sf::Text texte_piece_3;
    sf::Text texte_piece_4;
    sf::Text texte_piece_5;
    sf::Text texte_piece_6;
    sf::Text texte_piece_7;
    sf::Text texte_piece_8;
    sf::Text texte_piece_9;
    sf::Text texte_piece_10;
    sf::Text label;
    sf::Text win_text;

    std::string const nbrGames("res/nbrGames.txt");
    std::ofstream monFlux(nbrGames.c_str());
    if (monFlux){

    }
    else{
        std::cout << "marche pas" << std::endl;
    }


    Fenetre window(longueur, hauteur);
    window.run();


    int tabmap[29][29] = //CORRESPOND A MA MAP
            {
                    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
                    {1, 0, 0, 1, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 3, 0, 0, 0, 0, 2, 0, 3, 0, 0, 0, 1, 0, 1},
                    {1, 0, 0, 1, 0, 1, 5, 1, 0, 1, 6, 1, 0, 0, 0, 3, 0, 0, 1, 0, 1, 1, 1, 1, 1, 2, 1, 0, 1},
                    {1, 0, 0, 1, 0, 1, 1, 1, 2, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 1},
                    {1, 0, 0, 0, 0, 1, 0, 1, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 1, 1, 1, 1, 0, 0, 0, 0, 1},
                    {1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 1, 0, 1, 0, 7, 1, 1, 1, 1, 0, 1},
                    {1, 0, 0, 1, 0, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 1, 0, 0, 0, 1, 2, 1, 1, 0, 0, 0, 0, 1},
                    {1, 0, 0, 1, 1, 1, 0, 0, 3, 0, 8, 1, 0, 0, 0, 0, 3, 0, 0, 0, 1, 0, 0, 3, 0, 0, 0, 0, 1},
                    {1, 1, 0, 0, 1, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 2, 2, 1, 1, 1, 1, 1, 2, 1, 1, 1},
                    {1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 1, 9, 1, 0, 2, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 11, 1},
                    {1, 1, 1, 2, 2, 1, 1, 1, 1, 1, 0, 1, 0, 1, 0, 2, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 1, 3, 1},
                    {1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 1, 1, 3, 3, 1, 0, 1, 1, 0, 1, 0, 1},
                    {1, 1, 1, 1, 0, 0, 3, 0, 1, 1, 1, 1, 1, 1, 0, 1, 0, 0, 1, 0, 0, 1, 0, 1, 0, 0, 0, 0, 1},
                    {1, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 10, 1, 0, 0, 0, 0, 0, 1, 0, 1, 1, 1, 1, 0, 1},
                    {1, 3, 3, 1, 1, 1, 1, 1, 1, 1, 2, 2, 2, 1, 1, 1, 1, 1, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1},
                    {1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 2, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 0, 1},
                    {1, 0, 0, 0, 1, 0, 1, 1, 1, 0, 1, 1, 1, 1, 0, 0, 1, 0, 1, 1, 1, 1, 1, 0, 0, 12, 1, 0, 1},
                    {1, 2, 2, 2, 1, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 1, 1, 1, 1, 0, 0, 0, 3, 0, 1, 1, 1, 2, 1},
                    {1, 0, 0, 0, 0, 0, 1, 0, 1, 1, 3, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 1},
                    {1, 0, 0, 0, 0, 0, 1, 1, 1, 1, 0, 0, 0, 1, 1, 1, 1, 1, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 1},
                    {1, 1, 1, 1, 1, 0, 1, 0, 0, 1, 0, 1, 1, 1, 0, 0, 0, 1, 1, 1, 1, 1, 1, 0, 1, 0, 0, 0, 1},
                    {1, 0, 0, 0, 2, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 3, 0, 0, 0, 1, 1, 1, 1, 1, 1, 0, 1},
                    {1, 1, 0, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 0, 0, 2, 0, 1, 0, 1, 0, 0, 1},
                    {1, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 2, 0, 0, 0, 1, 3, 1, 1},
                    {1, 0, 1, 1, 1, 0, 1, 0, 1, 1, 1, 1, 1, 1, 2, 1, 1, 0, 1, 1, 1, 1, 1, 1, 0, 1, 0, 0, 1},
                    {1, 13, 1, 0, 1, 0, 1, 0, 1, 4, 1, 0, 1, 0, 0, 0, 1, 1, 1, 0, 1, 0, 0, 1, 0, 1, 2, 1, 1},
                    {1, 1, 1, 0, 0, 0, 1, 0, 1, 0, 1, 0, 1, 0, 0, 1, 1, 14, 1, 0, 0, 0, 0, 2, 0, 1, 0, 0, 1},
                    {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 3, 0, 0, 1, 0, 1, 5, 0, 1, 0, 3, 0, 0, 1},
                    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},


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
            } else if (tabmap[y][x] == 4) {
                sf::RectangleShape mur(sf::Vector2f(longueur, hauteur));
                mur.setFillColor((sf::Color::Yellow));
                mur.setPosition(sf::Vector2f(x * longueur, y * hauteur));
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


    if (!piece.loadFromFile("res/img/piece.JPG",
                            sf::IntRect (7, 7, 32, 32))){
        std::cout << "echec du sprite piece" << std::endl;
    }
    sprite_piece_1.setPosition(longueur*10, hauteur*7);
    sprite_piece_2.setPosition(longueur*10, hauteur*2);
    sprite_piece_3.setPosition(longueur*27, hauteur*9);
    sprite_piece_4.setPosition(longueur*1, hauteur*25);
    sprite_piece_5.setPosition(longueur*14, hauteur*13);
    sprite_piece_6.setPosition(longueur*17, hauteur*26);
    sprite_piece_7.setPosition(longueur*25, hauteur*16);
    sprite_piece_8.setPosition(longueur*6, hauteur*2);
    sprite_piece_9.setPosition(longueur*12, hauteur*9);
    sprite_piece_10.setPosition(longueur*22, hauteur*5);

    if (!font.loadFromFile("res/font/ALBAM.TTF")) { //Police d'ecriture
        std::cout << "echec de la police d'ecriture" << std::endl;
    }

    label.setFont(font);      //Proprietes de ma police d'ecriture
    label.setString("ZelnioGame");
    label.setPosition(200, -5);
    label.setOutlineColor(sf::Color(255, 179, 71));
    label.setOutlineThickness(2);




    sprite_personnage_1.setTexture(personnage_1);
    sprite_personnage_2.setTexture(personnage_2);
    sprite_piece_1.setTexture(piece);
    sprite_piece_2.setTexture(piece);
    sprite_piece_3.setTexture(piece);
    sprite_piece_4.setTexture(piece);
    sprite_piece_5.setTexture(piece);
    sprite_piece_6.setTexture(piece);
    sprite_piece_7.setTexture(piece);
    sprite_piece_8.setTexture(piece);
    sprite_piece_9.setTexture(piece);
    sprite_piece_10.setTexture(piece);


    while (window.isOpen()) {
        sf::Event event{};
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();

            }
            if (event.type == sf::Event::KeyPressed) {
                if (event.key.code == sf::Keyboard::T) {

                    variable_intermediaire_x = px1;
                    variable_intermediaire_y = py1;
                    px1 = px2;
                    py1 = py2;
                    px2 = variable_intermediaire_x;
                    py2 = variable_intermediaire_y;
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
                                      sf::IntRect(128, 96, 32, 32));
        } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
            py1 = py1 + vitesse_deplacement;
            personnage_1.loadFromFile("res/img/fox_vi12.png",
                                      sf::IntRect(128, 0, 32, 32));
        } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
            px1 = px1 - vitesse_deplacement;
            personnage_1.loadFromFile("res/img/fox_vi12.png",
                                      sf::IntRect(128, 32, 32, 32));
        } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
            px1 = px1 + vitesse_deplacement;
            personnage_1.loadFromFile("res/img/fox_vi12.png",
                                      sf::IntRect(128, 64, 32, 32));
        } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::B)) {
            px1 = 35, py1 = 35;
        }

        //DEPLACEMENT AU CLAVIER P2

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Z)) {
            py2 = py2 - vitesse_deplacement;
            personnage_2.loadFromFile("res/img/fox_vi12.png",
                                      sf::IntRect(224, 96, 32, 32));
        } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
            py2 = py2 + vitesse_deplacement;
            personnage_2.loadFromFile("res/img/fox_vi12.png",
                                      sf::IntRect(224, 0, 32, 32));
        } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q)) {
            px2 = px2 - vitesse_deplacement;
            personnage_2.loadFromFile("res/img/fox_vi12.png",
                                      sf::IntRect(224, 32, 32, 32));
        } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
            px2 = px2 + vitesse_deplacement;
            personnage_2.loadFromFile("res/img/fox_vi12.png",
                                      sf::IntRect(224, 64, 32, 32));
        } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::R)) {
            px2 = 866, py2 = 36;
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
                           px1 + longueur >= left){

                    win_text.setFont(font);
                    win_text.setString(" YOU WIN");
                    win_text.setCharacterSize(200);
                    win_text.setPosition(50, 200);
                    win_text.setOutlineColor(sf::Color::Blue);
                    win_text.setOutlineThickness(0);
                    if (monFlux){
                        monFlux << "Victoire !!" << std::endl;
                    }
                    else{
                        std::cout << "echec d'ecriture dans mon fichier" << std::endl;
                    }



                } else if (tabmap[y][x] == 5 && py1 <= bottom && py1 + hauteur >= top && px1 <= right &&
                           px1 + longueur >= left) {
                    texte_piece_1.setFont(font);
                    texte_piece_1.setString("x");
                    texte_piece_1.setPosition(longueur * 6 + 8, hauteur * 2 - 5);
                    texte_piece_1.setFillColor(sf::Color::Black);

                } else if (tabmap[y][x] == 5 && py2 <= bottom && py2 + hauteur >= top && px2 <= right &&
                          px2 + longueur >= left) {
                    texte_piece_1.setFont(font);
                    texte_piece_1.setString("x");
                    texte_piece_1.setPosition(longueur * 6 + 8, hauteur * 2 - 5);
                    texte_piece_1.setFillColor(sf::Color::Black);

                } else if (tabmap[y][x] == 6 && py1 <= bottom && py1 + hauteur >= top && px1 <= right &&
                           px1 + longueur >= left) {
                    texte_piece_2.setFont(font);
                    texte_piece_2.setString("x");
                    texte_piece_2.setPosition(longueur * 10 + 8, hauteur * 2 - 5);
                    texte_piece_2.setFillColor(sf::Color::Black);

                } else if (tabmap[y][x] == 6 && py2 <= bottom && py2 + hauteur >= top && px2 <= right &&
                           px2 + longueur >= left) {
                    texte_piece_2.setFont(font);
                    texte_piece_2.setString("x");
                    texte_piece_2.setPosition(longueur * 10 + 8, hauteur * 2 - 5);
                    texte_piece_2.setFillColor(sf::Color::Black);

                } else if (tabmap[y][x] == 7 && py1 <= bottom && py1 + hauteur >= top && px1 <= right &&
                           px1 + longueur >= left) {
                    texte_piece_3.setFont(font);
                    texte_piece_3.setString("x");
                    texte_piece_3.setPosition(longueur * 22 + 8, hauteur * 5 - 5);
                    texte_piece_3.setFillColor(sf::Color::Black);

                } else if (tabmap[y][x] == 7 && py2 <= bottom && py2 + hauteur >= top && px2 <= right &&
                           px2 + longueur >= left) {
                    texte_piece_3.setFont(font);
                    texte_piece_3.setString("x");
                    texte_piece_3.setPosition(longueur * 22 + 8, hauteur * 5 - 5);
                    texte_piece_3.setFillColor(sf::Color::Black);

                } else if (tabmap[y][x] == 8 && py1 <= bottom && py1 + hauteur >= top && px1 <= right &&
                           px1 + longueur >= left) {
                    texte_piece_4.setFont(font);
                    texte_piece_4.setString("x");
                    texte_piece_4.setPosition(longueur * 10 + 8, hauteur * 7 - 5);
                    texte_piece_4.setFillColor(sf::Color::Black);

                }  else if (tabmap[y][x] == 8 && py2 <= bottom && py2 + hauteur >= top && px2 <= right &&
                            px2 + longueur >= left) {
                    texte_piece_4.setFont(font);
                    texte_piece_4.setString("x");
                    texte_piece_4.setPosition(longueur * 10 + 8, hauteur * 7 - 5);
                    texte_piece_4.setFillColor(sf::Color::Black);

                }  else if (tabmap[y][x] == 9 && py1 <= bottom && py1 + hauteur >= top && px1 <= right &&
                            px1 + longueur >= left) {
                    texte_piece_5.setFont(font);
                    texte_piece_5.setString("x");
                    texte_piece_5.setPosition(longueur * 12 + 8, hauteur * 9 - 5);
                    texte_piece_5.setFillColor(sf::Color::Black);

                }  else if (tabmap[y][x] == 9 && py2 <= bottom && py2 + hauteur >= top && px2 <= right &&
                            px2 + longueur >= left) {
                    texte_piece_5.setFont(font);
                    texte_piece_5.setString("x");
                    texte_piece_5.setPosition(longueur * 12 + 8, hauteur * 9 - 5);
                    texte_piece_5.setFillColor(sf::Color::Black);

                }  else if (tabmap[y][x] == 10 && py1 <= bottom && py1 + hauteur >= top && px1 <= right &&
                            px1 + longueur >= left) {
                    texte_piece_6.setFont(font);
                    texte_piece_6.setString("x");
                    texte_piece_6.setPosition(longueur * 14 + 8, hauteur * 13 - 5);
                    texte_piece_6.setFillColor(sf::Color::Black);

                } else if (tabmap[y][x] == 10 && py2 <= bottom && py2 + hauteur >= top && px2 <= right &&
                           px2 + longueur >= left) {
                    texte_piece_6.setFont(font);
                    texte_piece_6.setString("x");
                    texte_piece_6.setPosition(longueur * 14 + 8, hauteur * 13 - 5);
                    texte_piece_6.setFillColor(sf::Color::Black);

                } else if (tabmap[y][x] == 11 && py1 <= bottom && py1 + hauteur >= top && px1 <= right &&
                           px1 + longueur >= left) {
                    texte_piece_7.setFont(font);
                    texte_piece_7.setString("x");
                    texte_piece_7.setPosition(longueur * 27 + 8, hauteur * 9 - 5);
                    texte_piece_7.setFillColor(sf::Color::Black);

                } else if (tabmap[y][x] == 11 && py2 <= bottom && py2 + hauteur >= top && px2 <= right &&
                           px2 + longueur >= left) {
                    texte_piece_7.setFont(font);
                    texte_piece_7.setString("x");
                    texte_piece_7.setPosition(longueur * 27 + 8, hauteur * 9 - 5);
                    texte_piece_7.setFillColor(sf::Color::Black);

                } else if (tabmap[y][x] == 12 && py1 <= bottom && py1 + hauteur >= top && px1 <= right &&
                          px1 + longueur >= left) {
                    texte_piece_8.setFont(font);
                    texte_piece_8.setString("x");
                    texte_piece_8.setPosition(longueur * 25 + 8, hauteur * 16 - 5);
                    texte_piece_8.setFillColor(sf::Color::Black);

                } else if (tabmap[y][x] == 12 && py2 <= bottom && py2 + hauteur >= top && px2 <= right &&
                           px2 + longueur >= left) {
                    texte_piece_8.setFont(font);
                    texte_piece_8.setString("x");
                    texte_piece_8.setPosition(longueur * 25 + 8, hauteur * 16 - 5);
                    texte_piece_8.setFillColor(sf::Color::Black);

                } else if (tabmap[y][x] == 13 && py1 <= bottom && py1 + hauteur >= top && px1 <= right &&
                           px1 + longueur >= left) {
                    texte_piece_9.setFont(font);
                    texte_piece_9.setString("x");
                    texte_piece_9.setPosition(longueur * 1 + 8, hauteur * 25 - 5);
                    texte_piece_9.setFillColor(sf::Color::Black);

                } else if (tabmap[y][x] == 13 && py2 <= bottom && py2 + hauteur >= top && px2 <= right &&
                           px2 + longueur >= left) {
                    texte_piece_9.setFont(font);
                    texte_piece_9.setString("x");
                    texte_piece_9.setPosition(longueur * 1 + 8, hauteur * 25 - 5);
                    texte_piece_9.setFillColor(sf::Color::Black);

                }  else if (tabmap[y][x] == 14 && py1 <= bottom && py1 + hauteur >= top && px1 <= right &&
                            px1 + longueur >= left) {
                    texte_piece_10.setFont(font);
                    texte_piece_10.setString("x");
                    texte_piece_10.setPosition(longueur * 17 + 8, hauteur * 26 - 5);
                    texte_piece_10.setFillColor(sf::Color::Black);

                }   else if (tabmap[y][x] == 14 && py2 <= bottom && py2 + hauteur >= top && px2 <= right &&
                             px2 + longueur >= left) {
                    texte_piece_10.setFont(font);
                    texte_piece_10.setString("x");
                    texte_piece_10.setPosition(longueur * 17 + 8, hauteur * 26 - 5);
                    texte_piece_10.setFillColor(sf::Color::Black);

                }

            }

        }

        window.clear(sf::Color(182, 230, 130));

        for (int i = 0; i < mur_vnr.size(); i++)
            window.draw(mur_vnr[i]);


        window.draw(sprite_personnage_1);
        window.draw(sprite_personnage_2);
        window.draw(sprite_piece_1);
        window.draw(sprite_piece_2);
        window.draw(sprite_piece_3);
        window.draw(sprite_piece_4);
        window.draw(sprite_piece_5);
        window.draw(sprite_piece_6);
        window.draw(sprite_piece_7);
        window.draw(sprite_piece_8);
        window.draw(sprite_piece_9);
        window.draw(sprite_piece_10);
        window.draw(label);
        window.draw(win_text);
        window.draw(texte_piece_1);
        window.draw(texte_piece_2);
        window.draw(texte_piece_3);
        window.draw(texte_piece_4);
        window.draw(texte_piece_5);
        window.draw(texte_piece_6);
        window.draw(texte_piece_7);
        window.draw(texte_piece_8);
        window.draw(texte_piece_9);
        window.draw(texte_piece_10);
        window.display();
    }
    std::cout << "Fermeture du jeu, a la prochaine!" << std::endl;

    return 0;

}

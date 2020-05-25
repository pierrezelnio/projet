#include <iostream>
#include <vector>
#include "SFML/Graphics.hpp"
#include "shape.h"

int main() {
    double px1 = 36;
    double py1 = 36;
    double px2 = 574;
    double py2 = 36;
    int longueur = 32;
    int hauteur = 32;
    float vitesse_deplacement = 0.1;
    sf::Vector2f before_p1;
    sf::Vector2f before_p2;

    sf::RenderWindow window(sf::VideoMode(longueur * 20, hauteur * 20), "Le Labyrinthe Du Renard");

    std::cout << "Start du super jeu" << std::endl;


    sf::RectangleShape player1(sf::Vector2f(longueur, hauteur));
    player1.setFillColor(sf::Color::Red);

    sf::RectangleShape player2(sf::Vector2f(longueur, hauteur));
    player2.setFillColor(sf::Color::Cyan);

    int tabmap[20][20] =
            {
                    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
                    {1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
                    {1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
                    {1, 0, 0, 1, 1, 1, 1, 0, 0, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 1},
                    {1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1},
                    {1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 1},
                    {1, 0, 0, 1, 0, 1, 0, 0, 1, 1, 1, 1, 0, 0, 0, 0, 1, 0, 0, 1},
                    {1, 0, 0, 1, 1, 1, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 1},
                    {1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 1, 1, 1, 1, 1, 1, 0, 0, 1},
                    {1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
                    {1, 1, 1, 0, 0, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
                    {1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
                    {1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
                    {1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
                    {1, 0, 0, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1},
                    {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1},
                    {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1},
                    {1, 3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 1},
                    {1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
                    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1}


            };

    std::vector<sf::RectangleShape> mur_vnr;

    for (int y = 0; y < 20; y++) {
        for (int x = 0; x < 20; x++) {
            if (tabmap[y][x] == 1) {
                sf::RectangleShape mur(sf::Vector2f(longueur, hauteur));
                mur.setFillColor(sf::Color::White);
                mur.setPosition(sf::Vector2f(x * longueur, y * hauteur));
                mur_vnr.push_back(mur);
            }
            else if (tabmap[y][x] == 2){
                sf::RectangleShape mur(sf::Vector2f(longueur, hauteur));
                mur.setFillColor((sf::Color(120,0, 0)));
                mur.setPosition(sf::Vector2f(x * longueur, y * hauteur));
                mur_vnr.push_back(mur);
            }
            else if (tabmap[y][x] == 3){
                sf::RectangleShape mur(sf::Vector2f(longueur, hauteur));
                mur.setFillColor((sf::Color(0, 0, 120)));
                mur.setPosition(sf::Vector2f(x * longueur, y * hauteur));
                mur_vnr.push_back(mur);
            }
        }
    }

    while (window.isOpen()) {
        sf::Event event{};
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
        }

        before_p1.x = px1;
        before_p1.y = py1;
        before_p2.x = px2;
        before_p2.y = py2;
        //DEPLACEMENT AU CLAVIER P1

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
            py1 = py1 - vitesse_deplacement;
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
            py1 = py1 + vitesse_deplacement;
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
            px1 = px1 - vitesse_deplacement;
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
            px1 = px1 + vitesse_deplacement;
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::R)) {
            px1 = 35, py1 = 35;
        }

        //DEPLACEMENT AU CLAVIER P2

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Z))
            py2 = py2 - vitesse_deplacement;
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
            py2 = py2 + vitesse_deplacement;
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q))
            px2 = px2 - vitesse_deplacement;
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
            px2 = px2 + vitesse_deplacement;
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::G)) {
            px2 = 574, py2 = 36;
        }

        player1.setPosition(sf::Vector2f(px1, py1));
        player2.setPosition(sf::Vector2f(px2, py2));

        for (int y = 0; y < 20; y++) {
            for (int x = 0; x < 20; x++) {
                int top = y * hauteur;
                int bottom = y * hauteur + hauteur;
                int left = x * longueur;
                int right = x * longueur + longueur;

                if (tabmap[y][x] == 1 && py1 <= bottom && py1 + hauteur >= top && px1 <= right && px1 + longueur >= left) {
                    px1 = before_p1.x;
                    py1 = before_p1.y;
                }
                else if (tabmap[y][x] == 1 && py2 <= bottom && py2 + hauteur >= top && px2 <= right && px2 + longueur >= left) {
                    px2 = before_p2.x;
                    py2 = before_p2.y;
                }
                else if (tabmap[y][x] == 2 && py1 <= bottom && py1 + hauteur >= top && px1 <= right && px1 + longueur >= left){
                    window.close();}
            }

        }


        window.clear(sf::Color(0, 230, 0));

        for (int i = 0; i < mur_vnr.size(); i++)
            window.draw(mur_vnr[i]);


        window.draw(player1);
        window.draw(player2);
        window.display();
    }
    std::cout << "J'ai leave la fenetre proprement !" << std::endl;

    return 0;

}

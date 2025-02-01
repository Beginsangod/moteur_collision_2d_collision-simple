#include <iostream>
#include <chrono>
#include <thread>
#include <stdio.h>
#include <cstdlib>
#include <ctime>
#include "formes.h"

int main(int argc,char** argv)
{
    char rectangle[5][6]; // Grille pour le rectangle
    char triangle[5][11]; // Grille pour le triangle
    char cercle[3][5]; // Grille pour le cercle
    char point = '*'; // Creation du point
    bool running = true; // Variable pour la boucle while

    // Grille principale
    char grille[20][50];

    // Ici, rectx et recty represente l'endroit ou va etre representer le rectangle dans la grille principale
    // L'action decrite ci dessus est valable pour pointx et pointy (point)
    // Pour trix et triy (triangle)
    // Pour cerx et cery (cercle)
    int rectx = 2, recty = 4, pointx = 18, pointy = 2, trix = 13, triy = 37, cerx = 2, cery = 44;
       
    // Initialiser le générateur de nombres aléatoires
    srand(static_cast<unsigned int>(time(nullptr)));

    // Directions initiales des formes
    int rdirx = (rand() % 3) - 1; // Valeurs possibles : -1, 0, 1
    int rdiry = (rand() % 3) - 1;
    if (rdirx == 0 && rdiry == 0) rdirx = 1;
    int tdirx = (rand() % 3) - 1; // Valeurs possibles : -1, 0, 1
    int tdiry = (rand() % 3) - 1;
    if (tdirx == 0 && tdiry == 0) tdirx = 1;
    int cdirx = (rand() % 3) - 1; // Valeurs possibles : -1, 0, 1
    int cdiry = (rand() % 3) - 1;
    if (cdirx == 0 && cdiry == 0) cdirx = 1;
    int pdirx = (rand() % 3) - 1; // Valeurs possibles : -1, 0, 1
    int pdiry = (rand() % 3) - 1;
    if (pdirx == 0 && pdiry == 0) pdiry = 1;

    definirRectangle(rectangle); // Donner une forme de rectangle a la grille en dessinant les contours
    definirTriangle(triangle); // Donner une forme triangle a la grille triangle[][]
    definirCercle(cercle); // Donner une forme de cercle a la grille cercle[][]

    while (running)
    {   
        // Effacement de l'écran en fonction du système d'exploitation
        #ifdef _WIN32
        system("cls");
        #else
        system("clear");
        #endif
        // Afficher la grille principale avec le rectangle, le cercle, le point et le triangle
        afficheRepere(grille, rectx, recty, pointx, pointy, trix, triy, triangle, rectangle, cercle, cerx, cery);

        // Deplacement des formes dans la grille
        deplacement(rectx, recty, rdirx, rdiry,pointx, pointy, pdirx, pdiry,trix, triy, tdirx, tdiry,cerx, cery, cdirx, cdiry, triangle, cercle);

        std::this_thread::sleep_for(std::chrono::milliseconds(16)) ;// Pause de 16ms
    }
    
    return 0;
}
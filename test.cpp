#include <iostream>

#include "formes.h"

int main(int argc,char** argv)
{
    char rectangle[5][6]; // Grille pour le rectangle
    char triangle[5][11]; // Grille pour le triangle
    char cercle[3][5]; // Grille pour le cercle
    char point = '*'; // Creation du point

    // Grille principale
    char grille[20][50];

    // Ici, rectx et recty represente l'endroit ou va etre representer le rectangle dans la grille principale
    // L'action decrite ci dsssus est valable pour pointx et pointy (point)
    // Pour trix et triy (triangle)
    // Pour cerx et cery (cercle)
    int rectx = 2, recty = 4, pointx = 10, pointy = 10, trix = 10, triy = 15, cerx = 6, cery = 25;

    definirRectangle(rectangle); // Donner une forme de rectangle a la grille en dessinant les contours
    definirTriangle(triangle); // Donner une forme triangle a la grille triangle[][]
    definirCercle(cercle); // Donner une forme de cercle a la grille cercle[][]

    // Afcficher la grille principale avec le rectangle, le cercle, le point et le triangle
    afficheRepere(grille, rectx, recty, pointx, pointy, trix, triy, triangle, rectangle, cercle, cerx, cery);
}
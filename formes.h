#define FORMES_INCLUDED
#ifdef FORMES_INCLUDED

#include <iostream>

// Ajout des contours a la grille pour avoir un rectangle
void definirRectangle(char rectangle[5][6])
{
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 6; j++)
        {
            if(i == 0 || i == 4 || j == 0 || j == 5)
            {
                rectangle[i][j] = '*';
            }
            else
            {
                rectangle[i][j] = ' ';
            }
        }
    }
}

// Creation d'un triangle dans la grille triangle[][]
void definirTriangle(char triangle[5][11])
{
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 11; j++)
        {
            if((i == 4) && (j != 0 && j != 10))
            {
                triangle[i][j] = '*';
            }
            else if((i == 3) && ( j == 2 || j == 8))
            {
                triangle[i][j] = '*';
            }
            else if((i == 2) && (j == 3 || j == 7))
            {
                triangle[i][j] = '*';
            }
            else if((i == 1) && (j == 4 || j == 6))
            {
                triangle[i][j] = '*';
            }
            else if((i == 0) && (j == 5))
            {
                triangle[i][j] = '*';
            }
            else
            {
                triangle[i][j] = ' ';
            }
        }
    }
}

// Creation d'un cercle dans la grille cercle[][]
void definirCercle(char cercle[3][5])
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            if((i == 0 || i == 2) && (j == 1 || j == 2 || j == 3))
            {
                cercle[i][j] = '*';
            }
            else if((i == 1) && (j == 0 || j == 4))
            {
                cercle[i][j] = '*';
            }
            else 
            {
                cercle[i][j] = ' ';
            }
        }
    }
}

// Affichage de la grille principale
// En prenant soin d'afficher les differentes formes a leur positions respectives
void afficheRepere(char grille[20][50], int rectx, int recty, int p1, int p2, int trix, int triy, char triangle[5][11], char rectangle[5][6], char cercle[3][5], int cerx, int cery)
{
    int a = 0, b = 0, x = 0, y = 0, u = 0, v = 0;
    for (int i = 0; i < 20; i++)
    {
        for (int j = 0; j < 50; j++)
        {
            if(i == 0 || i == 19 || j == 0 || j == 49)
            {
                std::cout << "#";
            }
            else if(i >= rectx && i < rectx + 5 && j >= recty && j < recty + 6)
            {
                std::cout << rectangle[x][y];
                y++;
            }
            else if(i == p1 && j == p2)
            {
                std::cout << "*";
            }
            else if(i >= trix && i < trix + 5 && j >= triy && j < triy + 11)
            {
                std::cout << triangle[a][b];
                b++;
            }
            else if(i >= cerx && i < cerx + 3 && j >= cery && j < cery + 5)
            {
                std::cout << cercle[u][v];
                v++;
            }
            else
            {
                std::cout << " ";
            }
        }
        std::cout << std::endl;
    }
}

#endif
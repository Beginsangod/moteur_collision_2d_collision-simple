#define FORMES_INCLUDED
#ifdef FORMES_INCLUDED

#include <iostream>
#include "collision_check.h"

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

//deplacement des formes dans la map
void deplacement(int& rectx, int& recty, int& rdirx, int& rdiry,int& px, int& py, int& pdirx, int& pdiry,int& trix, int& triy, int& tdirx, int& tdiry,int& cerx, int& cery, int& cdirx, int& cdiry, char triangle[5][11], char cercle[3][5])
{
    // Calcul des positions futures
    int future_rectx = rectx + rdirx;
    int future_recty = recty + rdiry;
    int future_trix = trix + tdirx;
    int future_triy = triy + tdiry;
    int future_cerx = cerx + cdirx;
    int future_cery = cery + cdiry;
    int future_px = px + pdirx;
    int future_py = py + pdiry;

    // Vérification des collisions pour chaque forme

    // --- Rectangle ---
    if (future_rectx <= 1 || future_rectx + RECT_HEIGHT >= 18)
        rdirx = -rdirx;
    if (future_recty <= 0 || future_recty + RECT_WIDTH >= 50)
        rdiry = -rdiry;
    else
    {
        // Vérifier les collisions avec les autres formes
        if (collision_check(future_rectx, future_recty, trix, triy, cerx, cery, px, py, triangle, cercle))
        {
            rdirx = -rdirx;
            rdiry = -rdiry;
        }
        else
        {
            rectx = future_rectx;
            recty = future_recty;
        }
    }

    // --- Triangle ---
    if (future_trix <= 1 || future_trix + TRI_HEIGHT >= 19)
        tdirx = -tdirx;
    if (future_triy <= 0 || future_triy + TRI_WIDTH >= 49)
        tdiry = -tdiry;
    else
    {
        if (collision_check(rectx, recty, future_trix, future_triy, cerx, cery, px, py, triangle, cercle))
        {
            tdirx = -tdirx;
            tdiry = -tdiry;
        }
        else
        {
            trix = future_trix;
            triy = future_triy;
        }
    }

    // --- Cercle ---
    if (future_cerx <= 1 || future_cerx + CER_HEIGHT >= 19)
        cdirx = -cdirx;
    if (future_cery <= 0 || future_cery + CER_WIDTH >= 50)
        cdiry = -cdiry;
    else
    {
        if (collision_check(rectx, recty, trix, triy, future_cerx, future_cery, px, py, triangle, cercle))
        {
            cdirx = -cdirx;
            cdiry = -cdiry;
        }
        else
        {
            cerx = future_cerx;
            cery = future_cery;
        }
    }

    // --- Point ---
    if (future_px <= 0 || future_px >= 19)
        pdirx = -pdirx;
    if (future_py <= 0 || future_py >= 49)
        pdiry = -pdiry;
    else
    {
        if (collision_check(rectx, recty, trix, triy, cerx, cery, future_px, future_py, triangle, cercle))
        {
            pdirx = -pdirx;
            pdiry = -pdiry;
        }
        else
        {
            px = future_px;
            py = future_py;
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

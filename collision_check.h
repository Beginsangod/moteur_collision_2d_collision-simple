#ifndef COLLISION_CHECK
#define COLLISION_CHECK

#include <iostream>

// Dimensions des formes
const int RECT_WIDTH = 6;
const int RECT_HEIGHT = 5;
const int TRI_WIDTH = 11;
const int TRI_HEIGHT = 5;
const int CER_WIDTH = 5;
const int CER_HEIGHT = 3;

// Fonction pour vérifier les collisions entre deux rectangles
bool rect_collision(int x1, int y1, int w1, int h1,int x2, int y2, int w2, int h2)
{
    return !(x1 + h1 <= x2 || x1 >= x2 + h2 || y1 + w1 <= y2 || y1 >= y2 + w2);
}

// Collision entre triangle et cercle
bool triangle_cercle_collision(int trix, int triy, char triangle[5][11], int cerx, int cery, char cercle[3][5])
{
    for (int i = 0; i < TRI_HEIGHT; i++)
    {
        for (int j = 0; j < TRI_WIDTH; j++)
        {
            if (triangle[i][j] == '*')
            {
                int tri_i = trix + i;
                int tri_j = triy + j;

                for (int m = 0; m < CER_HEIGHT; m++)
                {
                    for (int n = 0; n < CER_WIDTH; n++)
                    {
                        if (cercle[m][n] == '*')
                        {
                            int cer_i = cerx + m;
                            int cer_j = cery + n;

                            if (tri_i == cer_i && tri_j == cer_j)
                            {
                                return true; // Collision détectée
                            }
                        }
                    }
                }
            }
        }
    }
    return false; // Pas de collision
}

bool collision_check(int rectx, int recty,int trix, int triy,int cerx, int cery,int px, int py, char triangle[5][11], char cercle[3][5])
{
    // Collision entre rectangle et triangle
    if (rect_collision(rectx + 1, recty + 1, RECT_WIDTH, RECT_HEIGHT, trix + 1, triy + 1, TRI_WIDTH, TRI_HEIGHT))
        return true;

    // Collision entre rectangle et cercle
    if (rect_collision(rectx + 1, recty + 1, RECT_WIDTH, RECT_HEIGHT, cerx + 1, cery + 1, CER_WIDTH + 1, CER_HEIGHT + 1))
        return true;

    // Collision entre triangle et cercle
    if (triangle_cercle_collision(triy, trix, triangle, cery, cerx, cercle))
        return true;

    // Collision entre rectangle et point
    if (rectx <= px && px < rectx + RECT_HEIGHT && recty <= py && py < recty + RECT_WIDTH)
        return true;

    // Collision entre triangle et point
    if (trix <= px && px < trix + TRI_HEIGHT && triy <= py && py < triy + TRI_WIDTH)
        return true;

    // Collision entre cercle et point
    if (cerx <= px && px < cerx + CER_HEIGHT && cery <= py && py < cery + CER_WIDTH)
        return true;

    return false;
}

#endif

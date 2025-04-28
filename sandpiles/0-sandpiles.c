#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "sandpiles.h"


/**
 * print_grid - Print 3x3 grid
 * @grid: 3x3 grid
 *
 */
// static void print_grid(int grid[3][3])
// {
//     int i, j;

//     for (i = 0; i < 3; i++)
//     {
//         for (j = 0; j < 3; j++)
//         {
//             if (j)
//                 printf(" ");
//             printf("%d", grid[i][j]);
//         }
//         printf("\n");
//     }
// }


/**
 * stable - Verify if a grid is stable
 * @grid: 3x3 grid
 *
 * Return: True if grid is stable or False if not
 */
bool stable(int grid[3][3]) {
    int i, j;
    int verify;

    verify = grid[0][0];

    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
        {
            if (grid[i][j] != verify) {
                return (false);
            }
        }
    }

    return (true);
}


/**
 * sandpiles_sum - Computes the sum of two sandpiles
 * @grid1: 3x3 grid
 * @grid2: 3x3 grid
 *
 */
void sandpiles_sum(int grid1[3][3], int grid2[3][3]) {
    int i, j;

    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
        {
            grid1[i][j] = grid1[i][j] + grid2[i][j];
        }
    }

    if (stable(grid1) == false) {
        printf("=\n");
        print_grid(grid1);
        sandpiles_sum(grid1, grid2);
    }
}

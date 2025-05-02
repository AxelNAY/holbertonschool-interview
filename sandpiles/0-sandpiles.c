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
static void print_grid(int grid[3][3])
{
	int i, j;

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			if (j)
				printf(" ");
			printf("%d", grid[i][j]);
		}
		printf("\n");
	}
}


/**
 * verify - Verify if a grid is stable
 * @grid: 3x3 grid
 *
 * Return: True if grid is stable or False if not
 */
bool verify(int grid[3][3])
{
	int i, j, verif = 0;

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			if (grid[i][j] > 3)
			{
				verif = 1;
			}
		}
	}

	if (verif != 0)
	{
		printf("=\n");
		print_grid(grid);
		return (false);
	}

	return (true);
}


/**
 * stable - Modify grid
 * @grid: 3x3 grid
 */
void stable(int grid[3][3])
{
	int i, j;
	int new_grid[3][3];

	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
			new_grid[i][j] = grid[i][j];
	}

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			if (i + 1 != 3 && new_grid[i + 1][j] > 3)
				grid[i][j] += 1;
			if (j + 1 != 3 && new_grid[i][j + 1] > 3)
				grid[i][j] += 1;

			if (new_grid[i][j] > 3)
			{
				if (i + 1 != 3)
					grid[i + 1][j] += 1;
				if (j + 1 != 3)
					grid[i][j + 1] += 1;
				grid[i][j] -= 4;
			}
		}
	}

	if (verify(grid) == false)
		stable(grid);
}


/**
 * sandpiles_sum - Computes the sum of two sandpiles
 * @grid1: 3x3 grid
 * @grid2: 3x3 grid
 *
 */
void sandpiles_sum(int grid1[3][3], int grid2[3][3])
{
	int i, j;

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
			grid1[i][j] = grid1[i][j] + grid2[i][j];
	}

	if (verify(grid1) == false)
		stable(grid1);
}

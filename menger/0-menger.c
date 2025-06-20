#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "menger.h"

/**
 * menger - draws a 2D Menger Sponge
 * @level: level of the Menger Sponge to draw
 */
void menger(int level)
{
	if (level < 0)
	{
		return;
	}
	int size = pow(3, level);
	char character;

	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			character = '#';

			int row = i;
			int col = j;

			while (row || col)
			{
				if (row % 3 == 1 && col % 3 == 1)
				{
					character = ' ';
					break;
				}
				row /= 3;
				col /= 3;
			}
			printf("%c", character);
		}
		printf("\n");
	}
}

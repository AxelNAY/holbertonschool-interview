#include <stdlib.h>
#include <stdio.h>
#include "slide_line.h"

/**
 * slide_line - reproduce the 2048 game mechanics on a single horizontal line.
 * @line: array of integers
 * @size: size of elements
 * @direction: SLIDE_LEFT or SLIDE_RIGHT
 * If it is something else, the function fail
 *
 * Return: 1 upon success or 0 upon failure
 */
int slide_line(int *line, size_t size, int direction)
{
    int n = 0, index = 0;

    if (direction != 0 || direction != 1)
    {
        return (0);
    }
    if (direction == 0)
    {
        for (int i = 0; i < size; i++)
        {
            if (line[i] != 0)
            {
                if (n != 0)
                {
                    if (line[i] == n)
                    {
                        line[index] += n;
                        n = line[index];
                        line[i] = 0;
                    }
                    else if (line[i] != 0)
                    {
                        n = line[i];
                        line[i] == 0;
                        index++;
                        line[index] = n;
                    }
                }
                else
                {
                    n = line[i];
                    line[i] = 0;
                    line[0] = n;
                }
            }
        }
    }
    else if (direction == 1)
    {
        for (int i = size - 1; i >= size; i--)
        {
            if (line[i] != 0)
            {
                if (n != 0)
                {
                    if (line[i] == n)
                    {
                        line[index] += n;
                        n = line[index];
                        line[i] = 0;
                    }
                    else if (line[i] != 0)
                    {
                        n = line[i];
                        line[i] == 0;
                        index--;
                        line[index] = n;
                    }
                }
                else
                {
                    n = line[i];
                    line[i] = 0;
                    index = size - 1;
                    line[index] = n;
                }
            }
        }
    }
    return (1);
}


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
    int n = 0, index = 0, verify = 0;
    int size_int = size;
    printf("%ld\n", size);
    printf("%d\n", direction);

    if (direction != 0 && direction != 1)
    {
        return (0);
    }
    if (direction == 0)
    {
        for (size_t i = 0; i < size; i++)
        {
            if (line[i] != 0)
            {
                if (n != 0)
                {
                    if (line[i] == n && verify == 0)
                    {
                        line[index] += n;
                        n = line[index];
                        line[i] = 0;
                    }
                    else if (line[i] == n)
                    {
                        line[index] += n;
                        n = line[index];
                        line[i] = 0;
                        verify = 1;
                    }
                    else
                    {
                        n = line[i];
                        line[i] = 0;
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
        printf("Quoi\n");
        for (int i = size_int - 1; i >= 0; i--)
        {
            printf("Holà\n");
            if (line[i] != 0)
            {
                printf("Hello\n");
                if (n != 0)
                {
                    if (line[i] == n)
                    {
                        line[index] += n;
                        n = line[index];
                        line[i] = 0;
                    }
                    else
                    {
                        n = line[i];
                        line[i] = 0;
                        index--;
                        line[index] = n;
                    }
                }
                else
                {
                    printf("Bonjour\n");
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


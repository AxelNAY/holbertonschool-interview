#ifndef SANDPILES_H
#define SANDPILES_H

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>

static void print_grid_sum(int grid1[3][3], int grid2[3][3]);
static void print_grid(int grid[3][3]);
void sandpiles_sum(int grid1[3][3], int grid2[3][3]);
bool stable(int grid[3][3]);

#endif /* SANDPILES_H */

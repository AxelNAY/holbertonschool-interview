#!/usr/bin/python3
"""File containing the function island_perimeter"""


def island_perimeter(grid):
    if not grid:
        return 0

    count = 0
    n = len(grid)
    m = len(grid[0])
    for i in range(n):
        for j in range(m):
            if grid[i][j] == 1:
                if i > 0 and grid[i-1][j] == 0:
                    count += 1
                if i < n - 1 and grid[i+1][j] == 0:
                    count += 1
                if j > 0 and grid[i][j-1] == 0:
                    count += 1
                if j < m - 1 and grid[i][j+1] == 0:
                    count += 1
    return count

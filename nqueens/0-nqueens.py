#!/usr/bin/python3

import sys


def is_safe(positions, row, col):
    """Check if placing a queen at (row, col) conflicts with existing queens"""
    for queen_row, queen_col in positions:
        if queen_row == row or queen_col == col:
            return False
        if abs(queen_row - row) == abs(queen_col - col):
            return False
    return True


def solve_nqueens(n, positions, row):
    """Recursive backtracking function to solve N Queens"""
    if row == n:
        print(positions[:])
        return

    for col in range(n):
        if is_safe(positions, row, col):
            positions.append([row, col])
            solve_nqueens(n, positions, row + 1)
            positions.pop()


def main():
    if len(sys.argv) != 2:
        print("Usage: nqueens N")
        sys.exit(1)

    try:
        n = int(sys.argv[1])
    except ValueError:
        print("N must be a number")
        sys.exit(1)

    if n < 4:
        print("N must be at least 4")
        sys.exit(1)

    positions = []
    solve_nqueens(n, positions, 0)


if __name__ == "__main__":
    main()

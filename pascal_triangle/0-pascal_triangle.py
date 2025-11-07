#!/usr/bin/python3
"""Contain the function pascal_triangle."""


def factorial_recursive(n):
    if n == 0 or n == 1:
        return 1
    return n * factorial_recursive(n - 1)


def pascal_triangle(n):
    """Returns a list of lists of integers
    representing the Pascal’s triangle of n"""
    triangle = []
    if (n <= 0):
        return triangle

    for i in range(n):
        row = []
        for j in range(i+1):
            row.append(factorial_recursive(i) //
                       (factorial_recursive(j)*factorial_recursive(i-j)))
        triangle.append(row)

    return triangle

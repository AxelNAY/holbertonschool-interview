#!/usr/bin/python3
"""Calculates the fewest number of operations needed
to result in exactly n H characters"""


def minOperations(n):
    letter = "H"
    characters = [letter]
    copy = 1
    operation = 0
    i = 0

    if n <= 0:
        return (0)
    if n == 1:
        return (1)

    if n % 5 == 0:
        operation = operation + 5
        copy = 4
        while (i < copy):
            characters.append(letter)
            i = i + 1
    elif n % 3 == 0:
        operation = operation + 3
        copy = 2
        while (i < copy):
            characters.append(letter)
            i = i + 1
    elif n % 2 == 0:
        operation = operation + 2
        copy = 1
        while (i < copy):
            characters.append(letter)
            i = i + 1

    if operation != 0:
        while len(characters) != n:
            i = 0
            if n % len(characters) == 0:
                operation = operation + 2
                copy = len(characters)
            else:
                operation = operation + 1
            while (i < copy):
                characters.append(letter)
                i = i + 1
    else:
        operation = 1
        while len(characters) != n:
            operation = operation + 1
            characters.append(letter)

    return (operation)

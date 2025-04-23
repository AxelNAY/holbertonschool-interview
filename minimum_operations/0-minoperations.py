#!/usr/bin/python3


def minOperations(n):
    letter = "H"
    characters = [letter]
    copy = 1
    operation = -1
    count = 0

    if n <= 0:
        return (0)

    while (len(characters) < n):
        i = 0
        if count % 2 == 0:
            copy = len(characters)
            operation = operation + 2
        else:
            operation = operation + 1
        while (i < copy):
            characters.append(letter)
            i = i + 1
        count = count + 1

    return (operation)

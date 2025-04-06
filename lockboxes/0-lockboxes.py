#!/usr/bin/python3
"""Write a method that determines if all the boxes can be opened."""


def canUnlockAll(boxes):
    """Prototype: def canUnlockAll(boxes)
    boxes is a list of lists
    A key with the same number as a box opens that box
    You can assume all keys will be positive integers
    There can be keys that do not have boxes
    The first box boxes[0] is unlocked
    Return True if all boxes can be opened, else return False"""
    compare = [0]

    for i in compare:
        for j in boxes[i]:
            if (j not in compare and j != 0 and j < len(boxes)):
                compare.append(j)

    if len(compare) != len(boxes):
        return False
    return True

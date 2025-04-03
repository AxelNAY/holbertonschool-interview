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
    if boxes[0] == 0:
        return True
    for i in range(len(boxes) - 1):
        if len(boxes[i]) == 0:
            return False
    return True
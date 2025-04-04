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
    verify = 0
    compare = [0]
    for i in range(len(boxes) - 1):
        if len(boxes[i]) == 0:
                return False
        for j in range (len(boxes[i])):
            if boxes[i][j] <= len(boxes):
                for k in range (len(compare)):
                    if boxes[i][j] == compare[k]:
                        verify = 1
                if verify == 0:
                    compare.append(boxes[i][j])
                verify = 0
    if len(compare) != len(boxes):
        return False
    return True
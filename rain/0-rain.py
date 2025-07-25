#!/usr/bin/python3
"""
Given a list of non-negative integers representing
the heights of walls with unit width 1,
as if viewing the cross-section of a relief map,
calculate how many square units of water will be retained after it rains.
"""


def rain(walls):
    """
    Calculate how many square units of water will be retained after it rains.
    @walls: list of non-negative integers
    Return: Integer indicating total amount of rainwater retained
    or 0 if walls is empty
    """
    if not walls:
        return 0

    result = 0

    for i in range(1, len(walls) - 1):
        left_max = walls[i]
        right_max = walls[i]

        for j in range(i):
            left_max = max(left_max, walls[j])

        for j in range(i + 1, len(walls)):
            right_max = max(right_max, walls[j])

        result += min(left_max, right_max) - walls[i]

    return result

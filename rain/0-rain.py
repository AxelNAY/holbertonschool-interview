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
    left_wall = 0
    count = 0
    result = 0
    if len(walls) < 1:
        return 0

    for wall in walls:
        if wall == 0:
            count += 1
        else:
            if left_wall == 0:
                left_wall = wall
            elif left_wall < wall:
                result += left_wall * count
                left_wall = wall
            elif left_wall > wall:
                result += wall * count
                left_wall = wall
            count = 0

    return result

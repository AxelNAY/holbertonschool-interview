#!/usr/bin/python3
"""Calculates the fewest number of operations needed
to result in exactly n H characters"""


def minOperations(n):
    operation = 0

    if n <= 1:
        return (0)

    operation = 0
    factor = 2

    while n > 1:
        while n % factor == 0:
            operation += factor
            n //= factor
        factor += 1

    return (operation)

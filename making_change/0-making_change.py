#!/usr/bin/python3
"""File containing the function makeChange(coins, total)."""


def makeChange(coins, total):
    """
        Determines the fewest number of coins needed to meet a given amount
        total.

        Args:
            coins (list): a list of coins of different values.
            total (int): the target amount.

        Returns:
            fewest number of coins needed to meet total.
            If total is 0 or less, return 0.
            If total cannot be met by any number of coins you have, return -1.
    """
    if total <= 0:
        return 0
    if not coins:
        return -1

    dp = [total + 1] * (total + 1)
    dp[0] = 0

    for amt in range(1, total + 1):
        for coin in coins:
            if coin <= amt:
                dp[amt] = min(dp[amt], dp[amt - coin] + 1)

    return dp[total] if dp[total] <= total else -1

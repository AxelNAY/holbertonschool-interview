#!/usr/bin/python3
"""File containing isWinner function"""


def prime(num):
    """Create a list of prime number"""
    if num < 2:
        return []
    primes = []
    for n in range(2, num + 1):
        is_prime = True
        for p in range(2, int(n**0.5) + 1):
            if n % p == 0:
                is_prime = False
                break
        if is_prime:
            primes.append(n)
    return primes


def isWinner(x, nums):
    """Determine who the winner of each game is"""
    if x < 1:
        return None
    M = 0
    B = 0
    for num in nums:
        prime_nums = prime(num)
        if len(prime_nums) % 2 == 0:
            B += 1
        elif len(prime_nums) % 2 != 0:
            M += 1
    if M > B:
        return ("Maria")
    elif M < B:
        return ("Ben")
    else:
        return None

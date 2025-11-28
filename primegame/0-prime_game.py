#!/usr/bin/python3
def prime(num):
    """Create a list of prime number"""
    if num < 2:
        return []
    prime_nums = [True] * (num + 1)
    prime_nums[0] = prime_nums[1] = False

    for i in range(2, int(num**0.5) + 1):
        if prime_nums[i]:
            for j in range(i * i, num + 1, i):
                prime_nums[j] = False

    return prime_nums


def isWinner(x, nums):
    """Determine who the winner of each game is"""
    if x < 1 or not nums:
        return None

    max_n = max(nums)
    prime_nums = prime(max_n)

    prime_count = [0] * (max_n + 1)
    count = 0

    for i in range(2, max_n + 1):
        if prime_nums[i]:
            count += 1
        prime_count[i] = count

    M = 0
    B = 0

    for n in nums:
        if prime_count[n] % 2 == 0:
            B += 1
        else:
            M += 1

    if M > B:
        return "Maria"
    if B > M:
        return "Ben"
    return None

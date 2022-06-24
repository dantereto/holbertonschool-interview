#!/usr/bin/python3
"""create the function"""


def makeChange(coins, total):
    """comment"""
    if total <= 0:
        return 0
    if not coins or min(coins) > total:
        return -1
    num_coins = 0
    coins.sort(reverse=True)
    i = 0
    while i < len(coins):
        if coins[i] <= total:
            num_coins += total // coins[i]
            total = total % coins[i]
        i += 1
    if total == 0:
        return num_coins
    else:
        return -1

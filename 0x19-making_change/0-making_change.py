#!/usr/bin/python3
"""create the function"""


def makeChange(coins, total):
    """comment"""
    if total <= 0:
        return 0
    coins.sort(reverse=True)
    copy = total
    mv = 0
    cont = 0

    while (mv < len(coins)):
        if copy == 0:
            return cont

        if coins[mv] > copy:
            mv += 1

        else:
            copy -= coins[mv]
            cont += 1
    return -1

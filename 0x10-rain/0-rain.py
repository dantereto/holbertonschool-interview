#!/usr/bin/python3
"""comment"""


def rain(walls):
    """ lockcoxes"""
    left = 0
    i = 0
    right = 0
    water = 0
    j = len(walls) - 1
    while i < j:
        if walls[i] < walls[j]:
            if walls[i] < left:
                water += left - walls[i]
            left = max(left, walls[i])
            i += 1
        else:
            if walls[j] < right:
                water += right - walls[j]
            right = max(right, walls[j])
            j -= 1
    return water

#!/usr/bin/python3
"""
function
"""


def minOperations(n):
    """
    funcion
    """

    if (not isinstance(n, int)):
        return 0

    cont = 0
    i = 2
    while i <= n:
        if n % i == 0:
            cont += i
            n = n / i
            i = i - 1
        i = i + 1
    return int(cont)

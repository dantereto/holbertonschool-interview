#!/usr/bin/python3
"""Function"""


def pascal_triangle(n):
    if n <= 0:
        return []
    lst = [1]
    res = list()

    for i in range(n):
        res.append(lst)
        mylist = []
        mylist.append(lst[0])
        for j in range(len(lst)-1):
            mylist.append(lst[j]+lst[j+1])
        mylist.append(1)
        lst = mylist

    return res

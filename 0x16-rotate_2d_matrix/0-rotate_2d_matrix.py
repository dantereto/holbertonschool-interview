#!/usr/bin/python3
"""
Function
"""

from unittest import result


def rotate_2d_matrix(matrix):
    copy = matrix[:]
    for i in range(len(matrix)):
        result = [row[i] for row in copy]
        matrix[i] = result[::-1]

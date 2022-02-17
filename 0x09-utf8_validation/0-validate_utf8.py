#!/usr/bin/python3
"""
Valid utf
"""


def validUTF8(data):
    """start function"""

    number = 0
    for n in data:
        byte = format(n, '#010b')[-8:]
        if number == 0:
            if byte[0] == '1':
                number = len(byte.split('0')[0])
            if number > 4 or number == 1:
                return False
            if number == 0:
                continue
        else:
            if not byte.startswith('10'):
                return False
        number -= 1
    if number != 0:
        return False
    return True

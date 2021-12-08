#!/usr/bin/python3

def canUnlockAll(boxes):
    """ lockcoxes"""
    if (not boxes or len(boxes) == 0):
        return False
    keys = []
    keys.append(0)
    for key in keys:
        news = boxes[key]
        for new in news:
            if new not in keys and new < len(boxes):
                keys.append(new)
    if len(keys) == len(boxes):
        return True
    else:
        return False
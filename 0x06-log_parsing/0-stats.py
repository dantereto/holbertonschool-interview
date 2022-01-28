#!/usr/bin/python3
"""create the function"""

import sys


i = 0
size = 0
status = {'200' : 0, '301' : 0, '400' : 0, '401' : 0,
          '403' : 0, '404' : 0, '405' : 0, '500' : 0}
codes = ['200', '301', '400', '401', '403', '404', '405', '500']
try:
    for line in sys.stdin:
        i += 1
        space = line.split(' ')
        if len(space) > 2:
            size += int(space[-1])
            if space[-2] in status:
                status[space[-2]] += 1
        if i % 10 == 0:
            print("File size: {}".format(size))
            for code in codes:
                if status[code]:
                    print("{}: {}".format(code, status[code]))
except KeyboardInterrupt:
    pass
finally:
    print("File size: {}".format(size))
    for code in codes:
        if status[code]:
            print("{}: {}".format(code, status[code]))
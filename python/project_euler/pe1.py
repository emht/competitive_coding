#!/bin/python3

import sys

cases = int(input())
for i in range(cases):
    n = int(input())
    n =- 1
    count_3 = n / 3
    count_5 = n / 5
    count_15 = n / 15

    count_3 = count_3 * (count_3 + 1) / 2
    count_5 = count_5 * (count_5 + 1) / 2
    count_15 = count_15 * (count_15 + 1) / 2
    res = (3 * count_3 + 5 * count_5) - (15 * count_15)
    print(res)


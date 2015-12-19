#-*- encoding: utf-8 -*-
def maxProfit(stockprice):
    length= len(stockprice)
    if length == 0:
        return 0
    left = [0 for i in range(length)]
    right = left[:]

    minl = stockprice[0]
    for i in range(1,length):
        minl = min(minl, stockprice[i])
        left[i] = max(left[i-1], stockprice[i] - minl)

    maxr = stockprice[-1]
    i = length - 2
    while i >= 0:
        maxr = max(maxr, stockprice[i])
        right[i] = max(right[i+1], maxr - stockprice[i])
        i -= 1

    print left, right
    s = 0
    for i in range(length):
        s = max(s, left[i] + right[i])
    return s
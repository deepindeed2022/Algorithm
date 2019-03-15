#-*- encoding: utf-8 -*-
import sys

if __name__ == "__main__":
    # 读取第一行的n
    # n = int(sys.stdin.readline().strip())

    # line = sys.stdin.readline().strip()
    # # 把每一行的数字分隔后转化成int列表
    # values = map(int, line.split(' ', n))
    n = 5
    values = [1, 2, 3, 4, 5]

    b = []
    j = []
    o = []
    for i in xrange(len(values)):
        if i % 2 == 0:
            o.append(values[i])
        else:
            j.append(values[i])
    o = o[::-1]
    b = o + j
    if len(values) % 2 == 0:
        b = b[::-1]
    # for i in range(n):
    #     if i % 2 == 0:
    #         b = b + [values[i]]
    #     else:
    #         b = [values[i]] + b
    # if n % 2 == 1:
    #     b = b[::-1]
    print " ".join(map(str, b))
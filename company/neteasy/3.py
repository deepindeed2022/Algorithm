#-*- encoding: utf-8 -*-
import sys

if __name__ == "__main__":
    # 读取第一行的n
    n = int(sys.stdin.readline().strip())

    line = sys.stdin.readline().strip()
    # 把每一行的数字分隔后转化成int列表
    values = map(int, line.split(' ', n))
    # n = 5
    # values = [25,10,40,5, 25]

    s_values = sorted(values)
    b_values = sorted(values, reverse=True)
    l = len(s_values)
    tm_result = zip(s_values, b_values)
    result = []
    flag = True
    for i in tm_result[:l/2]:
        if flag:
            result = [i[0]] + result + [i[1]]
            flag = False
        else:
            result = [i[1]] + result + [i[0]]
            flag = True

    if l%2 == 1:
        if flag:
            result = result + [tm_result[l/2+1][0]]
        else:
            result = [tm_result[l/2+1][0]] + result

    max_val = 0
    for i in xrange(l - 1):
        max_val += abs(result[i] - result[i+1])
    print max_val
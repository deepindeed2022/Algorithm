# -*- coding:utf-8 -*-
class Solution:
    # array 二维列表
    def Find(self, target, array):
        # write code here
        if len(array) == 0:
            return False
        line_sz = len(array[0])
        col_sz = len(array)
        i = 0
        j = col_sz - 1
        while i < line_sz and j >= 0:
            if array[j][i] == target:
                return True
            if array[j][i] > target:
                j = j - 1
            else:
                i += 1
        return False
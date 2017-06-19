# -*- coding:utf-8 -*-
class Solution:
    def __init__(self):
        self.stack1 = []
        self.stack2 = []
        
    def push(self, node):
        # write code here
        self.stack1.append(node)
    def pop(self):
        # return xx
        if self.stack2:
            return self.stack2.pop()
        elif not self.stack1:
            return None
        else:
            while self.stack1:
                self.stack2.append(self.stack1.pop())
            return self.stack2.pop()
def test_pop_push():
    solve = Solution()
    for i in xrange(1, 10):
        solve.push(i)
    print solve.pop()
    print solve.pop()

if __name__ == '__main__':
    test_pop_push()
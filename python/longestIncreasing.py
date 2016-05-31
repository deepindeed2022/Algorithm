class Solution(object):
    def longestIncreasingPath(self, matrix):
        """
        :type matrix: List[List[int]]
        :rtype: int
        """
        def dfs(i, j):
            if not dp[i][j]:
                val = matrix[i][j]
                dp[i][j] = 1 + max(
                dfs(i-1, j) if i and val > matrix[i-1][j] else 0,
                dfs(i+1, j) if i < M - 1 and val > matrix[i+1][j] else 0,
                dfs(i, j-1) if j  and val > matrix[i][j-1] else 0,
                dfs(i, j+1) if j < N - 1 and val > matrix[i][j+1] else 0)
            return dp[i][j]

        if not matrix or not matrix[0]: return 0
        M, N = len(matrix),len(matrix[0])
        dp = [[0]*N for i in range(M)]
        return max(dfs(x,y) for x in range(M) for y in range(N))
matrix = [
  [3,4,5],
  [3,2,6],
  [2,2,1]
]
s = Solution()
print s.longestIncreasingPath(matrix)
matrix = [
  [9,9,4],
  [6,6,8],
  [2,1,1]
]
s = Solution()
print s.longestIncreasingPath(matrix)
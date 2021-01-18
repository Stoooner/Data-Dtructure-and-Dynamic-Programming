class Solution:
    """
    @param m: positive integer (1 <= m <= 100)
    @param n: positive integer (1 <= n <= 100)
    @return: An integer
    """
    def uniquePaths(self, m, n):
        # write your code here
        if m == 0 or n == 0:
            return -1
        # 初始化一个多维数组的正确方式：
        f = [[0 for j in range(n)] for i in range(2)]
        old = now = 0
        # 下面这种方式不对，因为*m只是把对象的引用复制了m次, 因此f[0][0]修改时，f[i][0]也会更改
        # f = [[0]*n]*m
        for i in range(m):
            old = now
            now = 1 - now
            for j in range(n):
                if i == 0 or j == 0:
                    f[now][j] = 1
                else:
                    f[now][j] = f[old][j] + f[now][j-1]
        return f[now][n-1]

if __name__ == '__main__':
    s = Solution()
    m, n = 3, 3
    result = s.uniquePaths(m, n)
    print("result = ", result)
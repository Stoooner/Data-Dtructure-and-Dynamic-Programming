class Solution:
    """
    @param n: An integer
    @return: An integer
    """
    def climbStairs(self, n):
        # write your code here
        if n == 0:
            return 0
        f = [0 for i in range(n+1)]
        f[0] = 1
        f[1] = 1
        for i in range(2, n+1):
            # 状态转移方程
            f[i] = f[i-1] + f[i-2]
        return f[n]

if __name__ == "__main__":
    n = 3
    print("result = ", Solution().climbStairs(n))

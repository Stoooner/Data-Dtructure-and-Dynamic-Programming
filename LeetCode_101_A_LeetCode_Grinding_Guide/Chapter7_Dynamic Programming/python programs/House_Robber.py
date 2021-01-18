class Solution:
    """
    @param A: An array of non-negative integers
    @return: The maximum amount of money you can rob tonight
    """
    def houseRobber(self, A):
        n = len(A)
        if n == 0:
            return 0
        if n == 1:
            return A[0]
        
        f = [0 for i in range(n+1)]

        # 方法1：普通方式
        # f[n] = 0
        # f[1] = A[0]
        # for i in range(2, n+1):
        #     f[i] = max(f[i-1], f[i-2]+A[i-1])
        # return f[n]

        # 方法2：滚动变量
        old, now = 0, A[0]
        for i in range(2, n+1):
            temp = max(now, old+A[i-1])
            old, now = now, temp
        return now

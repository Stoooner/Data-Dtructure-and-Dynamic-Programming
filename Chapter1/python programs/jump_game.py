class Solution:
    """
    @param A: A list of integers
    @return: A boolean
    """
    def canJump(self, A):
        # write your code here
        n = len(A)
        if n == 0:
            return False
        f = [False]*n
        f[0] = True
        for j in range(1, n):
            for i in range(0, j):
                if f[i] and i + A[i] >= j:
                    f[j] = True
        return f[n-1]

if __name__ == '__main__':
    A1 = [2,3,1,1,4]
    A2 = [3,2,1,0,4]
    s = Solution()
    result = s.canJump(A2)
    print("result: ", result)
class Solution:
    """
    @param nums: An array of integers
    @return: An integer
    """
    def maxProduct(self, nums):
        # write your code here
        n = len(nums)
        if n == 0:
            return -1
        f = [0] * n
        g = [0] * n
        result = float("-inf")
        for i in range(n):
            f[i] = nums[i]
            if i > 0:
                f[i] = max(f[i], max(nums[i]*f[i-1], nums[i]*g[i-1]))
            
            g[i] = nums[i]
            if i > 0:
                g[i] = min(g[i], min(nums[i]*f[i-1], nums[i]*g[i-1]))
            
            result = max(result, f[i])
        return result

if __name__ == '__main__':
    s = Solution()
    nums = [-1,2,4,1]
    result = s.maxProduct(nums)
    print("result: ", result)
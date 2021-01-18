class Solution:
    """
    @param nums: An array of integers
    @return: An integer
    """
    def maxProduct(self, nums):
        n = len(nums)
        if n == 0:
            return -1
        f = [0 for i in range(n)]
        g = [0 for j in range(n)]
        result = float("-inf")
        for j in range(n):
            f[j] = g[j] = nums[j]
            if j > 0:
                f[j] = max(f[j], max(f[j-1]*nums[j], g[j-1]*nums[j]))
                g[j] = min(g[j], min(g[j-1]*nums[j], f[j-1]*nums[j]))

            result = max(result, f[j])
        return result
            


if __name__ == "__main__":
    nums = [2,3,-2,4]
    print("result = ", Solution().maxProduct(nums))
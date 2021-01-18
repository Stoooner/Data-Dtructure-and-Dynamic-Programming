class Solution:
    """
    @param coins: a list of integer
    @param amount: a total amount of money amount
    @return: the fewest number of coins that you need to make up
    """
    def coinChange(self, coins, amount):
        n = len(coins)
        if n == 0:
            return -1
        f = [0 for i in range(amount+1)]
        pi = [[0 for j in range(3)] for i in range(amount+1)]
        for i in range(1, amount+1):
            f[i] = float("inf") # 首先设定f[i]是拼不出来的
            for j in range(n):
                # 转移方程：f[x] = min{f[x-2]+1, f[x-5]+1, f[x-7]+1}
                if i >= coins[j] and f[i-coins[j]] != float("inf"):
                    f[i] = min(f[i], f[i-coins[j]] + 1)

        return f[amount] if f[amount] != float("inf") else -1
        
if __name__ == '__main__':
    coins = [2, 5, 7]
    amount = 27
    s = Solution()
    result = s.coinChange(coins, amount)
    print("[result] = ", result)
    # 7 + 5 + 5 + 5 + 5 = 27
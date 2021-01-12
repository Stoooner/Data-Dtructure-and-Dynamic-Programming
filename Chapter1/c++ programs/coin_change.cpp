// 求最大最小型动态规划
#include<iostream>
#include<string>
#include<vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    /**
     * @param coins: a list of integer
     * @param amount: a total amount of money amount
     * @return: the fewest number of coins that you need to make up
     */
    int coinChange(vector<int> &coins, int amount) {
        // 获取硬币列表的长度
        int n = coins.size();
        // 数组的长度开辟为amount+1是因为从0遍历到amount
        int f[amount+1];
        // 初始化条件
        f[0] = 0;
        for (int i = 1; i <= amount; i++){
            // 首先要将f[i]值设定为无穷大，也即边界条件
            f[i] = INT_MAX;
            // 选择最后一枚硬币的面值
            for (int j = 0; j < n; j++){
                // i >= coins[j]代表现在的面值要大于硬币列表中各个硬币的面值
                // f[i-coins[j]]+1 < f[i]代表如果f[i-coins[j]]+1的数额更小的话则执行if中的内容
                // 也即更新f[i]所需的硬币数
                // 方式1：
                // if (i >= coins[j] && f[i-coins[j]]+1 < f[i] && f[i-coins[j]] != INT_MAX){
                //     f[i] = f[i-coins[j]]+1;
                // }
                // 方式2：
                if (i>=coins[j] && f[i-coins[j]] != INT_MAX){
                    f[i] = min(f[i], f[i-coins[j]]+1);
                }
            }
        }

        if (f[amount] == INT_MAX){
            return -1;
        }
        else{
            return f[amount];
        }
    }
};

int main(){
    Solution s;
    vector<int> coins;
    coins.push_back(2);
    coins.push_back(5);
    coins.push_back(7);
    int amount = 27;
    int result = s.coinChange(coins, amount);
    cout << "result = " << result << endl;
}
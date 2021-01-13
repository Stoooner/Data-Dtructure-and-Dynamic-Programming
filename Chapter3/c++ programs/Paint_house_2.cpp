#include<iostream>
#include<string>
#include<vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    /**
     * @param costs: n x k cost matrix
     * @return: an integer, the minimum cost to paint all houses
     */
    int minCostII(vector<vector<int>> &costs) {
        // write your code here
        // 状态转移方程：f[i][j] = min_{k!=j}{f[i-1][k]} + cost[i-1][j]
        // K的数目大了以后，通过循环的方式每次求得最小值的复杂度会很大，因此：
        // 如果最小值是第i个元素，次小值是第j个元素：
        //      1. 只要除掉的元素不是第i个元素，那么剩下的最小值就是第i个元素；
        //      2. 如果除掉的元素是第i个元素，剩下的最小值就是第j个元素；
        int n = costs.size();
        if (n == 0){
            return 0;
        }
        int K = costs[0].size();
        int f[n+1][K];
        int i, j, k;
        int min_1, min_2;// 分别代表最小值和次小值
        int id1=0, id2=0; // 指示最小值和次小值的位置
        // 首先初始化
        for (i=0;i<K;i++){
            f[0][i] = 0;
        }

        // 前1栋房子到前n栋房子, 先求出最小值和次小值
        for (i=1;i<=n;i++){
            min_1 = min_2 = INT_MAX;
            // 第一个for循环先求出当前在前i栋房子情况下，前i-1栋房子中的最小值和次小值
            for (j=0;j<K;j++){
                // 先看f[i-1][j]是否比当前最小值还小，如果是，则：
                if (f[i-1][j] < min_1) {
                    min_2 = min_1;
                    id2 = id1;
                    min_1 = f[i-1][j];
                    id1 = j;
                }
                else{
                    // 再看f[i-1][j]是否比当前次小值还小
                    if (f[i-1][j] < min_2){
                        min_2 = f[i-1][j];
                        id2 = j;
                    }
                }
            }

            // 第二个for循环在求得了前i-1栋房子中的最小值和次小值情况下求前i栋房子最小值
            for (j=0;j<K;j++){
                f[i][j] = costs[i-1][j];
                // 如果当前位置j不是最小值
                if (j != id1){
                    f[i][j] += min_1;
                }
                else{
                    f[i][j] += min_2;
                }
            }
        }
        int result = INT_MAX;
        // 由于不知道K中颜色中到底哪个颜色对于的花费最小，因此枚举一下
        for (i=0;i<K;i++){
            result = min(result, f[n][i]);
        }
        return result;
    }
};
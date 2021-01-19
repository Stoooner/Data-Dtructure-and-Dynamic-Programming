#include<iostream>
#include<string>
#include<vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    /**
     * @param prices: Given an integer array
     * @return: Maximum profit
     * f[i][j]: 前i天(第i-1天)结束后，处于阶段j, 最大获利
     * 阶段1， 3， 5：f[i][j] = max{f[i-1][j], f[i-1][j-1]+(P_(i-1) - P_(i-2))}
     * 阶段2, 4: f[i][j] = max{f[i-1][j]+(P_(i-1) - P_(i-2), f[i-1][j-1]}
     * 需要注意的是：天数i是从第0天开始的，所以需要注意i-2<0的情况不被考虑；
     * 相应的：阶段j是从1开始计算的，因此j-1<1也是不被考虑的
     * result = max{f[N][1], f[N][3], f[N][5]}，即清仓状态下最后一天的最大获利
     * 另外需要注意的是初始化时：f[0][2] = f[0][3] = f[0][4] = f[0][5] = -∞
     * 因为它代表前0天的时候它不能处于阶段2/3/4/5，所以使用负无穷表示
     */
    int maxProfit_3(vector<int> &prices) {
        // write your code here
        int n = prices.size();
        if (n == 0){
            return 0;
        }
        int f[n+1][5+1];
        int i, j;

        // initialization
        f[0][1] = 0;
        for (i=2;i<=5;i++){
            f[0][i] = INT_MIN;
        }

        for (i=1;i<=n;i++){
            // 阶段1， 3， 5
            for(j=1;j<=5;j+=2){
                // 阶段1， 3， 5：f[i][j] = max{f[i-1][j], f[i-1][j-1]+(P_(i-1) - P_(i-2))}
                f[i][j] = f[i-1][j];
                if (j>1 && i>=2 && f[i-1][j-1]!=INT_MIN){
                    f[i][j] = max(f[i][j], f[i-1][j-1]+(prices[i-1]-prices[i-2]));
                }
            }

            // 阶段2， 4
            for(j=2;j<=5;j+=2){
                // 阶段2, 4: f[i][j] = max{f[i-1][j]+(P_(i-1) - P_(i-2), f[i-1][j-1]}
                f[i][j] = f[i-1][j-1];
                if (i>=2 && f[i-1][j]!=INT_MIN){
                    f[i][j] = max(f[i][j], f[i-1][j]+(prices[i-1]-prices[i-2]));
                }
            }
        }

        return max(f[n][1], max(f[n][3], f[n][5]));
    }
};
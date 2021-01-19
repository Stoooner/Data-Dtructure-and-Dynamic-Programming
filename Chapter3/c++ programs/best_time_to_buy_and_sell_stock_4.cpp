#include<iostream>
#include<string>
#include<vector>
#include <algorithm>
using namespace std;

// 方法1：普通方式
/*
class Solution {
public:
    int maxProfit_4(int K, vector<int> &prices) {
        int n = prices.size();
        if (n == 0){
            return 0;
        }
        
        int i, j;
        if (K > n/2){
            // best time to buy and sell stock II
            // buy and sell any time
            int sum = 0;
            for (i=0;i<n-1;i++){
                if (prices[i+1] > prices[i]){
                    sum += (prices[i+1] - prices[i]);
                }
            }
            return sum;
        }

        int f[n+1][2*K+2];
        // initialization
        f[0][1] = 0;
        for (i=2;i<=2*K+1;i++){
            f[0][i] = INT_MIN;
        }

        for (i=1;i<=n;i++){
            // 阶段1， 3， 5, ..., 2K+1
            for(j=1;j<=2*K+1;j+=2){
                // 阶段1， 3， 5：f[i][j] = max{f[i-1][j], f[i-1][j-1]+(P_(i-1) - P_(i-2))}
                f[i][j] = f[i-1][j];
                if (j>1 && i>=2 && f[i-1][j-1]!=INT_MIN){
                    f[i][j] = max(f[i][j], f[i-1][j-1]+(prices[i-1]-prices[i-2]));
                }
            }

            // 阶段2， 4, ..., 2K
            for(j=2;j<=2*K;j+=2){
                // 阶段2, 4: f[i][j] = max{f[i-1][j]+(P_(i-1) - P_(i-2), f[i-1][j-1]}
                f[i][j] = f[i-1][j-1];
                if (i>=2 && f[i-1][j]!=INT_MIN){
                    f[i][j] = max(f[i][j], f[i-1][j]+(prices[i-1]-prices[i-2]));
                }
            }
        }
        
        int result = INT_MIN;
        for (i=1;i<=2*K+1;i+=2){
            result = max(result, f[n][i]);
        }
        return result;
    }
};*/

// 方法2：滚动数组
class Solution {
public:
    int maxProfit_4(int K, vector<int> &prices) {
        int n = prices.size();
        if (n == 0){
            return 0;
        }
        
        int i, j;
        if (K > n/2){
            // best time to buy and sell stock II
            // buy and sell any time
            int sum = 0;
            for (i=0;i<n-1;i++){
                if (prices[i+1] > prices[i]){
                    sum += (prices[i+1] - prices[i]);
                }
            }
            return sum;
        }

        int f[2][2*K+2];
        int old, now = 0;

        // initialization
        f[now][1] = 0;
        for (i=2;i<=2*K+1;i++){
            f[now][i] = INT_MIN;
        }

        for (i=1;i<=n;i++){
            old = now;
            now = 1 - now; 
            // 阶段1， 3， 5, ..., 2K+1
            for(j=1;j<=2*K+1;j+=2){
                // 阶段1， 3， 5：f[i][j] = max{f[i-1][j], f[i-1][j-1]+(P_(i-1) - P_(i-2))}
                f[now][j] = f[old][j];
                if (j>1 && i>=2 && f[old][j-1]!=INT_MIN){
                    f[now][j] = max(f[now][j], f[old][j-1]+(prices[i-1]-prices[i-2]));
                }
            }

            // 阶段2， 4, ..., 2K
            for(j=2;j<=2*K;j+=2){
                // 阶段2, 4: f[i][j] = max{f[i-1][j]+(P_(i-1) - P_(i-2), f[i-1][j-1]}
                f[now][j] = f[old][j-1];
                if (i>=2 && f[old][j]!=INT_MIN){
                    f[now][j] = max(f[now][j], f[old][j]+(prices[i-1]-prices[i-2]));
                }
            }
        }
        
        int result = INT_MIN;
        for (i=1;i<=2*K+1;i+=2){
            result = max(result, f[now][i]);
        }
        return result;
    }
};
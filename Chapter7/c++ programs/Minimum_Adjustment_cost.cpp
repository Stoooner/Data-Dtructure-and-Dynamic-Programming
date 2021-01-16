#include<iostream>
#include<string>
#include<vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    /*
     * @param A: An integer array
     * @param target: An integer
     * @return: An integer
     * 序列+状态型动态规划
     */
    int MinAdjustmentCost(vector<int> &A, int target) {
        // write your code here
        int n = A.size();
        if (n==0){
            return 0;
        }
        int i, j, k;
        int f[n+1][101];
        for (i=1; i<=100;i++){
            f[1][i] = abs(A[0]-i);
        }

        for (i=2;i<=n;i++){
            // A[i-1] changes to B[i-1] = j
            for (j=1;j<=100;j++){
                f[i][j] = INT_MAX;
                // A[i-2] changes to B[i-2] = k
                for (k=j-target;k<=j+target;k++){
                    if (k<1 || k>100){
                        continue;
                    }
                    f[i][j] = min(f[i][j], f[i-1][k]);
                }
                f[i][j] += abs(j-A[i-1]); 
            }
        }
        int res = INT_MAX;
        for (i=1;i<=100;i++){
            res = min(res, f[n][i]);
        }
        return res;
    }
};
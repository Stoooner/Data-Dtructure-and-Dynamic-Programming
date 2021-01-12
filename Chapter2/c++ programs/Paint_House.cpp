#include<iostream>
#include<string>
#include<vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    /**
     * @param costs: n x 3 cost matrix
     * @return: An integer, the minimum cost to paint all houses
     */
    int minCost(vector<vector<int>> &costs) {
        // write your code here
        int n = costs.size();
        if (n==0){
            return 0;
        }
        // f[0],...f[n]
        int f[n+1][3];
        f[0][0] = f[0][1] = f[0][2] = 0;
        for (int i=1;i<=n;i++){
            // color of house i-1
            for (int j=0;j<3;j++){
                f[i][j] = INT_MAX;
                // color of house i-2
                for (int k=0;k<3;k++){
                    if (j != k){
                        f[i][j] = min(f[i][j], f[i-1][k]+costs[i-1][j]);
                    }
                }
            }
        }
        return min(f[n][0],min(f[n][1],f[n][2]));
    }
};
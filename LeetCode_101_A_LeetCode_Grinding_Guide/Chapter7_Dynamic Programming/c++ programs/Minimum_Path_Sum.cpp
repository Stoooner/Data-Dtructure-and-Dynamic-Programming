#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

// 方法1：普通方式
/*
class Solution {
public:
    int minPathSum(vector<vector<int>> &grid) {
        int m = grid.size();
        int n = grid[0].size();
        if (m == 0 or n == 0){
            return 0;
        }

        // 状态转移方程：f[i][j] = min(f[i-1][j], f[i][j-1]) + grid[i][j]
        int f[m][n];
        for (int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if (i==0 && j==0){
                    f[i][j] = grid[i][j];
                    continue;
                }
                int t = INT_MAX;
                if (i > 0){
                    t = min(t, f[i-1][j]);
                }
                if (j > 0){
                    t = min(t, f[i][j-1]);
                }
                f[i][j] = t + grid[i][j];
            }
        }
        return f[m-1][n-1];
    }
};*/

// 方法2：滚动数组
/*
class Solution {
public:
    int minPathSum(vector<vector<int>> &grid) {
        int m = grid.size();
        int n = grid[0].size();
        if (m == 0 or n == 0){
            return 0;
        }

        // 状态转移方程：f[i][j] = min(f[i-1][j], f[i][j-1]) + grid[i][j]
        int f[2][n];
        int old, now = 0;
        for (int i=0;i<m;i++){
            old = now;
            now = 1 - now;
            for(int j=0;j<n;j++){
                if (i==0 && j==0){
                    f[now][j] = grid[i][j];
                    continue;
                }
                int t = INT_MAX;
                if (i > 0){
                    t = min(t, f[old][j]);
                }
                if (j > 0){
                    t = min(t, f[now][j-1]);
                }
                f[now][j] = t + grid[i][j];
            }
        }
        return f[now][n-1];
    }
};*/

// 方法3：极限滚动数组(一维)
class Solution {
public:
    int minPathSum(vector<vector<int>> &grid) {
        int m = grid.size();
        int n = grid[0].size();
        if (m == 0 or n == 0){
            return 0;
        }

        // 状态转移方程：f[i][j] = min(f[i-1][j], f[i][j-1]) + grid[i][j]
        int f[n];
        for (int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if (i==0 && j==0){
                    f[j] = grid[i][j];
                    continue;
                }
                int t = INT_MAX;
                if (i > 0){
                    // 对于第i-1行，在更新第i行时，第i-1行的第j列已经更新过了
                    // 所以使用f[j]代表f[i-1][j]
                    t = min(t, f[j]);
                }
                if (j > 0){
                    // 对于第i行，在遍历第j列的时候，因为第j-1列已经更新过了
                    // 所以使用f[j-1]代表f[i][j-1]
                    t = min(t, f[j-1]);
                }
                // 在更新的那一刻，代表f[i-1][j]的f[j]因为"更新"这个动作
                // 使得f[j]变为了代表f[i][j]
                f[j] = t + grid[i][j];
            }
        }
        return f[n-1];
    }
};

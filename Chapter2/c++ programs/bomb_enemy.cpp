#include<iostream>
#include<string>
#include<vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    /**
     * @param grid: Given a 2D grid, each cell is either 'W', 'E' or '0'
     * @return: an integer, the maximum enemies you can kill using one bomb
     */
    int maxKilledEnemies(vector<vector<char>> &grid) {
        // write your code here
        int m = grid.size();
        if (m == 0){
            return 0;
        }
        int n = grid[0].size();
        if (n == 0){
            return 0;
        }
        int up[m][n];
        int down[m][n];
        int left[m][n];
        int right[m][n];

        int i, j, result = 0;

        // up往上的情况：计算顺序是从上往下
        for (i=0;i<m;i++){
            for (j=0;j<n;j++){
                if (grid[i][j]=='W'){
                    up[i][j] = 0;
                    continue;
                }
                // 如果本格是敌人的话，则炸死数目加1，否则本格炸死数目为0
                up[i][j] = (grid[i][j] == 'E') ? 1 : 0;
                if (i > 0){
                    up[i][j] += up[i-1][j];
                }
            }
        }

        // down往下的情况：计算顺序是从下往上
        for (i=m-1;i>=0;i--){
            for (j=0;j<n;j++){
                if (grid[i][j]=='W'){
                    down[i][j] = 0;
                    continue;
                }
                // 如果本格是敌人的话，则炸死数目加1，否则本格炸死数目为0
                down[i][j] = (grid[i][j] == 'E') ? 1 : 0;
                if (i < m-1){
                    // 由于是从下往上的顺序计算，因此down[i+1]是在down[i]之前被计算的
                    down[i][j] += down[i+1][j];
                }
            }
        }

        // left往左的情况：计算顺序是从左往右
        for (i=0;i<m;i++){
            for (j=0;j<n;j++){
                if (grid[i][j]=='W'){
                    left[i][j] = 0;
                    continue;
                }
                // 如果本格是敌人的话，则炸死数目加1，否则本格炸死数目为0
                left[i][j] = (grid[i][j] == 'E') ? 1 : 0;
                if (j > 0){
                    left[i][j] += left[i][j-1];
                }
            }
        }

        // right往右的情况：计算顺序是从右往左
        for (i=0;i<m;i++){
            for (j=n-1;j>=0;j--){
                if (grid[i][j]=='W'){
                    right[i][j] = 0;
                    continue;
                }
                // 如果本格是敌人的话，则炸死数目加1，否则本格炸死数目为0
                right[i][j] = (grid[i][j] == 'E') ? 1 : 0;
                if (j < n-1){
                    right[i][j] += right[i][j+1];
                }
            }
        }
        
        for (i=0;i<m;i++){
            for (j=0;j<n;j++){
                if (grid[i][j]=='0'){
                    int t = up[i][j] + left[i][j] + down[i][j]+ right[i][j];
                    result = max(result, t);
                }
            }
        }
        return result;
    }
};
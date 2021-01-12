#include<iostream>
#include<string>
#include<vector>
using namespace std;

class Solution {
public:
    /**
     * @param obstacleGrid: A list of lists of integers
     * @return: An integer
     */
    int uniquePathsWithObstacles(vector<vector<int>> &obstacleGrid) {
        // write your code here
        int m = obstacleGrid.size();
        if (m==0){
            return 0;
        }

        int n = obstacleGrid[0].size();
        if (n == 0){
            return 0;
        }

        // 坐标型动态规划中传入的数组是m*n的，那么创建的状态矩阵就是m*n大小的
        int f[m][n];
        for (int i = 0;i < m;i++){
            for(int j=0;j<n;j++){
                // 障碍使用的是数字1来进行表示的
                if (obstacleGrid[i][j] == 1){
                    f[i][j] = 0;
                    continue; // 在第j列处理完毕之后，接着处理第j+1列格子的情况
                }

                // top-left
                if (i==0 && j==0){
                    f[i][j] = 1;
                    continue;
                } 

                f[i][j] = 0;
                // 对于下面这个if判断，如果是第一行，这个if语句就不执行
                if (i > 0){
                    f[i][j] += f[i-1][j];
                }
                // 如果是第一列，下面if语句就不执行
                if (j > 0){
                    f[i][j] += f[i][j-1];
                }
            }
        }
        return f[m-1][n-1];
    }
};

int main(){

}
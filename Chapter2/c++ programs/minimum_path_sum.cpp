#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

/*
1. 求最值一般用min/max；
2. 求方式数用＋；
3. 求可行性用and/or等；
*/

/*****************************方法1：*************************************/
class Solution {
public:
    /**
     * @param grid: a list of lists of integers
     * @return: An integer, minimizes the sum of all numbers along its path
     */
    int minPathSum(vector<vector<int>> &grid) {
        // write your code here
        int m = grid.size();
        if (m == 0){
            return 0;
        }
        int n = grid[0].size();
        if (n == 0){
            return 0;
        }
        int f[m][n];
        // 要记录路径，关键的就是上一步到底是来自i还是i-1，这里使用数组pi来进行记录
        // 其中pi[i][j]=0代表的是从上面来的，因为第i行的记录=0；
        // 相应的pi[i][j]=0代表是从左边来的
        int pi[m][n];

        for (int i=0;i<m;i++){
            for (int j=0;j<n;j++){
                // f[i][j] = min(f[i-1][j], f[i][j-1]) + grid[i][j]
                // f[0][0] = A[0][0]
                if (i==0 && j==0){
                    f[i][j] = grid[i][j];
                    // 绝对不要忘了continue，不然这代码下它会算出无穷大
                    continue;
                }
                int t = INT_MAX;
                if (i>0){
                    t = min(t, f[i-1][j]);
                    // t == f[i-1][j]代表是从结果是来自上面的结果时
                    if (t == f[i-1][j]){
                        pi[i][j] = 0;
                    }
                }
                if (j>0){
                    t = min(t, f[i][j-1]);
                    // t == f[i][j-1]代表是从结果是来自左边的结果时
                    if (t == f[i][j-1]){
                        pi[i][j] = 1;
                    }
                }
                f[i][j] = t + grid[i][j];
            }
        }

        // 通过上面的代码pi记录了路径的情况后，要重现路径时，从[m-1][n-1]开始倒着推导
        int path[m+n-1]; // 整个路径长度肯定是m+n-1
        int x = m-1;
        int y = n-1; // 最终结果所在的位置(x, y)
        // path: 这里存放着的是reverse order，因为是从(m-1, n-1)位置开始倒着推导的
        for (int p=0;p<m+n-1;p++){
            path[p] = grid[x][y];
            if (pi[x][y] == 0){
                --x;
            }
            else{
                --y;
            }
        }
        
        cout << "final path: " << endl;
        for (int p=m+n-2;p>=0;p--){
            cout << path[p] << " ";
        }

        return f[m-1][n-1];
    }
};

/*****************************方法2：*************************************/
// class Solution {
// public:
//     /**
//      * @param grid: a list of lists of integers
//      * @return: An integer, minimizes the sum of all numbers along its path
//      */
//     int minPathSum(vector<vector<int>> &grid) {
//         // write your code here
//         int m = grid.size();
//         if (m == 0){
//             return 0;
//         }
//         int n = grid[0].size();
//         if (n == 0){
//             return 0;
//         }
//         int f[m][n];
//         for (int i=0;i<m;i++){
//             for (int j=0;j<n;j++){
//                 // f[i][j] = min(f[i-1][j], f[i][j-1]) + grid[i][j]
//                 // f[0][0] = A[0][0]
//                 if (i==0 && j==0){
//                     f[i][j] = grid[i][j];
//                     // // 绝对不要忘了continue，不然这代码下它会算出无穷大
//                     // continue;
//                 }
//                 else{
//                     int t = INT_MAX;
//                     if (i>0){
//                         t = min(t, f[i-1][j]);
//                     }
//                     if (j>0){
//                         t = min(t, f[i][j-1]);
//                     }
//                     f[i][j] = t + grid[i][j];
//                 }
//             }
//         }
//         return f[m-1][n-1];
//     }
// };

/*****************************方法3：滚动数组*************************************/
// class Solution {
// public:
//     /**
//      * @param grid: a list of lists of integers
//      * @return: An integer, minimizes the sum of all numbers along its path
//      * 对于网格上的动态规划，如果f[i][j]只依赖与本行的f[i][x]和前一行的f[i-1][y]时，那么
//      * 就可以采用滚动数组的方式压缩空间，空间复杂度由O(MN)变成了O(N);
//      */
//     int minPathSum(vector<vector<int>> &grid) {
//         // write your code here
//         int m = grid.size();
//         if (m == 0){
//             return 0;
//         }
//         int n = grid[0].size();
//         if (n == 0){
//             return 0;
//         }
//         int f[2][n]; // 开两行的数组
//         // 使用now代表第i行，使用old(=1-now)代表第i-1行
//         int old, now=0; // now表示当前这一行存在哪儿
//         for (int i=0;i<m;i++){
//             // 每当处理新的一行的时候就交换old和now(滚动的意义所在)
//             old = now;
//             now = 1 - now; // 0-->1, 1-->0 
//             for (int j=0;j<n;j++){
//                 // f[i][j] = min(f[i-1][j], f[i][j-1]) + grid[i][j]
//                 // f[0][0] = A[0][0]
//                 if (i==0 && j==0){
//                     f[now][j] = grid[i][j];
//                     // 没有else的时候绝对不要忘了continue，不然这代码下它会算出无穷大
//                     // continue;
//                 }
//                 else{
//                     int t = INT_MAX;
//                     if (i>0){
//                         t = min(t, f[old][j]);
//                     }
//                     if (j>0){
//                         t = min(t, f[now][j-1]);
//                     }
//                     f[now][j] = t + grid[i][j];
//                 }
//             }
//         }
//         return f[now][n-1];
//     }
// };

/*****************************方法4：滚动数组(%2法)*************************************/
// class Solution {
// public:
//     /**
//      * @param grid: a list of lists of integers
//      * @return: An integer, minimizes the sum of all numbers along its path
//      * 对于网格上的动态规划，如果f[i][j]只依赖与本行的f[i][x]和前一行的f[i-1][y]时，那么
//      * 就可以采用滚动数组的方式压缩空间，空间复杂度由O(MN)变成了O(N);
//      */
//     int minPathSum(vector<vector<int>> &grid) {
//         // write your code here
//         int m = grid.size();
//         if (m == 0){
//             return 0;
//         }
//         int n = grid[0].size();
//         if (n == 0){
//             return 0;
//         }
//         int f[2][n]; // 开两行的数组
//         for (int i=0;i<m;i++){
//             for (int j=0;j<n;j++){
//                 // f[i][j] = min(f[i-1][j], f[i][j-1]) + grid[i][j]
//                 // f[0][0] = A[0][0]
//                 if (i==0 && j==0){
//                     f[i%2][j] = grid[i][j];
//                     // 没有else的时候绝对不要忘了continue，不然这代码下它会算出无穷大
//                     // continue;
//                 }
//                 else{
//                     int t = INT_MAX;
//                     if (i>0){
//                         t = min(t, f[1-i%2][j]);
//                     }
//                     if (j>0){
//                         t = min(t, f[i%2][j-1]);
//                     }
//                     f[i%2][j] = t + grid[i][j];
//                 }
//             }
//         }
//         return f[(m-1)%2)][n-1];
//     }
// };

int main(){
    // 测试将相关路径打印出来的方法(此时不能使用滚动数组了)
    Solution s;
    int temp[3][5] = {{1, 5, 7, 6, 8},{4, 7, 4, 4, 9},{10, 3, 2, 3, 2}};
    vector<vector<int>> grid(3, vector<int>(5));
    for(int i = 0; i < 3;++i){
        for (int j = 0; j < 5; ++j){
        grid[i][j]=temp[i][j];
    }
}
    s.minPathSum(grid);
}
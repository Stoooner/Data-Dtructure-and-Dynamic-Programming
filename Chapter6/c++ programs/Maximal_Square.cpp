#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<map>
#include<set>
#include<unordered_map>
using namespace std;
// 坐标型，考虑右下角
class Solution {
public:
    /**
     * @param matrix: a matrix of 0 and 1
     * @return: an integer
     */
    int maxSquare(vector<vector<int>> &matrix) {
        // write your code here
        int m = matrix.size();
        int n = matrix[0].size();
        int i, j, res = 0;
        int f[m][n];

        for(i=0;i<m;i++){
            for(j=0;j<n;j++){
                if (matrix[i][j] == 0){
                    f[i][j] = 0;
                    continue;
                }
                // 上面的if排除了matrix[i][j]=0的情况后，现在matrix[i][j]肯定为1
                // 此时先初始化f[i][j]为1(包含i=0,j!=0以及i!=0,j=0的情况)；
                f[i][j] = 1;
                // i > 0 && j > 0的情况：
                if (i > 0 && j > 0){
                    f[i][j] = min(min(f[i-1][j], f[i][j-1]),f[i-1][j-1]) + 1;
                }
                res = max(res, f[i][j]*f[i][j]);
            }
        }
        return res;
    }
};
// 计数型动态规划
#include<iostream>
#include<string>
#include<vector>
using namespace std;

class Solution {
public:
    /**
     * @param m: positive integer (1 <= m <= 100)
     * @param n: positive integer (1 <= n <= 100)
     * @return: An integer
     */
    int uniquePaths(int m, int n) {
        // write your code here
        int f[m][n];
        // 计算顺序是逐行逐列的
        for(int i = 0; i < m; i++){
            for (int j=0; j < n; j++){
                // 初始化条件(边界情况，这里已经隐含了f[0][0]=1的边界情况了)
                if (i == 0 || j == 0){
                    f[i][j] = 1;
                }
                else{
                    // 上边 + 左边
                    f[i][j] = f[i-1][j] + f[i][j-1];
                }
            }
        }
        return f[m-1][n-1];
    }
};

int main(){
    Solution s;
    int m= 3;
    int n = 3;
    int result = s.uniquePaths(m, n);
    cout << "result = " << result << endl;
}
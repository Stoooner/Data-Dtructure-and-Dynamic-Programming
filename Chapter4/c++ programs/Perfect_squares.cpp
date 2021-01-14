// 划分型动态规划
#include<iostream>
#include<string>
#include<vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    /**
     * @param n: a positive integer
     * @return: An integer
     */
    int numSquares(int n) {
        // write your code here
        int f[n+1];
        f[0] = 0;   
        for (int i=1;i<=n;i++){
            f[i] = INT_MAX;
            for (int j=1;j*j<=i;j++){
                f[i] = min(f[i], f[i-j*j]+1);
            }
        }
        return f[n];
    }
};

int main(){
    int n = 13;
    int result = Solution().numSquares(n);
    cout << "result = " << result << endl;

}
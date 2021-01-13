#include<iostream>
#include<string>
#include<vector>
#include <algorithm>
using namespace std;

// 和位操作相关的动态规划一般用值作状态
class Solution {
public:
    /**
     * @param num: a non negative integer number
     * @return: an array represent the number of 1's in their binary
     */
    vector<int> countBits(int num) {
        // write your code here
        // f[i]代表数组i的二进制中有多少个1
        // 转移方程：f[i] = f[i>>1] + (i mod 2)
        vector<int> f(num+1, 0); // f[0](数字0中有0个1，这个是初始条件), ... ,f[num]
        for (int i=1;i<=num;i++){
            // f[i] = f[i>>1] + (i%2);
            f[i] = f[i>>1] + (i&1);
        }
        return f;
    }
};

int main(){
    int num = 5;
    Solution s;
    vector<int> result(num+1, 0);
    result = s.countBits(num);
    cout << "result = " << endl;
    for (int i=0; i<=num; i++){
        cout << result[i] << endl;
    }

}
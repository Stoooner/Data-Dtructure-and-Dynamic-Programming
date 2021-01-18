#include<iostream>
#include<string>
#include<vector>
using namespace std;

// 方法1：自己的写法
// class Solution {
// public:
//     /**
//      * @param n: An integer
//      * @return: An integer
//      */
//     int climbStairs(int n) {
//         // write your code here
//         if (n==0){
//             return 0;
//         }
//         // f[i]表示台阶数量为i时爬台阶的总方式数
//         int f[n+1];
//         for (int i=0;i<=n;i++){
//             // initialize
//             if (i==0 or i==1){
//                 f[i] = 1;
//                 continue;
//             }
//             // 状态转移方程
//             f[i] = f[i-1] + f[i-2];
//         }
//         return f[n];
//     }
// };

// 方法2：参考别人的写法
// class Solution {
// public:
//     /**
//      * @param n: An integer
//      * @return: An integer
//      */
//     int climbStairs(int n){
//         if (n <= 2) return n; 
//         // 需要注意的是上面if判断中如果台阶数n=0，则返回的方式数为0
//         // 但是在定义状态转移矩阵时，f[0]要定义为f[0]=1, 否则计算的结果会不对
//         vector<int> f(n+1, 1);
//         for (int i=2;i<=n;i++){
//             f[i] = f[i-1] + f[i-2];
//         }
//         return f[n];
//     }
// };

// 方法3：滚动变量(压缩空间)
class Solution {
public:
    /**
     * @param n: An integer
     * @return: An integer
     */
    int climbStairs(int n){
        if (n <= 2) return n; 
        int old = 1, now = 2;
        // 需要注意的是，如果是转移矩阵的话，i为多少，f[i]就对应的是第几阶楼梯
        // 而在这里使用滚动变量的方式时，当i=2开始时，cur就已经对应了f[i+1]的位置了
        // 因此在循环中i不能去掉i=n, 因此只能是i<n;
        for (int i=2;i<n;i++){
            int t = old + now;
            // 这里的交替更改变量的方式与old/now方式类似，注意其区别
            old = now;
            now = t;
        }
        return now;
    }
};
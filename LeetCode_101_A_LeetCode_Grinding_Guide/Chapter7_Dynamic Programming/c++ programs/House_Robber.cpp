#include<iostream>
#include<string>
#include<vector>
#include <algorithm>
using namespace std;

// 方法1：常规方式：
// class Solution {
// public:
//     /**
//      * @param A: An array of non-negative integers
//      * @return: The maximum amount of money you can rob tonight
//      */
//     long long houseRobber(vector<int> &A) {
//         // write your code here
//         int n = A.size();
//         if (n == 0){
//             return 0;
//         }

//         if (n == 1){
//             return A[0];
//         }

//         long long f[n+1];
//         f[0] = 0;
//         f[1] = A[0];
//         // f[2] = max(A[0], A[1]);
//         for (int i=2; i<=n;i++){
//             f[i] = max(f[i-1], f[i-2]+A[i-1]);
//         }
//         return f[n];
//     }
// };

// 方法2：滚动数组
class Solution {
public:
    /**
     * @param A: An array of non-negative integers
     * @return: The maximum amount of money you can rob tonight
     */
    long long houseRobber(vector<int> &A) {
        // write your code here
        int n = A.size();
        if (n == 0){
            return 0;
        }

        if (n == 1){
            return A[0];
        }
        // 这里old一定要赋值，因此for循环里参与了训练，否则old的数据就是被随机初始化的一个脏数据
        long old = 0; // f[0]
        long now = A[0]; // f[1]
        for (int i=2; i<=n;i++){
            // now = f[i-1], old = f[i-2]
            long t = max(now, old+A[i-1]); //f[i]
            old = now; // old = f[i-1]
            now = t; // now = f[i]
        }
        return now;
    }
};

int main(){
    vector<int> A;

}
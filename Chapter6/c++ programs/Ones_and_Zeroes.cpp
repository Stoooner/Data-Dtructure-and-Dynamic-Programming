#include<iostream>
#include<string>
#include<vector>
#include <algorithm>
using namespace std;

// 方法1：
// class Solution {
// public:
//     /**
//      * @param strs: an array with strings include only 0 and 1
//      * @param m: An integer
//      * @param n: An integer
//      * @return: find the maximum number of strings
//      */
//     int findMaxForm(vector<string> &strs, int m, int n) {
//         // write your code here
//         if (strs.size() == 0){
//             return 0;
//         }

//         int T = strs.size();
//         int f[T+1][m+1][n+1];
//         int i, j, k, a0, a1;

//         // init 
//         for (j=0;j<=m;j++){
//             for(k=0;k<=n;k++){
//                 f[0][j][k] = 0;
//             }
//         }

//         for (i=1;i<=T;i++){
//             // how many 0's and 1's are there in strs[i-1];
//             a0 = a1 = 0;
//             for (j=0;j < strs[i-1].size();j++){
//                 if (strs[i-1][j] == '0'){
//                     ++ a0;
//                 }
//                 else{
//                     ++ a1;
//                 }
//             }

//             for (j=0;j<=m;j++){
//                 for (k=0;k<=n;k++){
//                     f[i][j][k] = f[i-1][j][k];
//                     if (j >= a0 && k >= a1){
//                         f[i][j][k] = max(f[i][j][k], f[i-1][j-a0][k-a1]+1);
//                     }
//                 }
//             }
//         }
//         return f[T][m][n];
//     }
// };

// 方法2：
class Solution {
public:
    /**
     * @param strs: an array with strings include only 0 and 1
     * @param m: An integer
     * @param n: An integer
     * @return: find the maximum number of strings
     */
    int findMaxForm(vector<string> &strs, int m, int n) {
        // write your code here
        if (strs.size() == 0){
            return 0;
        }

        int T = strs.size();
        int f[2][m+1][n+1];
        int old, now=0;
        int i, j, k, a0, a1;

        // init 
        for (j=0;j<=m;j++){
            for(k=0;k<=n;k++){
                f[now][j][k] = 0;
            }
        }

        for (i=1;i<=T;i++){
            old = now;
            now = 1 - now;
            // how many 0's and 1's are there in strs[i-1];
            a0 = a1 = 0;
            for (j=0;j < strs[i-1].size();j++){
                if (strs[i-1][j] == '0'){
                    ++ a0;
                }
                else{
                    ++ a1;
                }
            }

            for (j=0;j<=m;j++){
                for (k=0;k<=n;k++){
                    f[now][j][k] = f[old][j][k];
                    if (j >= a0 && k >= a1){
                        f[now][j][k] = max(f[now][j][k], f[old][j-a0][k-a1]+1);
                    }
                }
            }
        }
        return f[now][m][n];
    }
};
#include<iostream>
#include<string>
#include<vector>
#include <algorithm>
using namespace std;

// 方法1：普通方法
// class Solution {
// public:
//     /**
//      * @param S: A string
//      * @param T: A string
//      * @return: Count the number of distinct subsequences
//      */
//     int numDistinct(string &S, string &T) {
//         // write your code here
//         int m = S.size();
//         int n = T.size();
//         int i, j;
//         int f[m+1][n+1];

//         for (i=0;i<=m;i++){
//             for(j=0;j<=n;j++){
//                 if (j==0){ // 如果T是空串则f[i][j]无条件的等于1
//                     f[i][j] = 1;
//                     continue;
//                 }
//                 // 走到这一步时，j > 0;
//                 if (i==0){
//                     f[i][j] = 0;
//                     continue;
//                 }
//                 // i > 0, j > 0;
//                 // B[j-1] is not connected with A[i-1];
//                 f[i][j] = f[i-1][j];
//                 if (S[i-1] == T[j-1]){
//                     // B[j-1] is connected with A[i-1];
//                     f[i][j] += f[i-1][j-1];
//                 }
//             }
//         }
//         return f[m][n];
//     }
// };

// 方法2：滚动数组
class Solution {
public:
    /**
     * @param S: A string
     * @param T: A string
     * @return: Count the number of distinct subsequences
     */
    int numDistinct(string &S, string &T) {
        // write your code here
        int m = S.size();
        int n = T.size();
        int i, j;
        int f[m+1][n+1];
        int old, now=0;

        for (i=0;i<=m;i++){
            old = now;
            now = 1 - now;
            for(j=0;j<=n;j++){
                if (j==0){ // 如果T是空串则f[i][j]无条件的等于1
                    f[now][j] = 1;
                    continue;
                }
                // 走到这一步时，j > 0;
                if (i==0){
                    f[now][j] = 0;
                    continue;
                }
                // i > 0, j > 0;
                // B[j-1] is not connected with A[i-1];
                f[now][j] = f[old][j];
                if (S[i-1] == T[j-1]){
                    // B[j-1] is connected with A[i-1];
                    f[now][j] += f[old][j-1];
                }
            }
        }
        return f[now][n];
    }
};
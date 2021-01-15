#include<iostream>
#include<string>
#include<vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    /**
     * @param s1: A string
     * @param s2: Another string
     * @return: whether s2 is a scrambled string of s1
     */
    bool isScramble(string &s1, string &s2) {
        // write your code here
        int m = s1.size();
        int n = s2.size();
        if (m != n){
            return false;
        }
        //f[i][j][k][h]表示T[k...h]是否由S[i...j]变来的
        // 经过优化可以变为f[i][j][k]，它表示S1能否变成T1
        // 
        bool f[n][n][n+1];
        int i, j, k, w;
        for (i=0;i<n;i++){
            for (j=0;j<n;j++){
                // S从i开始，T从j开始，长度为1，看s1[i]是否等于s2[j]
                f[i][j][1] = (s1[i]==s2[j]);
            }
        }
        // 枚举长度
        for (k=2;k<=n;k++){
            // S开始位置i
            for (i=0;i<=n-k;i++){
                // T开始位置j
                for (j=0;j<=n-k;j++){
                    // 初始化： S[i,...i+k-1], T[j...j+k-1] --> 长度为k
                    f[i][j][k] = false;
                    // 对于S_i和T_i，每次的划分点用w来进行枚举
                    for (w=1;w<=k-1;w++){
                        if (f[i][j][w] && f[i+w][j+w][k-w]){
                            f[i][j][k] = true;
                            break; 
                        }
                    }

                    for (w=1;w<=k-1;w++){
                        if (f[i][j+k-w][w] && f[i+w][j][k-w]){
                            f[i][j][k] = true;
                            break; 
                        }
                    }
                }
            }
        }
        return f[0][0][n];
    }
};
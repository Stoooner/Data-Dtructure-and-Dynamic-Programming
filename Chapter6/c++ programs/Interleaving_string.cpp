#include<iostream>
#include<string>
#include<vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    /**
     * @param s1: A string
     * @param s2: A string
     * @param s3: A string
     * @return: Determine whether s3 is formed by interleaving of s1 and s2
     */
    bool isInterleave(string &s1, string &s2, string &s3) {
        // write your code here
        int m = s1.size();
        int n = s2.size();
        int i, j;
        if (m+n != s3.size()){
            return false;
        }
        bool f[m+1][n+1];
        for (i=0;i<=m;i++){
            for(j=0;j<=n;j++){
                if (i==0 && j==0){
                    f[i][j] = true;
                    continue;
                }
                f[i][j] = false; // 初始状态

                // 一定要判断i和j是否大于0
                if (i>0 && s3[i+j-1] == s1[i-1]){
                    f[i][j] |= f[i-1][j];
                }

                if (j>0 && s3[i+j-1] == s2[j-1]){
                    f[i][j] |= f[i][j-1];
                }

            }
        }
        return f[m][n];
    }
};
#include<iostream>
#include<string>
#include<vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    /**
     * @param s: A string 
     * @param p: A string includes "." and "*"
     * @return: A boolean
     */
    bool isMatch(string &s, string &p) {
        // write your code here
        int m = s.size();
        int n = p.size();
        int i, j;
        bool f[m+1][n+1];

        for (i=0;i<=m;i++){
            for(j=0;j<=n;j++){
                if (i==0 && j==0){
                    f[i][j] = true;
                    continue;
                }

                if (j==0){
                    f[i][j] = false; // 空的正则表达式不能匹配任何的非空字符串
                    continue;
                }

                // j > 0
                f[i][j] = false;
                if (p[j-1] != '*'){
                    if (i > 0 && (p[j-1] == '.' || s[i-1] == p[j-1])){
                        f[i][j] = f[i-1][j-1];
                    }
                }
                else{
                    // 忽略"c*"
                    if (j>1){
                        f[i][j] |= f[i][j-2];
                    }
                    if (i>0 && j>1){
                        if (p[j-2] == '.' || s[i-1] == p[j-2]){
                            f[i][j] |= f[i-1][j];
                        }
                    }
                }
            }
        }
        return f[m][n];
    }
};
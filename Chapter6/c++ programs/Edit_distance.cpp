#include<iostream>
#include<string>
#include<vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    /**
     * @param word1: A string
     * @param word2: A string
     * @return: The minimum number of steps.
     */
    int minDistance(string &word1, string &word2) {
        // write your code here
        int m = word1.size();
        int n = word2.size();
        int i, j;
        int f[m+1][n+1];

        for (i=0;i<=m;i++){
            for(j=0;j<=n;j++){
                if (i==0){
                    f[i][j] = j;
                    continue;
                }
                if (j==0){
                    f[i][j] = i;
                    continue;
                }
                f[i][j] = min(min(f[i-1][j], f[i][j-1]), f[i-1][j-1]) + 1;
                if (word1[i-1] == word2[j-1]){
                    f[i][j] = min(f[i][j], f[i-1][j-1]);
                }
            }
        }
        return f[m][n];
    }
};
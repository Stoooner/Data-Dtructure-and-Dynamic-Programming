// 划分型动态规划
#include<iostream>
#include<string>
#include<vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    /**
     * @param s: A string
     * @return: An integer
     */
    bool calcPalin(string &s, bool **f, int n){
        // int n = s.size();
        cout << "n = " << n << endl;
        // bool f[n][n];
        for (int i=0;i<n;i++){
            for (int j=i;j<n;j++){
                f[i][j] = false;
            }
        }

        int i, j, center;
        // odd length(center charater)
        for (center=0;center<n;center++){
            i = j = center;
            // extend to both directions
            while(i>=0 && j<n && s[i]==s[j]){
                f[i][j] = true;
                i--;
                j++;
            }
        }

        // even length(center line)
        for (center=0;center<n-1;center++){
            i = center;
            j = center+1;
            // extend to both directions
            while(i>=0 && j<n && s[i]==s[j]){
                f[i][j] = true;
                i--;
                j++;
            }
        }

        return f;
    }

    int minCut(string &s) {
        // write your code here
        int n = s.size();
        if (n == 0){
            return 0;
        }
        //calcPalin(s);
        bool * isPalin[n][n];
        int i;
        for (i=0; n>i; i++)
        {
            
        }

        isPalin = calcPalin(s, isPalin, n);
        int f[n+1];
        f[0] = 0;
        for (int i=1;i<=n;i++){
            f[i] = INT_MAX;
            // 0 <= j <= i-1;前0个到前i-1个
            for (int j=0;j<i;j++){
                if (isPalin[j][i-1]){
                    f[i] = min(f[i], f[j]+1);
                }
            }
        }
        return f[n] - 1;
    }
};

int main(){
    string ss = "abcba";
    Solution s;
    s.calcPalin(ss);
    
}
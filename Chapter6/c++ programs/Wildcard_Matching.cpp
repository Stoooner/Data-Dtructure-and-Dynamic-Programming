#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    /**
     * @param s: A string 
     * @param p: A string includes "?" and "*"
     * @return: is Match?
     */
    bool isMatch(string &s, string &p) {
        // write your code here
        int m = s.size();
        int n = p.size();
        int i, j;
        bool f[m+1][n+1]; // row index from 0 to m;
        int pi[m+1][n+1];

        for (i=0;i<=m;i++){
            for (j=0;j<=n;j++){
                if (i==0 && j==0){
                    f[i][j] = true;
                    continue;
                }
                if (j==0){
                    // i > 0
                    f[i][j] = false;
                    continue;
                }

                // initialize
                f[i][j] = false;
                if (p[j-1] != '*'){
                    if (i>0 && (s[i-1]==p[j-1] || p[j-1] == '?')){
                        pi[i][j] = 1; // 代表同归于尽(A and B cuts tail)
                        f[i][j] |= f[i-1][j-1];
                    }
                }
                else{
                    f[i][j] |= f[i][j-1];
                    if (f[i][j-1] == true){
                        pi[i][j] = 2; // B cuts "*"
                    }
                    if (i > 0){
                        f[i][j] |= f[i-1][j];
                        if (f[i-1][j] == true){
                        pi[i][j] = 3; // B's "*" at least matches A's tail
                        }
                    }
                }
            }
        }
        if (f[m][n]){
            int res[m]; // res[i] represents that A[i] is matched against B[res[i]];
            i = m;
            j = n;
            while(true){
                if (j==0){
                    break;
                }
                if (pi[i][j] == 1){
                    res[i-1] = j-1;
                    --i;
                    --j;
                }
                else{
                    if (pi[i][j] == 2){
                        --j;
                    }
                    else{
                        res[i-1] = j-1;
                        --i;
                    }
                }
            }
            
            for (i=0;i<m;i++){
                cout << s[i] << " matches " << p[res[i]] << endl;
            }
        }
        return f[m][n];
    }
};

int main(){
    string s = "abcdddef";
    string p = "*?c*d*e*f";
    Solution ss;
    bool result = ss.isMatch(s, p);
    cout << "result = " << result << endl;
}
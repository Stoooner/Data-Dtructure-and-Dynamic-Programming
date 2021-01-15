#include<iostream>
#include<string>
#include<vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    /**
     * @param A: A string
     * @param B: A string
     * @return: The length of longest common subsequence of A and B
     */
    int longestCommonSubsequence(string &A, string &B) {
        // write your code here
        int m = A.size();
        int n = B.size();
        int f[m+1][n+1];
        int pi[m+1][n+1];
        int i,j;
        for (i=0;i<=m;i++){
            for (j=0;j<=n;j++){
                if (i == 0 || j == 0){
                    f[i][j] = 0;
                    continue;
                }
                f[i][j] = max(f[i-1][j], f[i][j-1]);

                if (f[i][j] == f[i-1][j]){
                    pi[i][j] = 0;
                }
                else{
                    pi[i][j] = 1;
                }

                if (A[i-1] == B[j-1]){
                    f[i][j] = max(f[i][j], f[i-1][j-1]+1);
                    if (f[i][j] == f[i-1][j-1]+1){
                        pi[i][j] = 2;
                    }
                }
            }
        }
        char result[f[m][n]];
        int p = f[m][n]-1;
        i = m;
        j = n;
        while(i>0 && j>0){
            if (pi[i][j] == 0){
                // 说明用的是A的尾巴
                --i;
            }
            else if(pi[i][j] == 1){
                --j;
            }
            else{
                result[p] = A[i-1]; // 或者result[p] = B[i-1];
                --i;
                --j;
                --p;
            }
        }
        cout << "LCS is: " << endl;
        for (i=0;i<f[m][n];i++){
            cout << result[i] << " ";
        }

        return f[m][n];
    }
};

int main(){
    string A = "jiuzhang";
    string B = "lijiang";
    Solution().longestCommonSubsequence(A, B);
}

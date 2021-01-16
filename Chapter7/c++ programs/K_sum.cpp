#include<iostream>
#include<string>
#include<vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    /**
     * @param A: An integer array
     * @param k: A positive integer (k <= length(A))
     * @param target: An integer
     * @return: An integera
     */
    int kSum(vector<int> &A, int K, int target) {
        // write your code here
        int n = A.size();
        int i, j, k;
        int f[n+1][K+1][target+1];

        // initial
        for (j=0;j<=K;j++){
            for (k=0;k<=target;k++){
                f[0][j][k] = 0;
            }
        }

        f[0][0][0] = 1;
        for (i=1;i<=n;i++){
            for (j=0;j<=K;j++){
                for (k=0;k<=target;k++){
                    f[i][j][k] = f[i-1][j][k];
                    if (j > 0 && k >= A[i-1]){
                        f[i][j][k] += f[i-1][j-1][k-A[i-1]];
                    }
                }
            }
        }
        return f[n][K][target];
    }
};
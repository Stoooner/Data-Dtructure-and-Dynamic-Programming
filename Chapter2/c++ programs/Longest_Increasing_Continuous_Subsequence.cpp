#include<iostream>
#include<string>
#include<vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    /**
     * @param A: An array of Integer
     * @return: an integer
     */
    int LIS(vector<int> &A, int n){
        int i, j;
        int f[n];
        int res = 0;
        for (i=0;i<n;i++){
            // case 1
            f[i]=1;

            // case 2
            if (i>0 && A[i]>A[i-1]){
                f[i] = f[i-1]+1;
            }
            res = max(res, f[i]);
        }
        return res;
    }

    int longestIncreasingContinuousSubsequence(vector<int> &A) {
        // write your code here
        int n = A.size();
        if (n == 0){
            return 0;
        }
        int r1 = LIS(A, n);
        // reverse
        int i, j, t;
        i = 0;
        j = n-1;
        while(i < j){
            t = A[i];
            A[i] = A[j];
            A[j] = t;
            ++i;
            --j;
        }
        int r2 = LIS(A, n);
        return r1 > r2 ? r1 : r2;
    }
};
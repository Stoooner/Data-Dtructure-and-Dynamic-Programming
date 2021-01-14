// 背包问题中数组大小和总称重有关
#include<iostream>
#include<string>
#include<vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    /**
     * @param m: An integer m denotes the size of a backpack
     * @param A: Given n items with size A[i]
     * @return: The maximum size
     */
    int backPack(int m, vector<int> &A) {
        // write your code here
        int n = A.size();
        if (n == 0){
            return 0;
        }

        bool f[n+1][m+1];
        int i, j;
        f[0][0] = true;
        for (i=1;i<=m;i++){
            f[0][i] = false;
        }

        for (i=1;i<=n;i++){
            for (j=0;j<=m;j++){
                f[i][j] = f[i-1][j];
                if (j >= A[i-1]){
                    f[i][j] |= f[i-1][j-A[i-1]]; 
                }
            }
        }  
        int result = 0;
        for (i=m;i>=0;i--){
            if (f[n][i] == true){
                result = i;
                break;
            } 
        }
        return result;
    }
};
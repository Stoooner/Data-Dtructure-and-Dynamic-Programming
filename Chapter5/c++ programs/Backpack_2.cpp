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
     * @param V: Given n items with value V[i]
     * @return: The maximum value
     * 每个物品的数目不是无限的情况之下，所以物品的顺序是存在的，所以我们的最后一步就需要
     * 考虑最后一个物品进不进入到背包中，所以在拼出总重量W时，物品进入背包与否的总价值就
     * 成了最需要考虑的问题；
     */
    int backPackII(int m, vector<int> &A, vector<int> &V) {
        // write your code here
        int n = A.size();
        if (n == 0){
            return 0;
        }
        int f[n+1][m+1];
        int i, w;
        f[0][0] = 0;
        for(i=1;i<=m;i++){
            f[0][i] = -1; // 代表前0个物品不能拼出重量i；
        }

        for(i=1;i<=n;i++){
            for(w=0;w<=m;w++){
                f[i][w] = f[i-1][w]; // 初始化
                // w>=A[i-1]代表背包能撑下最后这个物品A[i-1]
                if (w>=A[i-1] && f[i-1][w-A[i-1]] != -1){
                    f[i][w] = max(f[i][w], f[i-1][w-A[i-1]]+V[i-1]);
                }
            }
        }
        int result = 0;
        for (w=0;w<=m;w++){
            if (f[n][w] != -1){
                result = max(result, f[n][w]);
            } 
        }
        return result;
    }
};
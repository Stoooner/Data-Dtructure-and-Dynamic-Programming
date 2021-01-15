#include<iostream>
#include<string>
#include<vector>
#include <algorithm>
using namespace std;

/***************************方法1***************************/
/*
class Solution {
public:
    int backPackIII(int m, vector<int> &A, vector<int> &V){
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
                if (w>=A[i-1] && f[i][w-A[i-1]] != -1){
                    f[i][w] = max(f[i][w], f[i][w-A[i-1]]+V[i-1]);
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
};*/

/***************************方法2: 滚动数组(变态一维版)***************************/
class Solution {
public:
    int backPackIII(int m, vector<int> &A, vector<int> &V){
        int n = A.size();
        if (n == 0){
            return 0;
        }
        int f[m+1]; // 滚动数组一维版

        int i, w;
        f[0] = 0;
        for(i=1;i<=m;i++){
            f[i] = -1; // 代表前0个物品不能拼出重量i；
        }

        for(i=1;i<=n;i++){
            for(w=0;w<=m;w++){
                                // f[i][w-A[i-1]]
                if (w>=A[i-1] && f[w-A[i-1]] != -1){
                              // f[i-1][w]
                    f[w] = max(f[w], f[w-A[i-1]]+V[i-1]);
                    // now f[w] is f[i][w]
                }
            }
        }
        int result = 0;
        for (w=0;w<=m;w++){
            if (f[w] != -1){
                result = max(result, f[w]);
            } 
        }
        return result;
    }
};

int main(){
    int temp1[] = {2, 3, 5, 7};
    vector<int> A(temp1, temp1+4);
    int temp2[] = {1, 5, 2, 4};
    vector<int> V(temp2, temp2+4);
    int m = 10;
    Solution s;
    int result = s.backPackIII(m, A, V);
    cout << "result = " << result << endl;
}
/*
关键点：最后一步
 - 1. 如果物品有顺序，则看最后一个物品有没有进入到背包；
 - 2. 如果物品没有顺序，则看最后一个进入背包的物品是哪个；
*/
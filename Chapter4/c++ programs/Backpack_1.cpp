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
        int pi[n+1][m+1];
        // pi[i][j]=0代表前i个物品拼出重量j时第i个物品不使用
        // pi[i][j]=1代表前i个物品拼出重量j时第i个物品要使用
        int i, j;
        f[0][0] = true;
        for (i=1;i<=m;i++){
            f[0][i] = false;
        }

        for (i=1;i<=n;i++){
            for (j=0;j<=m;j++){
                f[i][j] = f[i-1][j];
                pi[i][j] = 0;// 相当于初始化
                if (j >= A[i-1]){
                    if (f[i-1][j-A[i-1]]==true){
                        pi[i][j] = 1;
                    }
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
        
        cout << "放入背包中的物品重量如下： " << endl;
        i = result;
        for (j=n;j>=1;j--){
            if(pi[j][i]==1){
                cout << A[j-1] << " ";
                i -= A[j-1];
            }
        }

        return result;
    }
};

int main(){
    int temp[] = {3, 5, 8, 11, 7, 4};
    vector<int> A(temp, temp+6);
    int m = 20;
    Solution s;
    int result = s.backPack(m, A);
    cout << "result = " << result << endl;
}
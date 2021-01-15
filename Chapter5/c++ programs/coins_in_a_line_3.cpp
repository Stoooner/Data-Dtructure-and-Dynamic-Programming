#include<iostream>
#include<string>
#include<vector>
#include <algorithm>
using namespace std;

class Solution{
public: 
    bool firstWillWin_III(vector<int> &A){
        int n = A.size();
        if (n == 0){
            return 0;
        }
        int f[n][n];
        int i, j, len;
        for (i=0;i<n;i++){
            f[i][i] = A[i];
        }

        for (len=2;len<=n;len++){
            for(i=0;i<=n-len;i++){
                j = i + len - 1;
                f[i][j] = max(A[i]-f[i+1][j], A[j]-f[i][j-1]);
            }
        }
        return f[0][n-1] >= 0;
    }
};

int main(){
    int temp[] = {1, 6, 9, 20, 4, 7};
    vector<int> A(temp, temp+3);
    bool result = Solution().firstWillWin_III(A);
    cout << "result = " << result << endl; 
}
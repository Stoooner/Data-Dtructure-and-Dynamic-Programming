#include<iostream>
#include<string>
#include<vector>
#include <algorithm>
using namespace std;

// 方法1：
// class Solution {
// public:
//     /**
//      * @param pages: an array of integers
//      * @param k: An integer
//      * @return: an integer
//      */
//     int copyBooks(vector<int> &pages, int K) {
//         // write your code here
//         int n = pages.size();
//         if (n == 0){
//             return 0;
//         }

//         if (K > n){
//             K = n;
//         }

//         int f[K+1][n+1];
//         int i, j, k;
//         f[0][0] = 0; // 前0个人抄写0本书花费时间为0；
//         for (i=1;i<=n;i++){
//             f[0][i] = INT_MAX; // 初始条件
//         }

//         for (k=1;k<=K;k++){
//             f[k][0] = 0;
//             for (i=1;i<=n;i++){
//                 f[k][i] = INT_MAX;
//                 int sum = 0; // A[j]+...+A[i-1]
//                 for (j=i;j>=0;j--){
//                     f[k][i] = min(f[k][i], max(f[k-1][j], sum));
//                     if (j > 0){
//                         sum += pages[j-1];
//                     }
//                 }
//             }
//         }
//         return f[K][n];
//     }
// };

// 方法2：
class Solution {
public:
    /**
     * @param pages: an array of integers
     * @param k: An integer
     * @return: an integer
     */
    int copyBooks(vector<int> &pages, int K) {
        // write your code here
        int n = pages.size();
        if (n == 0){
            return 0;
        }

        if (K > n){
            K = n;
        }

        int f[K+1][n+1];
        int i, j, k;
        f[0][0] = 0; // 前0个人抄写0本书花费时间为0；
        for (i=1;i<=n;i++){
            f[0][i] = INT_MAX; // 初始条件
        }

        int sum[n];
        sum[0] = pages[0];
        for (i=1;i<n;i++){
            sum[i] = sum[i-1] + pages[i];
        }

        for (k=1;k<=K;k++){
            f[k][0] = 0;
            for (i=1;i<=n;i++){
                f[k][i] = INT_MAX;
                int s = 0;
                for (j=i;j>=0;j--){
                    // 0 3 0 2 5 0 4 6 9 0 3 0 2 5 0 4 6 9 result = 5
                    cout << s << " ";
                    // pages[j]+...+pages[i-1]
                    // sum[i-1] = pages[0] + pages[1] + ... + pages[j-1] + pages[j] + ... +pages[i-1]
                    // sum[j-1] = pages[0] + pages[1] + ... + pages[j-1]
                    f[k][i] = min(f[k][i], max(f[k-1][j], s));
                    if (j > 0){
                        s = sum[i-1] - sum[j];
                    }
                }
            }
        }
        return f[K][n];
    }
};

int main(){
    int temp[] = {3, 2, 4};
    vector<int> pages(temp, temp+3);
    int K = 3;
    Solution s;
    int result = s.copyBooks(pages, K);
    cout << "result = " << result << endl; 
}
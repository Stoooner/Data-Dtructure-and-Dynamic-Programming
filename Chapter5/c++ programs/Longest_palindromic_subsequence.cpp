#include<iostream>
#include<string>
#include<vector>
#include <algorithm>
using namespace std;

/*方法1：动态规划*/
// class Solution {
// public:
//     /**
//      * @param s: the maximum length of s is 1000
//      * @return: the longest palindromic subsequence's length
//      */
//     int longestPalindromeSubseq(string &s) {
//         // write your code here
//         int n = s.size();
//         if (n == 0 || n == 1){
//             return n;
//         }

//         int f[n][n]; // 区间形，端点到端点，因此开的数组就是nxn大小的就行了；
//         int pi[n][n];
//         int i, j, len;
//         // len = 1
//         for (i=0;i<n;i++){
//             f[i][i] = 1;// 初始化：f[0][0]=1, f[1][1]=1, ... , f[n][n]=1;
//         }
        
//         // len = 2
//         for (i=0;i<n-1;i++){
//             f[i][i+1] = (s[i]==s[i+1]) ? 2 : 1; 
//         }

//         // 枚举长度(0, 1, ..., n-3, n-2, n-1)
//         for (len=3;len<=n;len++){
//             // 0 -> 2
//             //   1 -> 3
//             //     2 -> 4
//             //       ....
//             //       n-3 -> n-1 
//             for (i=0;i<=n-len;i++){
//                 j = i + len -1;
//                 f[i][j] = max(f[i+1][j], f[i][j-1]);
//                 if (f[i][j] == f[i+1][j]){
//                     pi[i][j] = 0;
//                 }
//                 else{
//                     pi[i][j] = 1;
//                 }
//                 if (s[i] == s[j]){
//                     f[i][j] = max(f[i][j], f[i+1][j-1]+2);
//                     if (f[i][j] == f[i+1][j-1]+2){
//                         pi[i][j] = 2;
//                     }
//                 }
//             }
            
//         }
//         char result[f[0][n-1]];
//         int start = 0, end = f[0][n-1]-1;
//         i = 0;
//         j = n-1;
//         while(i <= j){
//             // len = 1
//             if (i==j){
//                 result[start] = s[i];
//                 break;
//             }
//             // len = 2
//             if (i+1==j){
//                 result[start] = s[i];
//                 result[end] = s[j];
//                 break;
//             }
//             if(pi[i][j] == 0){
//                 ++i;
//             }
//             else{
//                 if (pi[i][j] == 1){
//                     --j;
//                 }
//                 else{
//                     result[start++] = s[i];
//                     result[end--] = s[j];
//                     ++i;
//                     --j;
//                 }
//             }
//         }
//         cout << "result = "  << endl;
//         for (int i=0;i<f[0][n-1];i++){
//             cout << result[i] << " ";
//         }

//         return f[0][n-1];// 返回的是从index 0开始到index=n-1的字符串的性质
//     }
// };

/*方法2：记忆化搜索*/
class Solution {

public:
    /**
     * @param s: the maximum length of s is 1000
     * @return: the longest palindromic subsequence's length
     */
    vector<vector<int> > f;
    int n = 0;
    vector<char> s;

    void Compute(int i, int j){
        // memorization
        if (f[i][j] != -1){
            return;
        }
        if (i==j){
            f[i][j] = 1;
            return;
        }
        if (i+1==j){
            f[i][j] = (s[i] == s[j]) ? 2 : 1;
            return;
        }

        // recursion
        Compute(i+1, j);
        Compute(i, j-1);
        Compute(i+1, j-1);

        // DP
        f[i][j] = max(f[i+1][j], f[i][j-1]);
        if (s[i] == s[j]){
            f[i][j] = max(f[i][j], f[i+1][j-1]+2);
        }
    }
    int longestPalindromeSubseq(string &ss) {
        // write your code here
        // s = ss;
        for (int i=0;i<ss.size();i++){
            s[i] = ss[i];
        }
        // s(ss.begin(), ss.end());
        int n = s.size();
        if (n == 0 || n == 1){
            return n;
        }

        // f = new int[n][n]; 
        for (int i=0;i<n;i++){
            for(int j=i;j<n;j++){
                f[i][j] = -1; // not computed yet
            }
        }

        Compute(0, n-1);
        return f[0][n-1];// 返回的是从index 0开始到index=n-1的字符串的性质
    }
};

int main(){
    string s = "bbbab";
    int result = Solution().longestPalindromeSubseq(s);
    cout << "result = " << result << endl;
}
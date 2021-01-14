#include<iostream>
#include<string>
#include<vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    /**
     * @param nums: An integer array
     * @return: The length of LIS (longest increasing subsequence)
     */
    int longestIncreasingSubsequence(vector<int> &nums) {
        // write your code here
        int n = nums.size();
        if (n == 0){
            return 0;
        }

        int f[n];
        int pi[n]; // 开一个pi数组用于打印最长子序列
        int p = 0;
        int result = 0;

        for (int j=0;j<n;j++){
            f[j] = 1; // case 1(只有一个的情况);
            pi[j] = -1; // f[j] = 1的话就认为前一个没有
            for (int i=0;i<j;i++){
                if (nums[i] < nums[j]){
                    f[j] = max(f[i]+1, f[j]); // case 2
                    if (f[i]+1 == f[j]){
                        // pi[j] = i即符合条件时，pi[j]记录的是值小于f[j]的f[i]的index
                        pi[j] = i; 
                    }
                }
            }
            result = max(result, f[j]);
            if (f[j] == result){
                p = j; //如果result更新了的话，p用来记录以哪个元素index结尾的
            }
        }
        int seq[result];
        for (int i=result-1;i>=0;i--){
            seq[i] = nums[p];
            // index p记录的是结尾的数据f[j]的index，而pi[p]记录的是f[j]的前面的元素f[i]的index
            p = pi[p]; 
        }

        cout << "seq = " << endl;
        for (int i=0;i<result;i++){
            cout << seq[i] << " ";
        }
        return result;
    }
};

int main(){
    int temp[6] = {4, 2, 4, 5, 3, 7};
    vector<int> nums(temp, temp+6);
    Solution s;
    s.longestIncreasingSubsequence(nums);
}
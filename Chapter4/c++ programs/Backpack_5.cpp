// 背包问题中数组大小和总称重有关
#include<iostream>
#include<string>
#include<vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    /**
     * @param nums: an integer array and all positive numbers
     * @param target: An integer
     * @return: An integer
     */
    int backPackV(vector<int> &nums, int target) {
        // write your code here
        // write your code here
        int n = nums.size();
        if (n == 0){
            return 0;
        }

        int f[target+1];

        f[0] = 1; // f[0][0]=1; f[0][1]=0; f[0][2]=0
        for (int i=1;i<=target;i++){
            f[i] = 0;
        }

        for (int i=1;i<=n;i++){
            for (int j=target;j>=0;j--){
                if (j>=nums[i-1]){
                    // old + old = new
                    f[j] += f[j-nums[i-1]];
                }
            }
        }
        return f[target];
    }
};
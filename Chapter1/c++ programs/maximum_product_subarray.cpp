//最值型动态规划
#include<iostream>
#include<string>
#include<vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    /**
     * @param nums: An array of integers
     * @return: An integer
     */
    int maxProduct(vector<int> &nums) {
        /*
         * 确定状态：对于最优状态(乘积最大)，一定有最后一个元素a[j]
         * 1. 情况一：最优的序列就只有一个元素a[j]，那么乘积最大的结果就是a[j]
         * 2. 情况二：连续序列的长度大于1，那么最优策略中a[j]肯定有前一个元素a[j-1]，但是：
         *      - 2.1 a[j]为正数，那么我们希望以a[j-1]结尾的连续子序列乘积最大；
         *      - 2.2 a[j]为负数，那么我们希望以a[j-1]结尾的连续子序列乘积最小；
         */
        int n = nums.size();
        int result = INT_MIN;
        if (n==0){
            return 0;
        }
        int f[n];
        int g[n]; // 用来辅助求出f最大乘积结果的数组
        for (int i = 0;i < n;i++){
            // 方式1：
            f[i] = nums[i];
            if(i > 0){
                if (nums[i] >= 0){
                    f[i] = max(f[i], nums[i]*f[i-1]);
                }
                else{
                    f[i] = max(f[i], nums[i]*g[i-1]);
                }
            }

            g[i] = nums[i];
            if (i > 0){
                if (nums[i] >= 0){
                    g[i] = min(g[i], nums[i]*g[i-1]);
                }
                else{
                    g[i] = min(g[i], nums[i]*f[i-1]);
                }
            }
            result = max(result, f[i]);

        // 方式2：
        //     f[i] = nums[i];
        //     if (i > 0){
        //         f[i] = max(f[i], max(nums[i]*f[i-1], nums[i]*g[i-1]));
        //     }

        //     g[i] = nums[i];
        //     if (i > 0){
        //         g[i] = min(g[i], min(nums[i]*f[i-1], nums[i]*g[i-1]));
        //     }
        //     result = max(result, f[i]);
        // }
        }
        return result;
    }
};

int main(){
    Solution s;
    int temp[] = {-1, 2, 4, 1};
    int array_nums = sizeof(temp)/sizeof(temp[0]);
    vector<int> nums(temp, temp+array_nums);
    int result = s.maxProduct(nums);
    cout << boolalpha << "result = " << result << endl;
}
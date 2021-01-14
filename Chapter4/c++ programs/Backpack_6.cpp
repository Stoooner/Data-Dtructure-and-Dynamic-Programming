#include<iostream>
#include<string>
#include<vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    /**
     * @param nums: an integer array and all positive numbers, no duplicates
     * @param target: An integer
     * @return: An integer
     */
    int backPackVI(vector<int> &nums, int target) {
        // write your code here
        int f[target+1];
        int i, j;
        f[0] = 1;
        for (i=1;i<=target;i++){
            f[i] = 0;
            for (j=0;j<nums.size();j++){
                if (i>=nums[j]){
                    f[i] += f[i-nums[j]];
                }
            }
        }
        return f[target];
    }
};
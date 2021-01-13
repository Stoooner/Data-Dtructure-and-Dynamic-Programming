#include<iostream>
#include<string>
#include<vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    /**
     * @param nums: An array of non-negative integers.
     * @return: The maximum amount of money you can rob tonight
     */
    int houseRobber(vector<int> &A) {
        // write your code here
        int n = A.size();
        if (n == 0){
            return 0;
        }

        if (n == 1){
            return A[0];
        }

        // 这里old一定要赋值，因此for循环里参与了训练，否则old的数据就是被随机初始化的一个脏数据
        int old=0; // f[0]
        int now = A[0]; // f[1]
        for (int i=2; i<=n;i++){
            // now = f[i-1], old = f[i-2]
            int t = max(now, old+A[i-1]); //f[i]
            old = now; // old = f[i-1]
            now = t; // now = f[i]
        }
        return now;
    }

    int houseRobber2(vector<int> &nums) {
        // write your code here
        int n = nums.size();
        if (n == 0){
            return 0;
        }
        if (n == 1){
            return nums[0];
        }

        vector<int> A(n-1, 0);
        int result = INT_MIN;
        for (int i=0;i<n-1;i++){
            A[i] = nums[i];
        }
        result = max(result, houseRobber(A));

        for (int i=0;i<n-1;i++){
            A[i] = nums[i+1];
        }
        result = max(result, houseRobber(A));
        return result;
    }
};

int main(){
    int temp[] = {3, 6, 4};
    vector<int> nums(temp, temp+3);
    Solution s;
    int result = s.houseRobber2(nums);
    cout << "result = " << result << endl;
}
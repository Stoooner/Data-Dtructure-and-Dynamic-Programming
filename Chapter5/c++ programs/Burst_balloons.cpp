#include<iostream>
#include<string>
#include<vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maxCoins(vector<int>& nums) {
        // i, i+1, ... k, ..., j-1, j
        // 第i号和第j号气球是不能被扎破的(边界)，t是最后被扎破的气球；
        // 因此f[i][j]代表的是扎破第i+1号气球到第j-1号气球能够获得的最多的金币数
        // k来表示中间那个最后被扎破的气球，它的位置需要枚举：i < k < j
        int n = nums.size();
        if (n == 0){
            return 0;
        }

        int A[n+2]; // 之所以是n+2大小是因为最左边和最右边两个边界气球的存在
        A[0] = A[n+1] = 1; // 两个边界气球的金币为1；
        int i, j, k, len;
        for (i=0;i<n;i++){
            // nums: 0-->n-1为实际的气球
            // f: 1-->n为实际的气球
            A[i+1] = nums[i];
        }

        n += 2;
        int f[n][n];
        // 初始化
        for (i=0;i<n-1;i++){
            f[i][i+1] = 0;
        }

        for (len=3;len<=n;len++){
            for (i=0;i<=n-len;i++){
                // 区间长度为len时，对应的区间起始和终止位置为[i, i+len-1]
                j = i + len - 1;
                f[i][j] = INT_MIN;
                // 代表可以扎破的气球中最后被扎破的气球的位置(i+1 <= k <= j-1)
                for (k=i+1;k<j;k++){
                    f[i][j] = max(f[i][j], f[i][k]+f[k][j]+A[i]*A[k]*A[j]);
                }
            }
        }
        return f[0][n-1];
    }
};

int main(){
    int temp[] = {4, 1, 5, 10};
    vector<int> nums(temp, temp+4);
    int result = Solution().maxCoins(nums);
    cout << "result = " << result << endl; 
}
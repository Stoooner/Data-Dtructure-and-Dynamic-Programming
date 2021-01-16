#include<iostream>
#include<string>
#include<vector>
#include <algorithm>
using namespace std;

// O(nlogn)
class Solution {
public:
    /**
     * @param nums: An integer array
     * @return: The length of LIS (longest increasing subsequence)
     */
    int longestIncreasingSubsequence(vector<int> &nums){
        int n = nums.size();
        // b[i] means the minimum A[xx] when f[x] = i;
        // 由于b[i]中i代表的是f[x], 因此可以不用开辟f数组空间了
        int b[n+1]; // 数组b[i]用于存储f值是i时最小的a是谁
        int top = 0; 

        //由于将b[0]设置为无穷小并放在起始位置，因此永远可以找到一个比b[0]大的数放在后面
        b[0] = INT_MIN;

        int i, j=0, start, stop, mid;
        for (i=0;i<n;i++){
            start = 0;
            stop = top;
            while(start <= stop){
                mid = (start + stop) / 2;
                if (b[mid] < nums[i]){
                    j = mid;
                    start = mid + 1;
                }
                else{
                    stop = mid - 1;
                }
            }
            b[j+1] = nums[i];
            if (j+1 > top){
                top = j + 1;
            }
        }
        // b[0], b[1], ..., b[top]
        return top;
    }
};
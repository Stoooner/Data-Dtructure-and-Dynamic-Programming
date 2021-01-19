#include<iostream>
#include<string>
#include<vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    /**
     * @param prices: Given an integer array
     * @return: Maximum profit
     */
    int maxProfit_1(vector<int> &prices) {
        // write your code here
        // 保底策略：什么都不做，利润0
        int n = prices.size();
        if (n == 0){
            return 0;
        }

        int result = 0;
        int min_value = prices[0];// 假定当前最小值是prices[0]
        for(int i=1;i<n;i++){
            result = max(result, prices[i]-min_value);
            min_value = min(min_value, prices[i]); // 时刻维护着min_value是否为最小值
        }

        return result;

    }
};
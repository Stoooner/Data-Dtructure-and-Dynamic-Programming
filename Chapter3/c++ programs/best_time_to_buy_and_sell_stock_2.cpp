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
     * 1、初始化收益为0
     * 2、从左到右遍历，发现当前元素比刚遍历的元素大，即可取得收益，累加结果即为最大收益
     * 我们都知道炒股想挣钱当然是低价买入高价抛出，那么这里我们只需要从第二天开始，
     * 如果当前价格比之前价格高，则把差值加入利润中，因为我们可以昨天买入，今日卖出，
     * 若明日价更高的话，还可以今日买入，明日再抛出。以此类推，遍历完整个数组后即可求得最大利润。
     * 像 [1,2,3,4,5] 最大利润为第五天 - 第一天=4，也可以这么想：第一天买第二天抛，赚了1，
     * 第二天买第三天抛，赚了1，重复下来，最大利润也是4；
     */
    int maxProfit_2(vector<int> &prices){
        // write your code here
        int n = prices.size();
        if (n == 0){
            return 0;
        }
        int result = 0;
        for (int i=0;i<n-1;i++){
            // 上升趋势
            if (prices[i+1] - prices[i] > 0){
                result += (prices[i+1]-prices[i]);
            }
        }

        return result;
    }
};
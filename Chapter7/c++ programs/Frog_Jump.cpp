#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<map>
#include<set>
#include<unordered_map>
using namespace std;

class Solution {
public:
    /**
     * @param stones: a list of stones' positions in sorted ascending order
     * @return: true if the frog is able to cross the river or false
     * 坐标+状态型动态规划
     */
    bool canCross(vector<int> &stones) {
        // write your code here
        // f[i][j]表示能否跳距离j跳到石头a_i
        int n = stones.size();
        // f[stones[i]] is a set, stones[i] is key, set<int> is value.
        // if x is in stones[i], originally, f[stones[i]][x] = True;
        // f[stones[i]][x]代表在石头stones[i]这个地方，最后一跳距离x可以跳到
        map<int, set<int> > f;
        int i, j, delta;
        //initialization
        // for (i=0;i<n;i++){
        //     // 初始化方式1：
        //     f.insert(make_pair(stones[i], set<int>);
        //     // 初始化方式2和3；
        //     // f.insert(piar<int, set<int>>(stones[i], set<int>));
        //     // f[i] = stones[i];
        // }
        // 第0个石头stones[0]可以以0距离跳过去
        f[stones[0]].insert(0);

        for (i=0;i < n-1;i++){
            // si就是集合set：f[stones[i]]
            set<int> si = f[stones[i]];
            // previous jump distance = k;
            for (set<int>::iterator k=si.begin(); k!=si.end();k++){
                // curren jump distance = j, k-1 <= j <= k+1
                for (j=(*k)-1; j<=(*k)+1;j++){
                    if (j <= 0){
                        continue;
                    }

                    if (f.count(stones[i]+j)){
                        f[stones[i]+j].insert(j);
                    }
                }
            }
        }
        return !(f.find(stones[n-1]) == f.end());
    }
};

int main(){
    int temp[] = {0,1,3,5,6,8,12,17};
    vector<int> stones(temp, temp+8);
    bool result = Solution().canCross(stones);
    cout << "result = " << boolalpha <<result << endl;
}
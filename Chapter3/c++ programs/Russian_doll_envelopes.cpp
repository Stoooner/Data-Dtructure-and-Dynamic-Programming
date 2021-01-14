#include<iostream>
#include<string>
#include<vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    /**
     * @param envelopes: a number of envelopes with widths and heights
     * @return: the maximum number of envelopes
     */
    int maxEnvelopes(vector<vector<int>> &envelopes) {
        // write your code here
        if (envelopes.empty() || envelopes.size() == 0){
            return 0;
        }
        int n = envelopes.size();
        int f[n];
        int i, j, result=0;

        for (i=0;i<n;i++){
            f[i] = 1; // case 1
            // case 2: enumerate second outmost envelope
            for (j=0;j<i;j++){
                // both length and width are smaller
                // 长度和宽度要严格小于才能放入，相等情况下也是不行的
                if (envelopes[j][0] < envelopes[i][0] && envelopes[j][1] < envelopes[i][1]){
                    f[i] = max(f[i], f[j]+1);
                }
            }
            result = max(result, f[i]);
        }
        return result;    
    }
};
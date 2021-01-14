#include<iostream>
#include<string>
#include<vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    /**
     * @param n: An integer
     * @return: A boolean which equals to true if the first player will win
     */
    bool firstWillWin(int n) {
        // write your code here
        if (n == 0){
            return false;
        }
        if (n == 1){
            return true;
        }
        bool f[n+1];
        f[0] = false;
        f[1] = true;
        for (int i=2; i <=n ;i++){
            f[i] = (!f[i-1]) || (!f[i-2]);
        }

        for (int i=0;i<=n;i++){
            cout << i << ":" << f[i] << endl;
        }
        return f[n];
    }
};
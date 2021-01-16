#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<map>
#include<set>
#include<unordered_map>
using namespace std;

class Solution {
private:
    long getCnt(char c){
        if (c == '0'){
            return 0;
        }

        if (c == '*'){
            return 9;
        }

        // '1' ~ '9'
        return 1;
    }

    long getCnt2(char c2, char c1){
        if (c2 == '0' || (c2 >= '3' && c2 <= '9')){
            return 0;
        }

        if (c2 == '1'){
            if (c1 == '*'){
                return 9;
            }
            else{
                return 1;
            }
        }
        
        if (c2 == '2'){
            if (c1 >= '0' && c1 <= '6'){
                return 1;
            }
            if (c1 >= '7' && c1 <= '9'){
                return 0;
            }
            // *
            return 6;
        }

        // c2 = '*'的情况
        if (c1 >= '0' && c1 <= '6'){
            return 2;
        }
        if (c1 >= '7' && c1 <= '9'){
            return 1;
        }

        // **
        return 15;
    }

public:
    /**
     * @param s: a message being encoded
     * @return: an integer
     */
    int numDecodings(string &s) {
        // write your code here
        int n = s.size();
        long MOD = 1000000007;
        long c;
        long f[n+1];
        int i, j;
        f[0] = 1; // 前0个字符解码方式为1；
        // 前1个字符到前n个字符
        for (i=1;i<=n;i++){
            f[i] = 0;
            // 定义一个函数用于统计最后一个字符有多少种方式可以翻译成字母
            c = getCnt(s[i-1]);
            f[i] += c * f[i-1];

            if (i > 1){
                c = getCnt2(s[i-2], s[i-1]);
                f[i] += c * f[i-2];
            }
            f[i] = f[i] % MOD;
        }
        return (int)f[n];
    }
};
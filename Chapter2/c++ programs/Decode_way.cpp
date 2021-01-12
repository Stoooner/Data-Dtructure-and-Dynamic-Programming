#include<iostream>
#include<string>
#include<vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    /**
     * @param s: a string,  encoded message
     * @return: an integer, the number of ways decoding
     */
    int numDecodings(string &s) {
        // write your code here
        int n = s.size();
        if (n == 0){
            return 1; // 2. 空串的解码方式是0种还是1种只会影响到这里return的方式，不会影响到下面f[0]=1的设定
        }
        int f[n+1];
        f[0] = 1; // 1. 这个地方必须将f[0]设定为1，否则后面所有结果都是0
        int j;
        for (int i=1;i<=n;i++){
            f[i] = 0;
            if (s[i-1] >= '1' && s[i-1] <= '9'){
                f[i] += f[i-1];
            }
            // check whether i > 1
            if (i > 1){
                j = 10*(s[i-2]-'0') + (s[i-1]-'0');
                if (s[i-2] != '0' && j >=10 && j <= 26){
                    f[i] += f[i-2];
                }  
            }
        }
        return f[n];
    }
};

int main(){
    string s = "12";
    Solution so;
    int result = so.numDecodings(s);
    cout << "result = " << result << endl;
}

// 存在型动态规划
#include<iostream>
#include <typeinfo>
#include<string>
#include<vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    /**
     * @param A: A list of integers
     * @return: A boolean
     */
    bool canJump(vector<int> &A) {
        // write your code here
        if (A.empty() || A.size() == 0){
            return false;
        }
        int n = A.size();
        bool f[n];
        // stone 1: A[0]
        // stone 2: A[1]
        // ...
        // stone n: A[n-1]
        // 初始化条件
        f[0] = true;
        for (int j = 1;j < n;j++){
            // previous stone(last step)
            f[j] = false;
            for (int i = 0;i < j;i++){
                // i + A[i]只要大于等于j就可以了，因此A[i]代表的是能跳的最大距离，但是不一定非得跳到最大距离
                if (f[i] && i + A[i] >= j){
                    f[j] = true;
                    break;
                }
            }
        }
        return f[n-1];
    }
};

int main(){
    int temp[] = {3,2,1,0,4};
    int array_nums = sizeof(temp)/sizeof(temp[0]);
    cout << "array_nums = " << array_nums <<endl;
    vector<int> A(temp, temp+5);//开始位置和超尾位置
    Solution s;
    bool result = s.canJump(A);
    cout << "A[0] = " << A[0] << endl;
    cout << "result_type: " <<typeid(result).name() << endl;
    // 要想把bool型输出成true或者false 而不是 1,0的话，可以使用boolalpha
    cout << boolalpha << "result = " << result << endl;
}
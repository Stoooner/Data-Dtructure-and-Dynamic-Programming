#include<iostream>
#include<string>
#include<vector>
using namespace std;

class Solution {
public:
    /**
     * @param A: an array
     * @return: the number of arithmetic slices in the array A.
     */
    int numberOfArithmeticSlices(vector<int> &A) {
        // Write your code here
        int n = A.size();
        if (n < 3){
            return 0;
        }

        // 由于要形成连续的等差子数组，因此数组元素的个数至少要有三个
        int f[n];
        int sum = 0;
        for (int i=0;i<n;i++){
            if (i==0 || i==1){
                f[i] = 0;
                continue;
            }
            if (A[i] - A[i-1] == A[i-1] - A[i-2]){
                f[i] = f[i-1] + 1;
                sum += f[i];
            }
        }
        return sum;
    }
};

int main(){
    int temp[] = {1,2,3,8,9,10};
    vector<int> A(temp, temp+6);
    int result = Solution().numberOfArithmeticSlices(A);
    cout << "result = " << result << endl;
}
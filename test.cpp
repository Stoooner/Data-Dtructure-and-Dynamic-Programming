#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<map>
#include<set>
#include<unordered_map>
using namespace std;

/*
class Solution {
public:
    bool canCross(vector<int> &stones) {
        int n = stones.size();
        map<int, set<int> > f;
        int i, j, delta;

        for (i=0;i<n;i++){
            set<int> i;
            f[stones[0]] = i;
        }
        f[stones[0]].insert(0);

        for (i=0;i<n;i++){
            // set<int> si = f[stones[i]];
            for (set<int>::iterator k=f[stones[i]].begin(); k!=f[stones[i]].end();k++){
                for (delta=-1; delta<=1;delta++){
                    int t = stones[i] + ((*k) + delta);
                    if (f.count(t)){
                        f[t].insert((*k) + delta);
                    }
                }
            }
        }
        
        cout << "func f: " << endl;
        for (map<int, set<int> >::iterator itm=f.begin();itm!=f.end();itm++){
            cout << "stone: " << itm->first << endl;
            for (set<int>::iterator its=f[itm->first].begin();its!=f[itm->first].end();its++){
                cout << (*its) << " ";
            }
        }
        cout << endl;
        
        return !(f[stones[n-1]].empty());
        // return !(f.find(stones[n-1]) == f.end());
    }
};*/

class Solution {
public:
    bool canCross(vector<int> &stones) {
        int n = stones.size();
        map<int, set<int> > f;
        int i, j, delta;

        // for (i=0;i<n;i++){
        //     set<int> i;
        //     f[stones[0]] = i;
        // }

        f[stones[0]].insert(1);

        for (i=0;i<n;i++){
            // set<int> si = f[stones[i]];
            for (set<int>::iterator k=f[stones[i]].begin(); k!=f[stones[i]].end();k++){
                for (delta=-1; delta<=1;delta++){
                    int t = stones[i] + ((*k) + delta);
                    if (f.count(t)){
                        // cout << "t = " << t << endl;
                        // cout << "(*k) + delta = " << (*k) + delta << endl;
                        f[t].insert((*k) + delta);
                    }
                }
            }
        }        
        return !(f[stones[n-1]].empty());
    }
};

int main(){
    int temp[] = {0,1,3,5,6,8,12,17}; // true
    vector<int> stones(temp, temp+8);
    bool result = Solution().canCross(stones);
    cout << "result = " << boolalpha <<result << endl;
}
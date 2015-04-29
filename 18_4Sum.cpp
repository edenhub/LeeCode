#include <iostream>
#include <cmath>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int> > fourSum(vector<int> &num, int target) {
        int size = num.size();
        vector<vector<int> > res;
        if(size < 4) return res;
        if(size == 4){
            int sum = 0;
            vector<int>::iterator iter = num.begin();
            vector<int> tmp;
            while(iter != num.end()){
                sum += *iter;
                tmp.push_back(*iter);
                iter++;
            }

            if(sum == target){
                sort(tmp.begin(),tmp.end());
                res.push_back(tmp);
            }

            return res;
        }

        sort(num.begin(),num.end());
        set<vector<int> > cnt;
        for(int i=0;i<size;i++){
            //warning:skip the dumplicate num
            if(i>0 && num[i-1] == num[i]) continue;

            threeSum(num,target-num[i],i+1,cnt);
        }

        set<vector<int> >::iterator iter = cnt.begin();
        while(iter != cnt.end()){
            res.push_back(*iter); iter++;
        }

        return res;
    }


    void threeSum(vector<int> &num,int target,int idx,set<vector<int> > &res){
        for(int i=idx;i<num.size();i++){
            int s = i+1,e = num.size()-1;

            while(s < e){
                int curr = num[i]+num[s]+num[e];
                if(curr == target){
                    vector<int> tmp;
                    tmp.push_back(num[i]); tmp.push_back(num[s]);
                    tmp.push_back(num[e]); tmp.push_back(num[idx-1]);
                    sort(tmp.begin(),tmp.end());
                    res.insert(tmp);
                    
                    //warning:skip the dumplicate num
                    while(s<e && num[s-1] == num[s]) s++;
                    while(s<e && num[e] == num[e-1]) e--;
                    s++; e--;

                }else if(curr > target) e--;
                else s++;
            }
        }
    }
};


int main(){
    Solution s;
    vector<int> num;
    num.push_back(1);num.push_back(-1);num.push_back(-1);num.push_back(0);
    num.push_back(-4);num.push_back(2);

    vector<vector<int> > res = s.fourSum(num,-1);
    cout<<res.size()<<endl;

    return 0;
}
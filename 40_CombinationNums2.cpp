#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

class Solution {
public:
    vector<vector<int> > combinationSum2(vector<int>& candidates, int target) {
            sort(candidates.begin(),candidates.end());
            vector<int> st;
            vector<vector<int> > res;
            combin(candidates,target,0,0,st);

            set<vector<int> >::iterator iter = cnt.begin();
            while(iter != cnt.end()){
                res.push_back(*iter);
                iter++;
            }


            return     res;
    }

private:
    void combin(vector<int>& candidates,int target,int start,int curr,vector<int>& st){
        if(curr == target){
            sort(st.begin(),st.end());
            cnt.insert(st);
            return;
        }else if(curr > target) return;

        for(int i=start;i<candidates.size() && (curr + candidates[i] <= target); i++){
            curr += candidates[i];
            st.push_back(candidates[i]);
            combin(candidates,target,i+1,curr,st);
            curr -= candidates[i];
            st.pop_back();
        }
    }

    set<vector<int> > cnt;
};

int main(){
    // 10,1,2,7,6,1,5
    vector<int> candidates;
    candidates.push_back(10);candidates.push_back(1);candidates.push_back(2);candidates.push_back(7);
    candidates.push_back(6);candidates.push_back(1);candidates.push_back(5);

    int target=8;
    Solution s;
    vector<vector<int> > res = s.combinationSum2(candidates,target);
    vector<vector<int> >::iterator iterOut = res.begin();
    while(iterOut != res.end()){
        vector<int> curr = *iterOut;
        vector<int>::iterator iterIn = curr.begin();
        while(iterIn != curr.end())
            cout<<*iterIn++<<" ";
        cout<<endl;
        iterOut++;
    }
    return 0;
}
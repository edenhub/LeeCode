#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int> > combinationSum(vector<int>& candidates, int target) {
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
            // sort(st.begin(),st.end());
            cnt.insert(st);
            return;
        }else if(curr > target) return;

        for(int i=start;i<candidates.size() && (curr + candidates[i] <= target); i++){
            curr += candidates[i];
            st.push_back(candidates[i]);
            combin(candidates,target,i,curr,st);
            curr -= candidates[i];
            st.pop_back();
        }
    }

    set<vector<int> > cnt;
};

int main(){

vector<int> candidates;
    candidates.push_back(2);candidates.push_back(3);candidates.push_back(6);candidates.push_back(7);


    int target=7;
    Solution s;
    vector<vector<int> > res = s.combinationSum(candidates,target);
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
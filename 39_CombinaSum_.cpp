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
        innerOp(candidates,target,0,st);

        return ret;
    }

private:

    void innerOp(vector<int>& candidates,int target,int start,vector<int>& st){
        if(target == 0){
            ret.push_back(st);
            return;
        }else if(target < 0) return;

        for(int i=start;i<candidates.size(); i++){
            if(candidates[i] > target) break;

            st.push_back(candidates[i]);
            innerOp(candidates,target-candidates[i],i,st);
            st.pop_back();
        }
    }

    vector<vector<int> > ret;
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

    return 0;
}
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int> > subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int len = nums.size();
        vector<vector<int> > ret;
        vector<int> empty; ret.push_back(empty);
        if(len == 0) return ret;
        // vector<int> init; init.push_back(nums[0]); ret.push_back(init);
        // if(len == 1) return ret;

        int idx=0;
        for(int i=0;i<len;i++){
            int cnt = ret.size();
            int curr = nums[i];
            // int loop=0;
            for(int j=idx;j<cnt;j++){
                vector<int>  tmp = ret[j];
                tmp.push_back(curr);
                // loop++;
                ret.push_back(tmp);
            }
            if(i+1<len && nums[i] == nums[i+1]) idx = cnt;
            else idx = 0;
        }

        return ret;
    }
};

int main(){
        vector<int> nums;
    nums.push_back(1);nums.push_back(1);
    // nums.push_back(2);nums.push_back(2);nums.push_back(3);

    Solution s;

    vector<vector<int> > ret = s.subsetsWithDup(nums);
    int size = ret.size();
    for(int i=0;i<size;i++){
        vector<int> tmp = ret[i];
        int cnt = tmp.size();
        for(int j=0;j<cnt;j++)
            cout<<tmp[j]<<" ";
        cout<<endl;
    }

    return 0;
}
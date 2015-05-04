#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int> > subsets(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int size = nums.size();
        vector<vector<int> > ret;
        vector<int> empty; ret.push_back(empty);
        if(size == 0) return ret;
        vector<int> init; init.push_back(nums[0]); ret.push_back(init);
        if(size == 1) return ret;


        for(int i=1;i<size;i++){
            int cnt = ret.size();
            int curr = nums[i];
            for(int j=0;j<cnt;j++){
                vector<int> tmp = ret[j];
                tmp.push_back(curr);
                ret.push_back(tmp);
            }
        }

        return ret;
    }
};

int main(){
    vector<int> nums;
    nums.push_back(1);nums.push_back(2);nums.push_back(2);

    Solution s;

    vector<vector<int> > ret = s.subsets(nums);
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
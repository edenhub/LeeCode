#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ret = nums[0];

        for(int i=1;i<nums.size();i++)
            ret ^= nums[i];

        return ret;
    }
};

int main(){
    int T; cin>>T;
    vector<int> nums;
    while(T--){
        int n; cin>>n;
        nums.push_back(n);
    }

    Solution s;
    int ret = s.singleNumber(nums);

    cout<<ret<<endl;

    return 0;
}
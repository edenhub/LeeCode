#include <iostream>
#include <vector>
#include <sstream>

using namespace std;

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int size = nums.size()-1;
        int bound = size;
        for(int i=size-1;i>=0;i--){
            bound = (nums[i]+i >= bound) ? i : bound;
        }

        return bound == 0;
    }
};

int main(){
    int T=7;
    istringstream is("1,1,2,2,0,1,1");
    vector<int> nums;
    while(T--){
        int n; is>>n;
        char dot; is>>dot;
        nums.push_back(n);
    }

    Solution s;
    bool res = s.canJump(nums);

    cout<<res<<endl;

    return 0;
}
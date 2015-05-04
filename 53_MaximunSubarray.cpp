#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int size = nums.size();
        if(size == 0) return 0;
        if(size == 1) return nums[0];

        int currSum=nums[0],ret=currSum;

        for(int i=1;i<size;i++){
            if(currSum < 0) currSum = nums[i];
            else currSum += nums[i]; 

            ret = max(currSum,ret);
        }

        return ret;
    }
};
// 


int main(){
// −2,1,−3,4,−1,2,1,−5,4
    int T; cin>>T;
    vector<int> nums;
    while(T-->0){
        int t; cin>>t;
        nums.push_back(t);
    }
    Solution s;
    int ret =  s.maxSubArray(nums);

    cout<<ret<<endl;

    return 0;
}
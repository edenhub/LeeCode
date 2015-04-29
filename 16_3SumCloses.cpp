#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;


class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int size = nums.size();
        if(size < 3) return 0;

        int sum = nums[0] + nums[1] + nums[size-1];
        sort(nums.begin(),nums.end());

        for(int i=0;i<size;i++){
            //warning : like the 3Sum,we can skip the same and the previous nums
            int j = i+1,k = size-1;
            while(j < k){
                int curr = nums[i] + nums[j] + nums[k];
                if( abs(curr - target) < abs(sum - target) ) sum = curr;
                if(curr > target) k--;
                else j++;
            }
        }

        return sum;
    }

};

int main(){
    vector<int> nums;
    nums.push_back(-1); nums.push_back(2); nums.push_back(1); nums.push_back(-4);
    Solution s;
    int res = s.threeSumClosest(nums,1);
    cout<<res<<endl;

    return 0;
}
#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

class Solution {
public:
    int rob(vector<int>& nums) {
    	int len = nums.size();
    	if(len == 0) return 0;
    	if(len == 1) return nums[0];
    	if(len == 2) return max(nums[0],nums[1]);
    	int ret = max(nums[0],nums[1]);
    	int rets[len+1];
    	rets[0] = nums[0];
    	rets[1] = max(nums[0],nums[1]);

    	for(int i=2;i<nums.size();i++){
    		ret = max(rets[i-1],rets[i-2]+nums[i]);
    		rets[i] = ret;
    	}

    	return ret;
    }


};

int main(){
	vector<int> v;
	v.push_back(2);
	v.push_back(1);
	v.push_back(1);

	Solution s = Solution();
	int ret = s.rob(v);

	cout<<ret<<endl;


	return 0;
}
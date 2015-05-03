#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int findMin(vector<int>& nums) {
        int size = nums.size();

        int L = 0, R = size-1;
        if(nums[R] > nums[L]) return nums[L];

        while(L < R){
            int M = (L + R) / 2;
            if(nums[M] == nums[R] || nums[M] == nums[L]){
                int mi=nums[L];
                for(int i=L+1;i<=R;i++){
                    mi = min(mi,nums[i]);
                }

                return mi;
            }else if(nums[M] > nums[R]) L = M +1;
            else R = M;
        }

        return nums[L];
    }
};

int main(){
    int const size = 7;
    vector<int> nums;
    nums.push_back(4);
    nums.push_back(4);
    nums.push_back(4);
    nums.push_back(4);
    nums.push_back(0);
    nums.push_back(1);
    nums.push_back(2);
    nums.push_back(4);

    Solution s;
    int res = s.findMin(nums);

    cout<<res<<endl;

    return 0;
}
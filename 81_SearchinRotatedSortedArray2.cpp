#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int size = nums.size();
        int L=0,R=size-1;

        if(target < nums[L] && target > nums[R]) return false;
//generate,binary search can not let L equals R,think about only one input [1]
        while(L < R){
            int M = (L + R) / 2;
            if(target == nums[M]) return true;
            else if(nums[L] == nums[R]){
                 for(int i=L;i<=R;i++)
                    if(nums[i] == target) return true;
                return false;
            }
            else{
                if(nums[M] <= nums[R]){
                    if(nums[M] < target && target <= nums[R]) L = M+1;
                    else R = M;
                }else{
                    if(nums[L] <= target && target <= nums[M]) R = M;
                    else L = M+1;
                }
            }
        }

        if(nums[L] == target) return true;
        else return false;
    }
};

int main(){
    vector<int> nums;
    int T; cin>>T;
    while(T--){
        int n; cin>>n; nums.push_back(n);
    }
    Solution s;
    int target; cin>>target;
    bool res = s.search(nums,target);
    cout<<res<<endl;
    return 0;
}
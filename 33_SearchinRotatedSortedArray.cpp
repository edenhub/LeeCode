#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int size = nums.size();

        int low = 0,high = size-1;

        while(low <= high){
            int mid = (low + high) /2;
            // cout<<low<<" "<<high<<endl;
            if(target == nums[mid]) return mid;
            if(target < nums[mid]){
                if(nums[low] <= target && nums[low] < nums[mid]) high =  mid-1;
                else low = mid+1;
            }else{
                if(nums[mid] < nums[high] && nums[low] < nums[high]) low =  mid+1;
                else high = mid-1;
            }
        }

        return -1;
    }
};

int main(){
    vector<int> nums;
    int T; cin>>T;
    while(T--){
        int n; cin>>n; nums.push_back(n);
    }
    int target; cin>>target;
    Solution s;
    int res = s.search(nums,target);
    cout<<res<<endl;
    return 0;
}
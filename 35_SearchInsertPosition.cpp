#include <iostream>
#include <vector>

using namespace std;
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int low = 0, high = nums.size()-1;

        if(nums[high] < target) return nums.size();
        if(nums[low] > target) return 0;


        int mid;

        while(low <= high){
            mid = (low + high) / 2;

            if(nums[mid] == target){ return mid;}
            else if(nums[mid] > target) high = mid-1;
            else low = mid+1;
        }
        //the array is sorted,use binary search,final the low is add one step than target,return it
        return low;
    }
};

int main(){
    vector<int> nums;
    nums.push_back(1);
    nums.push_back(3);
    nums.push_back(5);nums.push_back(6);
    Solution s;
    int res = s.searchInsert(nums,7);
    cout<<res<<endl;

    return 0;
}
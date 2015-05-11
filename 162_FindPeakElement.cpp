#include <iostream>
#include <vector>
#include <sstream>

using namespace std;

class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int size = nums.size();

        if(size == 1) return 0;
        if(size == 2) return (nums[0] > nums[1]) ? 0 : 1;

        if(nums[0] > nums[1]) return 0;
        if(nums[size-1] > nums[size-2]) return size-1;

        int low = 0, high = size-1;

        while(low < high){
            int mid = (low + high) / 2;

            if((mid==1 && nums[mid] > nums[mid+1]) ||
                (mid==size-1 && nums[mid] > nums[mid-1]) ||
                (nums[mid] > nums[mid+1] && nums[mid] > nums[mid-1]) ) return mid;
            else if((mid==1 && nums[mid] < nums[mid+1]) ||
                (nums[mid] > nums[mid-1] && nums[mid] < nums[mid+1])) low = mid+1;
            else high = mid-1;
        }

        return low;
    }
};

int main(){
    istringstream is("3,2,1b");
    vector<int> nums;

    int T; cin>>T;
    while(T--){
        int n; is>>n;
        char dot; is>>dot;
        nums.push_back(n);
    }

    Solution s;
    int res = s.findPeakElement(nums);

    cout<<res<<endl;

    return 0;
}
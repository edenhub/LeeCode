#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int findMin(vector<int>& nums){
        int size = nums.size();
        int L = 0,R = size-1;

        while(L < R){
            int M = (L + R) /2 ;
            if(nums[M] > nums[R]) L = M+1;
            else if(nums[M] < nums[R]) R = M; 
        }

        return nums[L];
    }
    int findMin2(vector<int>& nums) {
        int size = nums.size();
        int L = 0, R = size-1;

        if(nums[R] > nums[L]) return nums[L];

        while(nums[L] > nums [R]){
            int M = (L + R) / 2;
            if(nums[M] == nums[L]){
                if(nums[R] > nums[L]) return nums[L];
                else return nums[R];
            }else if(nums[L] < nums[M]) L = M;
            else R = M;
        }

        return nums[L];
    }
};
int main(){
   int const size = 7;
    vector<int> nums;
    nums.push_back(4);
    nums.push_back(5);
    nums.push_back(6);
    nums.push_back(7);
    nums.push_back(0);
    nums.push_back(1);
    nums.push_back(2);

    Solution s;
    int res = s.findMin(nums);

    cout<<res<<endl;
    return 0;
}
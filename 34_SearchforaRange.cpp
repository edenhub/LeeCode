#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> res;
        int fir=-1,sec=-1;

        int s=0,e=nums.size()-1;

        while(s <= e){
            int mid = (s + e) / 2;
            if(nums[mid] == target){
                if(mid == 0 || nums[mid-1] != target) {
                    fir = mid;
                    break;
                }
                e = mid-1;
            }else if(nums[mid] < target) s = mid+1;
            else e = mid-1;
        }
        s=0,e=nums.size()-1;
        while(s <= e){
            int mid = (s + e) / 2;
            if(nums[mid] == target){
                if(mid == e || nums[mid+1] != target){
                    sec = mid;
                    break;
                }
                s = mid+1;
            }else if(nums[mid] < target) s= mid+1;
            else e = mid-1;
        }

        res.push_back(fir); res.push_back(sec);
        cout<<fir<<" "<<sec<<endl;
        return res;
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
   s.searchRange(nums,target);

    return 0;
}
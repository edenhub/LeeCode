#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

#include <limits.h>
using namespace std;

const int MAX_VAL=2147483647;

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int size = nums.size();
        if(size <=3 ){
            vector<int>::iterator iter = nums.begin();
            int tmp=0;
            while(iter != nums.end()){
                 tmp += *iter;
                 iter++;
            }

            return tmp;
        }

        int minDiff = MAX_VAL,res;

        sort(nums.begin(),nums.end());
        for(int i=0;i<size;i++){
            // swap(nums[i],nums[size-1]);
            int subTgt = target - nums[i];
            subTgt = twoSumCLosest(nums,size,i,subTgt);
            if( abs(subTgt+nums[i] - target) <= minDiff){
                res = subTgt+nums[i];
                minDiff = abs(subTgt+nums[i] - target);
            }
            // swap(nums[i],nums[size-1]);
        }

        return res;
    }

    int twoSumCLosest(vector<int>& nums,int len,int ignore,int target){
        int minDiff=MAX_VAL,res=0;
        int s=0,e=len-1;
        while(s<=e){
            cout<<s<<" "<<e<<endl;
            if(s == ignore) {s++;continue;}
            if(e == ignore) {e--;continue;}
            int curr = nums[s]+nums[e];

            if(curr == target){
                return target;
            }else if(curr < target){
                if( abs(target-curr) < minDiff ){
                  // cout<<minDiff;
                    res=curr;
                    minDiff = abs(target - curr);
                }
                s++;
            }else{
                if( abs(target-curr) < minDiff){
                    res = curr;
                    minDiff = abs(target - curr);
                }
                e--;
            }
        }

        return res;
    }
};

int main(){
    vector<int> nums;
    nums.push_back(-1);nums.push_back(2);nums.push_back(1);nums.push_back(-4);

    Solution s;
    int res = s.threeSumClosest(nums,1);
    cout<<res<<endl;

    return 0;
}
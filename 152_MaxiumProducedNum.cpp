#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
     int maxProduct(vector<int>& nums) {
        int size = nums.size();
        int ret = nums[0], lastMax = ret, lastMin = ret;

        for(int i=1;i<size;i++){
            int tmpMax = nums[i] * lastMax;
            int tmpMin = nums[i] * lastMin;

            if(tmpMax > tmpMin){
                lastMax = max(nums[i],tmpMax);
                lastMin = min(nums[i],tmpMin);
            }else{
                lastMax = max(nums[i],tmpMin);
                lastMin = min(nums[i],tmpMax);
            }

            ret = max(lastMax,ret);

        }

        return ret;
    }
};

int main(){

    return 0;
}
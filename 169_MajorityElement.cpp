#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int size = nums.size();
        if(size <= 2) return nums[0];

        int tmp=nums[0],cnt=1;

        for(int i=1;i<size;i++){
            int curr = nums[i];
            if(cnt == 0) {tmp = curr; cnt=1;}
            else if(tmp != curr) cnt--;
            else cnt++;
        }

        return tmp;
    }
};

int main(){

    return 0;
}
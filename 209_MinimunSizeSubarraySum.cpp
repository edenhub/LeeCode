#include <iostream>
#include <vector>
#include <sstream>

using namespace std;

const int MAX=2147483647;

class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        int size = nums.size();
        if(size == 0 || (size == 1 && nums[0] < s) ) return 0;

        int left=0,right=0,min=MAX,sum=0;

        while(left < size && right < size){
            while(sum < s && right < size){
                sum += nums[right++];
            }

            while(sum >= s && left <= right){
                min = (min > (right - left)) ? (right - left) : min;
                sum -= nums[left++]; 
            }
        }

        return min == MAX ? 0 : min;
    }
};

int main(){
    stringstream ss("10,2,3");
    int size = 3;
    vector<int> nums;
    for(int i=0;i<size;i++){
        int n; ss>>n;
        char dot; ss>>dot;
        nums.push_back(n);
    }

    int s=7;

    Solution so;

   
    int min = so.minSubArrayLen(s,nums);

    cout<<min<<endl;

    return 0;
}
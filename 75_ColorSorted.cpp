#include <iostream>
#include <vector>
#include <sstream>

using namespace std;

class Solution {
public:
    void sortColors(vector<int>& nums) {
        quickSort(nums,0,nums.size()-1);
    }

private:
    void quickSort(vector<int>& nums,int s,int e){
        if(s>=e) return;
        int idx = partition(nums,s,e);
        quickSort(nums,s,idx);
        quickSort(nums,idx+1,e);
    }

    int partition(vector<int>& nums,int s,int e){
        int low = s, high = e;
        int tmp = nums[s];

        while(low < high){
            while(low< high && nums[high] >= tmp) high--;
            nums[low] = nums[high];
            while(low<high && nums[low] <= tmp) low++;
            nums[high] = nums[low];
        }

        nums[low] = tmp;
        return low;
    }
};

int main(){
    stringstream inStream("1");
    vector<int> in,post;

    while(!inStream.eof()){
        int n; inStream>>n;
        char dot; inStream>>dot;
        in.push_back(n);
    }

    Solution s;
    s.sortColors(in);

    vector<int>::iterator iter = in.begin();
    while(iter != in.end()) cout<<*iter++<<" ";
    cout<<endl;

    return 0;
}
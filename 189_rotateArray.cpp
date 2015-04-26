    #include <iostream>
    #include <algorithm>

    using namespace std;

    class Solution {
    public:
        void rotate(int nums[], int n, int k) {
                //warning : check if the list is ok
                //and check if the k is larger than n,if it is ,then let k %=n
                if(n==0 || k==0)  return;
                k%=n;
                reverse(nums,0,n-1);
                reverse(nums,0,k-1);
                reverse(nums,k,n-1);
        }

        void reverse(int nums[],int s,int e){
            while(s <= e){
                swap(nums[s++],nums[e--]);
            }
        }
    };

int main(){
    int nums[7]={1,2,3,4,5,6,7};
    Solution s;
    s.rotate(nums,7,3);
    for(int i=0;i<7;i++)
        cout<<nums[i]<<" ";
    return 0;
}
#include <iostream>

using namespace std;

class Solution {
public:
    int removeDuplicates(int A[], int n) {
        if(n == 0) return 0;
        if(n == 1) return 1;
        int idx=1,next=0;
        //pt1 point to the next index
        //pt2 point to the curr index;
        for(;next<n;next++){
            if(A[idx-1] != A[next]){
                A[idx++] = A[next];
            }
        }

        return idx;
    }
};

int main(){
    Solution s;
    int size = 5;
    int A[] = {1,1,2,2,3};

    cout<<s.removeDuplicates(A,size);

    return 0;
}
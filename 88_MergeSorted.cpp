#include <iostream>

using namespace std;

class Solution {
public:
    void merge(int A[], int m, int B[], int n) {
        int k=m+n-1,pa=m-1,pb=n-1;

        while(pa>=0 && pb>=0){
            if(A[pa] > B[pb]) A[k--] = A[pa--];
            else A[k--] = B[pb--];
        }

        while(pa>=0){
            A[k--] = A[pa--];
        }

        while(pb>=0){
            A[k--] = B[pb--];
        }
    }
};

int main(){
    

    return 0;
}
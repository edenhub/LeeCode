#include <iostream>
#include <algorithm>
using namespace std;

class Solution {
public:
    int removeElement(int A[], int n, int elem) {
        n-=1;

        for(int i=0;i<=n;i++){
            if(A[i] == elem){
                swap(A[i],A[n]);
                n--;
                //warning : the last element may equal to elem,so the i must minus 1
                i--;
            }
        }

        return n+1;
    }
};

int main(){

    return 0;
}
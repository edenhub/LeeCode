#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int removeDuplicates(int A[], int n) {
        if(n<=2) return n;
        int k=1, cnt=1,i=1;

        while(i < n){
            if(A[i] != A[i-1]){
                cnt=1;
                A[k++] = A[i];
            }else if(A[i] == A[i-1] && cnt<2){
                A[k++] = A[i];
                cnt++;
            }

            i++;
        }

        return k;

        // if(n <=2) return n;

        // int len = n;
        // int iStart = 0, iEnd = 1 , k=1;

        // while(iEnd < len){
        //     while(A[iEnd] == A[k-1]) ++iEnd;
        //     int step = iEnd - iStart;
        //     if(step >= 2){
        //         A[k] = A[k-1]; ++k;
        //     }

        //     if(iEnd<len)
        //     A[k++] = A[iEnd];
        //     iStart = iEnd;
        // }

        //     int step = iEnd - iStart;
        //     if(step >= 2){
        //         A[k] = A[k-1]; ++k;
        //     }
        //     return k;
    }
};

int main(){
    int const n=11;
    int A[] = {0,0,1,1,1,2,2,2,3,3,4};

    Solution s;
    int res = s.removeDuplicates(A,n);

    cout<<res<<endl;
    for(int i=0;i<n;i++)
        cout<<A[i]<<" ";
    cout<<endl;

    return 0;
}
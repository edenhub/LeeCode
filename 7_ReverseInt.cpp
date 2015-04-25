#include <iostream>

using namespace std;

const int SIZE=10;
int MAX_VAL[SIZE]={2,1,4,7,4,8,3,6,4,7};
int MIN_VAL[SIZE]={2,1,4,7,4,8,3,6,4,8};

class Solution {
public:
    int reverse(int x) {
        if(x ==0) return 0;
        if(x == -2147483648) return 0;
        int* standa;
        bool isNegative;
        if(x >0){
            isNegative = false;
            standa = MAX_VAL;
        }else{
            isNegative = true;
            standa = MIN_VAL;
            x = -x;
        } 

        int tmp[SIZE],idx=0;

        while(x!=0){
            tmp[idx++] = x%10;
            x/=10;
        }

        if(idx > SIZE) return 0;
        if(idx < SIZE){
            return toDigit(tmp,idx,isNegative);
        }

     

        int cmp=seqCmp(tmp,standa,SIZE);
        if(cmp <= 0) return toDigit(tmp,SIZE,isNegative);
        else return 0;
    }

    int toDigit(int* data,int len,bool isNegative){
        int tgt=0;
        for(int i=0;i<len;i++){
            tgt = tgt*10 + data[i];
        }

        if(isNegative) return -tgt;
        return tgt;
    }

    int seqCmp(int *fir,int *sec,int size){
        for(int i=0;i<size;i++){
            if(fir[i] < sec[i]) return -1;
            else if(fir[i] > sec[i]) return 1;
            else continue;
        }

        return 0;
    }
};

int main(){
    Solution solution;
    
    int res = solution.reverse(-2147483648);

    cout<<res<<endl;

    return 0;
}
#include <iostream>

using namespace std;

const int LEN=100000;
const int SIZE=10;
int MAX_VAL[SIZE]={2,1,4,7,4,8,3,6,4,7};
int MIN_VAL[SIZE]={2,1,4,7,4,8,3,6,4,8};

class Solution {
public:
    int myAtoi(string str) {
        int size = str.size();
        int tmp[LEN],idx=0;
        bool isNegative=false,isFirst=true,isFlag=false;
        int cnt=0;

        for(int i=0;i<size;i++){
        //     if(idx>SIZE){
        //          if(idx > SIZE){
        //     if(isNegative) return -2147483648;
        //     else return 2147483647;
        // }
        //     }

             char curr = str[i];
             if(isLecter(curr,isFlag)) {
                tmp[idx++] = curr - '0';
                continue;
             }

             if(curr == '-' && !isNegative) {
                isNegative = true;
                cnt++;
                if(cnt > 1) return 0;
                isFlag=true;
                continue;
             }

             if(curr == '+' && isFirst){
                isNegative = false;
                isFirst = false;
                                cnt++;
                if(cnt > 1) return 0;
                isFlag=true;
                continue;
             }

              if(curr == ' '    ) continue;
              // if(curr == ' ') return 0;

              // return 0;
              break;
        }

        if(idx > SIZE){
            if(isNegative) return -2147483648;
            else return 2147483647;
        }

        if(idx < SIZE) return toDigit(tmp,idx,isNegative);

        int *standa;
        if(isNegative) standa = MIN_VAL;
        else standa = MAX_VAL;
        int cmp = seqCmp(tmp,standa,SIZE);
        if(cmp<=0) return toDigit(tmp,idx,isNegative);
        else{
              if(isNegative) return -2147483648;
            else return 2147483647;
        }

    }

    bool isLecter(int ch,bool isFlag){
        if(isFlag && '1' <= ch && ch <= '9' ) return true;
        if(!isFlag && '0' <= ch && ch <= '9' ) return true;
        else return false;
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

// int main(){
//     Solution solution;

//     // while(1){
//     //     cout<<"start"<<endl;
//     //     string str;
//     // cin>>str;
//     int res = solution.myAtoi("  010");
//     cout<<res<<"\n-------\n";
//     // }

//     return 0;
// }
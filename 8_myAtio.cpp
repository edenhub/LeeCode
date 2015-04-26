#include <iostream>
#include <string>
#include <limits.h>

using namespace std;

int MAX_VAL=2147483647;
int MIN_VAL=-2147483648;

class Solution {
public:
    int myAtoi(string str) {
        string::size_type idx = str.find_first_not_of(' ');
        if(idx == string::npos) return 0;
        bool negative =false;
        int flagCnt=0;
        long long result=0;
        if(str[idx] == '-') {
            negative = true;
            idx++;
            flagCnt++;
            if(flagCnt>1) return 0;
        }
        if(str[idx] == '+') {
            idx++;
            flagCnt++;
            if(flagCnt>1) return 0;
        }
        for(;idx !=string::npos;idx++){
            if(isDigit(str[idx])){
                result =  result*10 + (str[idx] - '0');
                if(negative && -result <= MIN_VAL) return MIN_VAL;
                if(!negative && result >= MAX_VAL) return MAX_VAL;
            }else
                break;
        }
        if(negative) result =  -result;
        return (int)result;

    }

    bool isDigit(char ch){
        return ( '0' <= ch && ch <='9' );
    }
};

int main(){
    Solution s;
    cout<<s.myAtoi("2147483648");

    return 0;
}
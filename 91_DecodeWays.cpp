#include <iostream>
#include <vector>
#include <map>
#include <stdlib.h>

using namespace std;

class Solution {
public:
    Solution():cnt(0){}
    int numDecodings(string s) {
        int size = s.size();
        if(size == 0) return 0;
        if(size == 1 ) return s[0] == '0' ? 0 : 1;

        // int i=1; char ch='A';
        // for(;i<=26;i++,ch++) container[i] = ch;

        helper(0,s);
        return cnt;
    }

private:
    // map<int,char> container;
    int cnt;
    void helper(int idx,string& s){
        if(idx == s.size()){
            cnt++;
            return;
        } 

        int num1 = s[idx] - '0';
        if(isValidate(num1)) helper(idx+1,s);
        if(idx+1 < s.size()){
            int num2 = atoi(s.substr(idx,2).c_str());
            if(isValidate(num2)) helper(idx+2,s);
        }
    }

    bool isValidate(int num){
        return (1 <= num && num <= 26);
    }
};

int main(){
    string str = "00";

    Solution s;

    int ret = s.numDecodings(str);

    cout<<ret<<endl;

    return 0;
}
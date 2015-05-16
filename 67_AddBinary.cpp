#include <iostream>
#include <math.h>
#include <stack>
#include <sstream>
#include <memory.h>

using namespace std;

class Solution {
public:
    string addBinary(string a, string b) {
        int sizeA = a.size(), sizeB = b.size();
        if(sizeA == 1 && sizeB == 1 && a[0] == '0' && b[0] == '0') return "0";
        if(sizeA == 1 && a[0] == '0') return b;
        if(sizeB == 1 && b[0] == '0') return a;
        int size = sizeA > sizeB ? sizeA : sizeB;

        int charA[size],charB[size];
        copyStr(a,charA,size);
        copyStr(b,charB,size);

        size++;
        int addition=0;
        int ret[size];
        memset(ret,0,sizeof(ret));
        for(int i=0;i<=size;i++){
            int add = charA[i] + charB[i] + addition;
            if(add >= 2){
                addition = 1;
                ret[i] = add-2;
            }else{
                addition = 0;
                ret[i] = add;
            }
        }

        stringstream ss;
        int idx=size;

        if(ret[idx-1] == 0) idx--;
        for(int i=idx-1;i>=0;i--)
            ss<<ret[i];

        return ss.str();
    }

private:
    void copyStr(string& str,int* cont,int size){
        int strsize = str.size()-1;
        int idx=0;
        for(int i=strsize;i>=0;i--)
            cont[idx++] = str[i]-'0';

        while(idx<=size)
            cont[idx++] = 0;
    }
};

int main(){
    Solution s;

    string res = s.addBinary("1","10");

    cout<<res<<endl;

    return 0;
}
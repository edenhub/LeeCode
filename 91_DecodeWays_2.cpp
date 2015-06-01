#include <iostream>

using namespace std;

class Solution {
public:
    int numDecodings(string s) {
        int size = s.size();
        if(size == 0) return 0;
        if(s[0] == '0') return 0;
        if(size == 1) return s[0] == '0' ? 0 : 1;
        int f[size+1];
        f[0] = 1; f[1] = 1;

        for(int i=2;i<=size;i++){
            int pre = s[i-2] - '0', curr = s[i-1] - '0';
            if(pre == 0 && curr == 0) return 0;
            else if(pre == 0) f[i] = f[i - 2];
            else if(curr == 0){
                if(pre == 1 || pre == 2) f[i] = f[i-2];
                else return 0;
            }else if(isNumValidated(pre*10 + curr)) f[i] = f[i - 1] + f[i - 2];
            else f[i] = f[i - 1];
        }

        return f[size];
    }

private:
    bool isNumValidated(int num){
        return 1 <= num && num <= 26;
    }
};

int main(){
    string str = "100";

    Solution s;

    int ret = s.numDecodings(str);

    cout<<ret<<endl;

    return 0;
}
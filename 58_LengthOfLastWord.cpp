#include <iostream>

using namespace std;

class Solution {
public:
    int lengthOfLastWord(string s) {
        int size = s.size() ;
        if(size == 0) return 0;
        int pre=0,tail = size-1;
        while(tail >=  0 && s[tail] == ' ')  tail--;
        if(tail < 0) tail++;
        if(s[tail] == ' ') return 0;
        pre = tail-1;
        while(pre >= 0 && s[pre] != ' ') pre--;
        return tail - pre;
    }
};

int main(){
    string str = " ";
    Solution s;

    int ret = s.lengthOfLastWord(str);

    cout<<ret<<endl;

    return 0;
}
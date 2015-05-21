#include <iostream>

using namespace std;

class Solution {
public:
    bool isPalindrome(string s) {
        int left=0,right = s.size()-1;
        bool isLeftIn,isRightIn;

        if(left == right) return true;

        while(left<=right){
            //warning::
            while(left <= right && !isAlpha(s[left])) {
                left++;
            }
            //warning::
            while(left <= right && !isAlpha(s[right])) {
                right--;
            }
            //warning::
            if(left<=right && !isAlphaEqual(s[left],s[right])) return false;
            left++;
            right--;
        }

        return true;      
    }

private:
    bool isAlpha(char ch){
        return ('A'<=ch && ch<='Z') || ('a'<=ch && ch<='z' || ('0'<= ch && ch<='9'));
    }

    bool isAlphaEqual(char fir,char sec){
        return (fir == sec || fir - sec == 32 || sec - fir == 32);
    }
};

int main(){
    string ss=",.";

    Solution s;

    bool ret = s.isPalindrome(ss);
    cout<<ret<<endl;

    return 0;
}
#include <iostream>
#include <cmath>
using namespace std;

class Solution {
public:
    bool isPalindrome(int x) {
        if(x<0) return false;
        if(0<= x && x<=9) return true;
        if(x == 11 || x == 99) return true;
        if(10 <= x && x<=100) return false;

        int size = numberLen(x);
        int s=1,e=pow(10,size-1);
        while(s<=e){
            int left = x/e % 10;
            int right = x / s %10;
            if(left!= right) return false;

            s*=10;
            e/=10;
        }

        return true;
    }

    int numberLen(int x){
        int cnt=0;
        while(x!=0){
            cnt++;
            x/=10;
        }

        return cnt;
    }
};



int main(){
    Solution solution;
    bool res = solution.isPalindrome(122222);
    cout<<res;
}
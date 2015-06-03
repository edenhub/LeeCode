#include <iostream>

using namespace std;

class Solution {
public:
    double myPow(double x, int n) {
        if(n == 0) return 1.0;
        if(n == 1) return x;
        if(x == 1.0) return 1.0;
        if(x == -1.0) return n%2 == 0 ? 1.0 : -1.0;

        if(n < 0) return 1.0 / myPow(x,-n);
        double half = myPow(x,n/2);
        if(n % 2 == 0) return half * half;
        else return half * half * x;
    }
};

int main(){
    Solution s;

    double ret = s.myPow(-1 ,-2147483648);

    cout<<ret<<endl;

    return 0;
}
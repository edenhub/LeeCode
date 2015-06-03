#include <iostream>

using namespace std;

class Solution {
public:
    int mySqrt(int x) {
        if( x == 0) return 0;
        if(0 < x && x <= 3) return 1;

        if (x >= 46340 * 46340) { 
            return 46340;
        }

        int left = 0, right = x;

        while(left < right){
            int mid =  left + ( right - left ) / 2;
            if(mid > 46340)  right = mid;
            else if(mid * mid > x) right = mid - 1;
            else if (mid * mid < x && (mid + 1) * (mid + 1) <= x) left = mid + 1;
            else return mid;
        }

        return left;
    }
};

int main(){
    int x = 183692038;
    Solution s;

    int ret = s.mySqrt(x);

    cout<<ret<<endl;

    return 0;
}
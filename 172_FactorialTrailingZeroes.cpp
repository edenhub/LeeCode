#include <iostream>
using namepace std;

class Solution {
public:
    int trailingZeroes(int n) {
        int ret=0;

        while(n){
            ret+=n/5;
            n = n/5;
        }      

        return ret;
    }
};

int main(){

    return 0;
}
#include <iostream>
#include <bitset>

using namespace std;
const int t=9999999;
class Solution {
public:
    int countPrimes(int n) {
        bitset<t> flags;
        int cnt = 0;

        for(int i=2;i<n;i++){
            if(!flags[i]){
                cnt++;
                for(int j=2;j*i<n;j++){
                    flags[i*j] = 1;
                }
            }
        }
        return cnt;        
    }
};

int main(){
    Solution s;

    int n = s.countPrimes(2);

    cout<<n<<endl;

    return 0;
}
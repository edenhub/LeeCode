#include <iostream>
#include <math.h>

using namespace std;

class Solution {
public:
    int titleToNumber(string s) {
        int size = s.size()-1;

        int sum=0;

        for(int i=size;i>=0;i--){
            int curr = s[i] - 'A' + 1;
            sum += curr * pow(26,size-i);
        }

        return sum;
    }
};

int main(){
    string s; cin>>s;

    Solution ss;

    int ret = ss.titleToNumber(s);

    cout<<ret<<endl;
    return 0;
}
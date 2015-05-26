#include <iostream>
#include <sstream>

using namespace std;

class Solution {
public:
    string countAndSay(int n) {
        string init = "1";

        while(n>1){
            n--;
            init = helper(init);
        }

        return init;
    }

private:
    string helper(string& str){
        int size = str.size();
        stringstream ss;

        char ch=str[0];
        int cnt=1;

        for(int i=1;i<size;i++){
            if(str[i] == ch) cnt++;
            else{
                ss<<cnt<<ch;
                ch = str[i];
                cnt=1;
            }
        }

        ss<<cnt<<ch;

        return ss.str();
    }
};

int main(){
    int n=5;

    Solution s;
    string str = s.countAndSay(n);
    cout<<str<<endl;

    return 0;
}
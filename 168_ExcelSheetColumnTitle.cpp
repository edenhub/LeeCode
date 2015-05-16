#include <iostream>
#include <sstream>
#include <stack>

using namespace std;

class Solution {
public:
    string convertToTitle(int n) {
        char mapper[26] = {'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};
        stringstream ss;
        stack<char> st;
        while(n!=0){
            n--;
            st.push(mapper[n%26]);
            n/=26;
        }

        while(!st.empty()){
            ss<<st.top();
            st.pop();
        }

        return ss.str();
    }

};

int main(){
    int n; cin>>n;

    Solution s;

    string res = s.convertToTitle(n);
    cout<<res<<endl;

    return 0;
}
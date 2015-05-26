#include <iostream>
#include <stack>

using namespace std;

class Solution {
public:
    bool isValid(string s) {
        int size = s.size();
        stack<char> st;

        for(int i=0;i<size;i++){
            if(s[i] == '(' || s[i] == '[' || s[i] == '{') st.push(s[i]);
            else{
                if(st.empty()) return false;
                switch(s[i]){
                    case ')' : {
                        char left = st.top(); 
                        if(left == '(') st.pop();
                        else return false;
                        break;
                    }
                    case ']' : {
                        char left = st.top();
                        if(left == '[') st.pop();
                        else return false;
                        break;
                    }
                    case '}' : {
                        char left = st.top();
                        if(left == '{') st.pop();
                        else return false;
                        break;
                    }
                }
            }
        }

        if(!st.empty()) return false;
        else return true;
    }
};

int main(){
    string str = "()[]{}";
    Solution s;

    bool ret = s.isValid(str);

    cout<<ret<<endl;

    return 0;
}
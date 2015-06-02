#include <iostream>
#include <vector>
#include <sstream>

using namespace std;

class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> ret;
        if(n == 0) return ret;
        if(n == 1) {
            stringstream ss;
            ss<<'('<<')';
            ret.push_back(ss.str());
            return ret;
        }
        vector<char> st;
        helper(n,0,0,st,ret);
        return ret;
    }

private:
    void helper(int n,int left,int right,vector<char>& st,vector<string>& ret){
        if(left == n && right == n){
            stringstream ss;
            for(int i=0;i<st.size();i++) ss<<st[i];
            ret.push_back(ss.str());
            // cout<<ss.str()<<endl;
            return;
        }

        if(left < n){
            st.push_back('(');
            helper(n,left+1,right,st,ret);
            st.pop_back();
        }
            if(right < left && right < n && !st.empty()){
                st.push_back(')');
                helper(n,left,right+1,st,ret);
                st.pop_back();
            }
    }
};

int main(){
    int n=5;
    Solution s;

    vector<string> ret = s.generateParenthesis(n);
    vector<string>::iterator iter = ret.begin();

    while(iter != ret.end())
        cout<<*iter++<<endl;
    cout<<endl;

    return 0;
}
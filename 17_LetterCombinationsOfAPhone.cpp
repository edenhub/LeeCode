#include <iostream>
#include <vector>
#include <sstream>

using namespace std;

const string nums[] = {
    "","","abc","def","ghi","jkl","mno",
    "pqrs","tuv","wxyz"
    };

class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> ret;
        int size = digits.size();
        if(size == 0) return ret;
        vector<char> st;
        dfs(digits,0,st,ret);

        return ret;
    }

private:
    void dfs(string digits,int idx,vector<char>& st,vector<string>& ret){
        if(idx == digits.size()){
            string s = toString(st);
            ret.push_back(s);
            return;
        }

        string str = nums[(digits[idx] - '0')];
        for(int i=0;i<str.size();i++){
            st.push_back(str[i]);
            dfs(digits,idx+1,st,ret);
            st.pop_back();
        }
    }

    string toString(vector<char>& st){
        vector<char>::iterator iter = st.begin();
        stringstream ss;
        while(iter != st.end()) ss<<(*iter++);

        return ss.str();
    }    
};

int main(){

    string str = "2";
    Solution s;

    vector<string> ret = s.letterCombinations(str);

    return 0;
}
#include <iostream>
#include <vector>

using namespace std;

const string[] nums = {
    "","","abc","def","ghi","jkl","mno",
    "pqrs","tuv","wxyz"
};

class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> ret;

    }

private:
    void helper(int idx,int len,vector<char> st,vector<string> ret){
        string str = nums[idx];
        int size = str.size();
        if(size == 0) {
            return;
        }
        if(idx == len){
            stringstream ss;
            vector<char>::iterator iter = st.begin();
            while(iter != st.end()) ss<<*iter++;
            ret.push_back(ss.str());
            return;
        }


    }
};

int main(){

    return 0;
}
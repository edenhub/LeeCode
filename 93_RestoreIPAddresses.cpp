#include <iostream>
#include <vector>
#include <sstream>
#include <stdlib.h>

using namespace std;

class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        int size = s.size();
        vector<string> ret;
        for(int i=1;i<4&&(i-1)<size-3;i++){
            for(int j=1;j<4&&(i+j-1)<size-2;j++){
                for(int k=1;k<4&&(i+j+k-1)<size-1;k++){
                    stringstream ss;
                    string s1 = s.substr(0,i);
                    string s2 = s.substr(i,j);
                    string s3 = s.substr(i+j,k);
                    string s4 = s.substr(i+j+k,size-i-j-k);
                    if(!isValidate(s1) || !isValidate(s2) || !isValidate(s3) || !isValidate(s4)) continue;
                    ss<<s1<<"."<<s2<<"."<<s3<<"."<<s4;
                    string str = ss.str();
                    // cout<<str<<" -- "<<endl;
                    ret.push_back(str);
                }
            }
        }

        return ret;
    }

private:
    bool isValidate(string s){
        if(s.size()==0 || s.size()>3 || (s[0] == '0' && s.size()>1) || atoi(s.c_str()) > 255) return false;
        return true;
    }
};

int main(){
    string str = "25525511135";
    Solution s;

    vector<string> ret = s.restoreIpAddresses(str);

    return 0;
}
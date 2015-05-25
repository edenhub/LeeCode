#include <iostream>
#include <stdlib.h>
#include <vector>

using namespace std;

//1.0.0.0.0 == 1
//1.0.0.0.1 > 1.0.0.0.0
//1.2 < 1.10

class Solution {
public:
    int compareVersion(string version1, string version2) {
        vector<int> v1,v2;
        helper(version1,v1);
        helper(version2,v2);

        int s1=0,s2=0;

        while(s1<v1.size() && s2<v2.size()){
            if(v1[s1] > v2[s2]) return 1;
            else if(v1[s1] < v2[s2]) return -1;

            s1++;
            s2++;
        }

        if(s1 != v1.size()) {
            while(s1<v1.size()){
                if(v1[s1++] != 0) return 1;
            }

            return 0;
        }
        if(s2 != v2.size()) {
            while(s2 <v2.size()){
                if(v2[s2++] != 0) return -1;
            }

            return 0;
        }

        return 0;
    }

private:
    void helper(string version,vector<int>& v){
        int pre=0,idx=0;

        for(;idx<version.size();idx++){
            if(version[idx] == '.'){
                string tmp = version.substr(pre,idx-pre);
                v.push_back(atoi(tmp.c_str()));
                pre = idx+1;
            }
        }

        string tmp = version.substr(pre);
        v.push_back(atoi(tmp.c_str()));
    }
};

int main(){

    string s1="1.0.0.0",s2="1";

    Solution s;
    // vector<int> v1;

    // s.helper(s1,v1);
    // vector<int>::iterator iter = v1.begin();
    // while(iter != v1.end())
    //     cout<<*iter++<<" ";
    // cout<<endl;

    int ret = s.compareVersion(s1,s2);

    // string sss = "012";
    // cout<<atoi(sss.c_str())<<endl;
    cout<<ret<<endl;

    return 0;
}
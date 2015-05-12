#include <iostream>
#include <vector>
#include <memory.h>

using namespace std;

class Solution {
public:
    bool isIsomorphic(string s, string t) {
        return helper(s,t) && helper(t,s);
    }

private:
    bool helper(string s,string t){
        char cnt[128];
        memset(cnt,'\0',sizeof(cnt));

        for(int i=0;i<s.size();i++){
            char curr = s[i];
            if(cnt[curr] == '\0'){
                cnt[curr] = t[i];
                continue;
            }

            if(cnt[curr] != t[i]) return false;
        }

        return true;
    }
};

int main(){
    string s,t;
    cin>>s>>t;

    Solution so;
    bool res = so.isIsomorphic(s,t);
    cout<<res<<endl;
    return 0;
}
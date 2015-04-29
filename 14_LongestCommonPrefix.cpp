#include <iostream>
#include <vector>
#include  <algorithm>
using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int size = strs.size();
        if(size == 0) return "";
        if(size == 1) return strs[0];
            sort(strs.begin(),strs.end());
            int loop = strs[0].size();
            if(loop == 0) return strs[0];

            int cnt=0; bool ctnue = true;
            for(int i=0;i<loop;i++){
                char ch=strs[0][i];
                bool isSame = true;
                for(int j=1;j<strs.size();j++){
                    if(ch != strs[j][i]){
                        isSame =false; break;
                    }
                }

                if(!isSame) break;
                cnt++;
            }

            return strs[0].substr(0,cnt);
    }
};

int main(){
    vector<string> strs;
    strs.push_back("abcdefg");
    strs.push_back("abckg");
    strs.push_back("ab");
    Solution s;
    string res = s.longestCommonPrefix(strs);
    cout<<res<<endl;
    return 0;
}
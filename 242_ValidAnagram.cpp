#include <iostream>
#include <algorithm>

using namespace std;

class Solution {
public:
    bool isAnagram(string s, string t) {
        int size1 = s.size();
        int size2 = t.size();

        if(size1 != size2) return false;
        sort(s.begin(),s.end());
        sort(t.begin(),t.end());
        for(int i=0;i<size1;i++){
            if(s[i] != t[i]) return false;
        }

        return true;
    }
};

int main(){
    Solution solution = Solution();
    string s("anagram");
    string t("nagaram");

    cout<<solution.isAnagram(s,t)<<endl;

    return 0;
}
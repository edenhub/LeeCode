#include <iostream>
#include <vector>
#include <bitset>
#include <map>
#include <math.h>

using namespace std;

class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        vector<string> ret;
        int size = s.size();
        if(size <= 10) return ret;
        map<int,int> m;
        int first = init(s,9);
        m[first] = 1;
        for(int i=1;i<=s.size()-10;i++){
            int ne = init(s,i+9);
            if(m[ne] == 1 ) {
                 ret.push_back(s.substr(i,10));
                 m[ne]++;
            }
            else if(m[ne] > 1) continue;
            else m[ne] = 1;

            first = ne;
        }   
        return ret;
    }

private:
    inline int init(string& s,int last){
        int res=0;
        for(int i=last;i>=last-9;i--){
            int add = ( (s[i] & 0x6) >> 1 );
            res += add;
            res = res<<2;
        }

        return res;
    }
};

int main(){
    string s1 = "AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT";

    Solution s;
    vector<string> res = s.findRepeatedDnaSequences(s1);

    for(int i=0;i<res.size();i++)
        cout<<res[i]<<endl;

    return 0;
}
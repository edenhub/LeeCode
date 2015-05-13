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
        int first = init(s);
        m[first] = 1;
        for(int i=1;i<=s.size()-10;i++){
            int ne = next(first,s[i+10]);
            if(m[ne] == 1) ret.push_back(s.substr(i,10));
            else m[ne] = 1;
        }   

        return ret;
    }

private:
    int next(int pre,char ch){
        return (pre << 2) + judeAddition(ch);
    }

    int init(string& s){
        int first;
        for(int i=9;i>=0;i--){
            int add = judeAddition(s[i]);
            first += add*pow(4,9-i);
        }

        return first;
    }

    int judeAddition(char ch){
        int addition;
        switch(ch){
            case 'A' : { addition = 0 ; break;}
            case 'T' : { addition = 1 ; break;}
            case 'C' : { addition = 2 ; break;}
            case 'G' : { addition = 3 ; break;}
        }

        return addition;
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
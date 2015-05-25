#include <iostream>
#include <sstream>
#include <algorithm>

using namespace std;

class Solution {
public:
    int compareVersion(string version1, string version2) {
           int po1 = version1.find_first_of('.');
        int po2 = version2.find_first_of('.');
        int part1 = helper(version1,version2);

        if(part1 != 0) return part1;

        version1 = version1.substr(po1+1);
        version2 = version2.substr(po2+1);

        return helper(version1,version2);

        // return (version1 < version2) ? -1 :
        //                     ( (version1 == version2) ? 0 : 1 );
    }

private:
    int helper(string version1,string version2){
        int po1 = version1.find_first_of('.');
        int po2 = version2.find_first_of('.');

        if(po1 == string::npos && po2 == string::npos){
            return leftCmp(version1,version2);
        }

        if(po1 == string::npos){
            version2 = version2.substr(0,po2);
            int ret = leftCmp(version1,version2);
            if(ret > 0) return 1;
            else return -1;
        }

        if(po2 == string::npos){
            version1 = version1.substr(0,po1);
            int ret = leftCmp(version1,version2);
            if(ret < 0) return 1;
            else return -1;
        }


        if(po1 < po2) return -1;

        if(po1 > po2) return 1;

        string tmp1 = version1.substr(0,po1);
        string tmp2 = version2.substr(0,po2);
        if(tmp1 != tmp2){
            int ret = leftCmp(tmp1,tmp2);
            if(ret < 0) return -1;
            else if(ret > 0) return 1;
        }

        return 0;
    }
    int leftCmp(string version1,string version2){
        int no1 = version1.find_first_not_of('0');
        int no2 = version2.find_first_not_of('0');

        if(no1 == string::npos && no2 == string::npos) return 0;
        else if(no1 == string::npos) return -1;
        else if(no2 == string::npos) return 1; 

        version1 = version1.substr(no1+1);
        version2 = version2.substr(no2+1);

        return (version1 < version2) ? -1 :
                            ( (version1 == version2) ? 0 : 1 );
    }
};

int main(){

    string s1="01.1",s2="1.1";

    Solution s;

    int ret = s.compareVersion(s1,s2);

    cout<<ret<<endl;

    return 0;
}
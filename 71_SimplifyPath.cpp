#include <iostream>
#include <vector>
#include <sstream>

using namespace std;

class Solution {
public:
    string simplifyPath(string path) {
        int size = path.size();
        if(size == 0 || size == 1) return path;

        stringstream ss(path);
        vector<string> st;

        while(!ss.eof()){
            string next = nextDir(ss);
            if(next == "" || next == "." ) continue;
            else if(next == "..") {
                if(st.empty()) continue;
                else st.pop_back();                 
            } 
            else st.push_back(next);
        }

        stringstream ret;
        int len = st.size();
        if(len == 0) return "/";
        for(int i=0;i<len;i++) ret<<'/'<<st[i];

        return ret.str();
    }

private:
    string nextDir(stringstream& path){
        char ch='\0';
        stringstream ss;
        do{
            path>>ch;
            if(!path.eof()&&ch!= '/') ss<<ch;
        }while(!path.eof() && ch != '/');

        return ss.str();
    }
};

int main(){
    string path = "/../";
    Solution s;

    string ret = s.simplifyPath(path);
    cout<<ret<<endl;
    return 0;
}
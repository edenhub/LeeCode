#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <set>

using namespace std;

class Solution {
public:
    vector<string> anagrams(vector<string>& strs) {
        map<string,vector<string> > containers;

        for(int i=0;i<strs.size();i++){
            string s = strs[i];
            sort(s.begin(),s.end());
            map<string,vector<string> >::iterator iter = containers.find(s);
            if(iter == containers.end()){
                containers.insert(make_pair(s,vector<string>(0)));
            }

            containers[s].push_back(strs[i]);
        }        

        map<string,vector<string> >::iterator iter = containers.begin();
        int maxNum=0;
        string head;
        while(iter != containers.end()){
            int size = containers[iter->first].size();
            if(maxNum < size){
                maxNum = size;
                head = iter->first;
            }
            iter++;
        }

        // sort(containers.begin(),containers.end());
        iter = containers.begin();
        vector<string> ret;

        while(iter != containers.end()){
            vector<string> group = containers[iter->first];
            if(group.size() > 1){
                for(int i=0;i<group.size();i++)
                    ret.push_back(group[i]);
            }
            iter++;
        }

        return ret;
    }
};

int main(){
    int T; cin>>T;
    vector<string> strs; 
    // strs.push_back("");strs.push_back("");
    while(T--){
        string s; cin>>s;
        strs.push_back(s);
    }

    Solution s;
    vector<string> ret = s.anagrams(strs);

    vector<string>::iterator iter  = ret.begin();
    cout<<ret.size()<<endl;
    while(iter!=ret.end())
        cout<<*iter++<<" ";
    cout<<endl;

    return 0;
}
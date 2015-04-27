#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    vector<vector<int> > generate(int numRows) {
        vector<vector<int> > res;
        if(numRows == 0) return res; 
        vector<int> beg; beg.push_back(1);
        res.push_back(beg);

        if(numRows == 1) return res;
        for(int i=1;i<numRows;i++){
            vector<int> tmp; tmp.push_back(1);

            for(int j=1;j<=i-1;j++){
                int curr = res[i-1][j-1] + res[i-1][j];
                tmp.push_back(curr);
            }
            //warning : the first and the last one is 1
            tmp.push_back(1);

            res.push_back(tmp);
        }

        return res;
    }
};

int main(){
        Solution s;
        vector<vector<int> > res = s.generate(5);
        int outter = res.size();

        for(int i=0;i<outter;i++){
            vector<int> v = res[i];

            vector<int>::iterator iter = v.begin();
            while(iter!=v.end())
                cout<<*iter++<<" ";
            cout<<endl;
        }

}
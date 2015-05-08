#include <iostream>
#include <vector>
#include <sstream>

using namespace std;

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int> >& matrix) {
        vector<int> ret;
        int rows = matrix.size();
        if(rows == 0) return ret;
        int cols = matrix[0].size();

        int sX = 0, sY = 0;
        int eX = rows-1, eY = cols - 1;

        while(sX <=eX && sY <= eY){
            printCircle(matrix,sX,sY,eX,eY,ret);
            sX++; sY++;
            eX--; eY--;
        }
        return ret;
    }

private:
    void printCircle(vector<vector<int> >& matrix,int sX,int sY,int eX,int eY,vector<int>& ret){
        for(int i=sY;i<=eY;i++)
            ret.push_back(matrix[sX][i]);

        for(int i=sX+1;i<=eX;i++)
            ret.push_back(matrix[i][eY]);

        if(sX !=eX && sY != eY){
            for(int i=eY-1;i>=sY;i--)
                ret.push_back(matrix[eX][i]);

            for(int i=eX-1;i>sX;i--)
                ret.push_back(matrix[i][sY]);
        }
    }
};

int main(){
    int rows; cin>>rows;
    int cols; cin>>cols;
    istringstream is("1,2,3,4,5,6");
    vector<vector<int> > matrix;
    for(int i=0;i<rows;i++){
        vector<int> vt;
        for(int j=0;j<cols;j++){
            int n; is>>n;
            char dot; is>>dot;
            vt.push_back(n);
        }
        matrix.push_back(vt);
    }

    Solution s;

    vector<int> ret = s.spiralOrder(matrix);
    vector<int>::iterator iter = ret.begin();

    while(iter != ret.end())
        cout<<*iter++<<" ";
    cout<<endl;

    return 0;
}
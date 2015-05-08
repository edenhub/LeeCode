#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int> > generateMatrix(int n) {
        vector<vector<int> > matrix;

        if(n == 0) return matrix;

        for(int i=0;i<n;i++){
            vector<int> vt;
            for(int j=0;j<n;j++)
                vt.push_back(0);
            matrix.push_back(vt);
        }

        int sX=0, sY = 0;
        int eX = n-1, eY = n-1;
        int curr=1;

        while(sX <= eX && sY <= eY){
            insertCircle(matrix,sX,sY,eX,eY,curr);
            sX++; sY++;
            eX--; eY--;
        }

        return matrix;
    }

private:
    void insertCircle(vector<vector<int> >& matrix,int sX,int sY,int eX,int eY,int& curr){
        for(int i=sY;i<=eY;i++)
            matrix[sX][i] = curr++;

        for(int i=sX+1;i<=eX;i++)
            matrix[i][eY] = curr++;

        if(sX != eX && sY != eY){
            for(int i=eY-1;i>=sY;i--)
                matrix[eX][i] = curr++;

            for(int i=eX-1;i>sX;i--)
                matrix[i][sY] = curr++;
        }
    }
};

int main(){
    int n; cin>>n;

    Solution s;

    vector<vector<int> > res = s.generateMatrix(n);

    for(int i=0;i<n;i++){
            for(int j=0;j<n;j++)
                cout<<res[i][j]<<"\t";
        cout<<endl;
    }

    return 0;
}
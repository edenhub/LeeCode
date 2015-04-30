#include <iostream>
#include <vector>
#include <memory.h>

using namespace std;

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int> >& obstacleGrid) {
        int rows = obstacleGrid.size(), cols = obstacleGrid[0].size();
        long ret[rows][cols];

        memset(ret,0,sizeof(ret));

        for(int i=0;i<cols;i++){
            if(obstacleGrid[0][i] == 0) ret[0][i] = 1;
            // else break;
            else{
                while(i++<cols) ret[0][i] = 0;
                break;
            }
        }

        for(int i=0;i<rows;i++){
            if(obstacleGrid[i][0] == 0) ret[i][0] = 1;
            // break;
            else{
                while(i++<rows) ret[i][0] = 0;
                break;
            }
        }

        for(int i=1;i<rows;i++){
            for(int j=1;j<cols;j++){
                if(obstacleGrid[i][j] == 1) ret[i][j] = 0;
                else ret[i][j] = ret[i-1][j] + ret[i][j-1];
            }
        }

        for(int i=0;i<rows;i++){
            for(int j=0;j<cols;j++)
                cout<<ret[i][j]<<" ";
            cout<<endl;
        }

        return ret[rows-1][cols-1];
    }
};

int main(){
    const int rows=16, cols = 33;
    int data[rows][cols] = {0,0,0,0,0,0,0,0,1,0,1,0,0,0,0,0,0,0,0,1,0,0,0,0,0,1,0,0,0,0,0,0,0,
                                        0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
                                        0,0,0,0,0,1,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,1,0,0,0,0,0,0,
                                        1,1,1,0,0,0,0,1,0,0,0,0,0,0,0,0,1,0,0,1,1,0,0,0,0,0,0,0,0,1,0,0,1,
                                        0,0,1,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,1,0,0,0,0,0,
                                        0,0,0,1,0,1,0,0,0,0,1,1,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,1,1,0,
                                        1,0,1,1,1,0,0,0,0,1,0,0,0,0,0,0,0,0,1,0,0,0,0,0,1,0,0,0,0,0,0,0,0,
                                        0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,1,0,1,0,0,0,1,0,1,0,0,0,0,0,0,
                                        0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0,1,0,
                                        0,0,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0,0,1,0,0,0,0,0,
                                        0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,
                                        1,0,1,0,0,0,0,0,0,0,0,1,0,0,1,0,0,0,0,1,0,1,0,0,0,1,0,1,0,0,0,0,1,
                                        0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,1,0,1,0,0,0,0,0,0,1,1,0,0,0,0,0,
                                        0,1,0,1,0,0,0,0,1,0,0,1,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,1,0,0,0,0,0,
                                        0,1,0,0,0,0,0,0,1,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,1,1,0,1,
                                        1,0,0,0,0,1,0,0,1,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};

    vector<vector<int> > input;
    for(int i=0;i<rows;i++){
        vector<int> tmp;
        for(int j=0;j<cols;j++){
            int curr = data[i][j];
            tmp.push_back(curr);
        }
        input.push_back(tmp);
    }

    Solution s;
    int ret = s.uniquePathsWithObstacles(input);
    cout<<ret<<endl;

    return 0;
}
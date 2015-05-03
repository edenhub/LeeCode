#include <iostream>
#include <vector>
#include <memory.h>
#include <algorithm>
using namespace std;

class Solution {
public:
    int minPathSum(vector<vector<int> >& grid) {
            int rows = grid.size(), cols = grid[0].size();

            for(int i=1;i<cols;i++)
                grid[0][i] += grid[0][i-1];
            for(int i=1;i<rows;i++)
                grid[i][0] += grid[i-1][0];

            for(int i=1;i<rows;i++)
                for(int j=1;j<cols;j++)
                    grid[i][j] = min(grid[i][j]+grid[i-1][j],grid[i][j]+grid[i][j-1]);

            return grid[rows-1][cols-1];
            // int dp[rows][cols];      
            // memset(dp,0,sizeof(dp));

            // dp[0][0] = grid[0][0];
            // for(int i=1;i<cols;i++)
            //     dp[0][i] = grid[0][i] + dp[0][i-1];
            // for(int i=1;i<rows;i++)
            //     dp[i][0] = grid[i][0] + dp[i-1][0];

            // int mi = dp[0][0];
            // for(int i=1;i<rows;i++){
            //     for(int j=1;j<cols;j++){
            //         dp[i][j] = min(grid[i][j] + dp[i-1][j],grid[i][j]+dp[i][j-1]);
            //     }
            // }

            // return dp[rows-1][cols-1];
    }
};

int main(){

    return 0;
}
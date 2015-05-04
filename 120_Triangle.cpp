#include <iostream>
#include <vector>
#include <algorithm>
#include <memory.h>
using namespace std;

class Solution {
public:
    int minimumTotal(vector<vector<int> > &triangle) {
            int n = triangle.size();
            for(int i=1;i<n;i++){
              for(int j=0;j<=i;j++){
                if(j==0) triangle[i][j] += triangle[i-1][0];
                else if(j == i) triangle[i][j] += triangle[i-1][j-1];
                else
                  triangle[i][j] = min(triangle[i][j] + triangle[i-1][j], triangle[i][j] + triangle[i-1][j-1]);
              }
            }

            sort(triangle[n-1].begin(), triangle[n-1].end());

            return triangle[n-1][0];
            // int dp[n][n];
            // memset(dp,0,sizeof(dp));

            // dp[0][0] = triangle[0][0];
            // for(int i=1;i<n;i++){
            //     for(int j=0;j<=i;j++){
            //         if(j==0) dp[i][j] = triangle[i][j] + dp[i-1][0];
            //         else if(j==i) dp[i][j] = triangle[i][j] + dp[i-1][i-1];
            //         else{
            //           dp[i][j] = min(triangle[i][j]+dp[i-1][j],triangle[i][j]+dp[i-1][j-1]);
            //         }
            //     }
            // }

            // sort(dp[n-1],dp[n-1]+n);
            // return dp[n-1][0];
    }
};

int main(){
  //   [2],
  //   [3,4],
  //  [6,5,7],
  // [4,1,8,3]
    vector<vector<int> > triangle;
    vector<int> t0; t0.push_back(2); triangle.push_back(t0);
    vector<int> t1; t1.push_back(3); t1.push_back(4); triangle.push_back(t1);
    vector<int> t2; t2.push_back(6); t2.push_back(5); t2.push_back(7); triangle.push_back(t2);
    vector<int> t3; t3.push_back(4); t3.push_back(1); t3.push_back(8); t3.push_back(3); triangle.push_back(t3);

    Solution s;

    int ret = s.minimumTotal(triangle);
    cout<<ret<<endl;

    return 0;
}
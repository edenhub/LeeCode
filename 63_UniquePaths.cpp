#include <iostream>

using namespace std;
//the question is like the have m-1+n-1 box,the find how many ways to put m-1(n-1) balls
//because the the robot only have to move right m-1 and left n-1
//because only fron right and up can move to A[i][j],so dp[i][j] = dp[i][j-1]+dp[i-1][j]
//and the init station is the the first colum and first row is 1
class Solution {
public:
    int uniquePaths(int m, int n) {
        if(m == 0 || n == 0) return 0;

        long long dp[m][n];

        for(int i=0;i<m;i++) dp[i][0] = 1;
        for(int i=0;i<n;i++) dp[0][i] = 1;

        for(int i=1;i<m;i++){
            for(int j=1;j<n;j++){
                dp[i][j] = dp[i-1][j] + dp[i][j-1];
            }
        }

        return dp[m-1][n-1];
    }
};

int main(){
    Solution s;
    int res = s.uniquePaths(99,99);

    cout<<res;

    return 0;
}
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int minimumTotal(vector<vector<int> > &triangle) {
            int n = triangle.size();
            
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
    vector<int> t2; t2.push_back(6); t2.push_back(6); t2.push_back(7); triangle.push_back(t2);
    vector<int> t3; t3.push_back(4); t3.push_back(1); t3.push_back(8); t3.push_back(3); triangle.push_back(t3);

    Solution s;

    int ret = s.minimumTotal(triangle);
    cout<<ret<<endl;

    return 0;
}
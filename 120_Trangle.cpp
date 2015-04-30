#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int minimumTotal(vector<vector<int> > &triangle) {
        int sum=0,size=triangle.size();

        sum += triangle[0][0];
        for(int i=1;i<size;i++){
            sort(triangle[i].begin(),triangle[i].end());
            sum+=triangle[i][0];
        }
        return sum;
    }
};

int main(){

    return 0;
}
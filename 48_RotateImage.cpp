#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
class Solution {
public:
    void rotate(vector<vector<int> > &matrix) {
        int rows = matrix.size(), cols = matrix[0].size();

        for(int i=0;i<rows;i++){
            for(int j=i+1;j<cols;j++){
                swap(matrix[i][j],matrix[j][i]);
            }
        }

        for(int i=0;i<cols/2;i++){
            for(int j=0;j<rows;j++){
                swap(matrix[j][i],matrix[j][cols-i-1]);
            }
        }
    }
};
int main(){

    return 0;
}
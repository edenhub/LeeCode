#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int rows = matrix.size(), cols = matrix[0].size();

        int i=0,j=cols-1;

        while(i<rows && j>=0){
            if(matrix[i][j] == target) return true;
            else if(matrix[i][j] > target) --j;
            else ++i;
        }

        return false;
    }
};

int main(){

    return 0;
}
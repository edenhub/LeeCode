#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void setZeroes(vector<vector<int> > &matrix) {
        int rows = matrix.size(),cols = matrix[0].size();

        if(rows == 0 || cols == 0) return;

        for(int i=0;i<rows;i++){
            for(int j=0;j<cols;j++){
                if(matrix[i][j] == 0){
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }
            }
        }

        for(int i=0;i<rows;i++){
            if(matrix[i][0] == 0){
                for(int j=1;j<cols;j++)
                    if(i != 0)
                    matrix[i][j] = 0;
            }
        }

        for(int i=0;i<cols;i++){
            if(matrix[0][i] ==0){
                for(int j=1;j<rows;j++)
                    if(i != 0)
                    matrix[j][i] = 0;
            }
        }

        if(matrix[0][0] == 0){
            for(int i=0;i<cols;i++) matrix[0][i] = 0;
            for(int i=0;i<rows;i++) matrix[i][0] = 0;
        }
    }
};

int main(){

    return 0;
}
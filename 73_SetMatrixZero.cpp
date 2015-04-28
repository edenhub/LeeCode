#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void setZeroes(vector<vector<int> > &matrix) {
        //matrix[0][0] has two state
        bool isFirRow = false, isFirCol = false;

        int rows = matrix.size(), cols = matrix[0].size();
        //check should delete fir cols and fir row
        if(matrix[0][0] == 0){
            isFirRow = true;
            isFirCol = true;
        }

        //check should delete fir col
        for(int i=1;i < cols;i++)
            if(matrix[0][i] == 0) isFirRow = true;
        //check should delete fir row
        for(int i=1;i < rows; i++)
            if(matrix[i][0] == 0) isFirCol = true;
        //mark cols and rows to delete
        for(int i=1;i<rows;i++){
            for(int j=1;j<cols;j++){
                if(matrix[i][j] == 0){
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }
            }
        }
        //delete thr cols
        for(int i=1;i<cols;i++){
            if(matrix[0][i] == 0){
                for(int t = 1; t < rows; t++){
                    matrix[t][i] = 0;
                }
            }
        }

        //delete the rows
        for(int i=1;i<rows;i++){
            if(matrix[i][0] == 0){
                for(int t = 1; t< cols; t++){
                    matrix[i][t] = 0;
                }
            }
        }
        //is to delete first col
        if(isFirRow){
            for(int i=0;i<cols;i++){
                matrix[0][i] = 0;
            }
        }
        //is to delete first row
        if(isFirCol){
            for(int i=0;i<rows;i++){
                matrix[i][0] = 0;
            }
        }
    }
};

int main(){

    return 0;
}
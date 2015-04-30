#include <iostream>
#include <vector>
#include <memory.h>

using namespace std;

class Solution {
public:
    bool exist(vector<vector<char> > &board, string word) {
        int rows = board.size(), cols = board[0].size();
        bool flag[rows*cols];
        memset(flag,false,sizeof(flag));
        const char *str = word.c_str();
        for(int i=0;i<rows;i++){
            for(int j=0;j<cols;j++){
                if(isExist(board,str,i,j,flag)) return true;
            }
        }
        
        return false;
    }
//good idea,worth learn
    bool isExist(vector<vector<char> > &board,const char *ch,int x,int y,bool *flag){
        int rows = board.size(), cols = board[0].size();

        if(x<0 || y <0 || x>=rows || y >= cols|| *(flag+x*cols+y) || board[x][y] != *ch) return false;
        if(*(ch+1) == '\0') return true;

        *(flag+x*cols+y) = true;
         if(isExist(board,ch+1,x+1,y,flag) || isExist(board,ch+1,x-1,y,flag) ||
                        isExist(board,ch+1,x,y-1,flag) || isExist(board,ch+1,x,y+1,flag))
            return true;
        *(flag+x*cols+y) = false;
        return false;
    }
};

int main(){

    return 0;
}
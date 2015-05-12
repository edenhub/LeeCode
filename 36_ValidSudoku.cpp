#include <iostream>
#include <vector>
#include <bitset>

using namespace std;

class Solution {
public:
    bool isValidSudoku(vector<vector<char> >& board) {
        vector<bitset<9> > rows(9,bitset<9>(0));
        vector<bitset<9> > cols(9,bitset<9>(0));
        vector<bitset<9> > subs(9,bitset<9>(0));

        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                char curr = board[i][j];
                if(curr == '.') continue;
                int n = curr - '1';
                if(rows[n][i] || cols[n][j] || subs[n][i/3*3+j/3]) return false;
                rows[n][i] = cols[n][j] = subs[n][i/3*3+j/3] = 1;
            }
        }

        return true;
    }
};

int main(){
    vector<vector<char> > board;

    for(int i=0;i<9;i++){
        for(int j=0;j<9;j++){
            int n; cin>>n;
            board[i][j] = n;
        }
    }

    Solution s;

    bool res = s.isValidSudoku(board);

    cout<<res<<endl;

    return 0;
}
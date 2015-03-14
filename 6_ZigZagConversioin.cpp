#include <iostream>

using namespace std;


class Solution {
public:
    string convert(string s, int nRows) {
    	int r = nRows,len = s.length();
    	int temp = r + (r - 1)/2;
    	cout<<temp;
    	// int c = len / (r + (r-1)/2);
    	// cout<<c;
    }

    int calRows(int len,int r){
    	return len / (r + (r-1)/2);
    }

};

int main(){
	Solution s;
	string s = 
	s.convert(,3);

	return 0;
}
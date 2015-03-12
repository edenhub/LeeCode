#include <iostream>

using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        int len = s.length();


       	if(len == 0)
       		return "";

       	string longest = s.substr(0,1);

       	for(int i=0;i<len;i++){
       		string p1 = expandAroundCenter(s,i,i);
       		if(p1.length() > longest.length())
       			longest = p1;

       		string p2 = expandAroundCenter(s,i,i+1);
       		if(p2.length() > longest.length())
       			longest = p2;
       	}

       	return longest;
    }

    string expandAroundCenter(string s,int l,int r){
    	int len = s.length();

    	while(l>=0 && r < len && s[l] == s[r]){
    		l--;
    		r++;
    	}

    	return s.substr(l+1,r-l-1);
    }
};

int main(){
	Solution solution;

	cout<<solution.longestPalindrome("abacdfgdcaba");
}
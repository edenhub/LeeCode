#include <iostream>
#include <memory.h>
#include <set>

using namespace std;

/*
不需要知道当前子串的实际情况，只要记录当前子串中
字符的变化就行
*/

class Solution {
public:
	int lengthOfLongestSubstring(string s){
		int len = s.size(),max = 0;

		for(int i=0;i<)
	}

    int lengthOfLongestSubstring_2(string s) {
    	int len = s.size(),max = 0;
    	int idex = -1;

    	int locs[256];
    	memset(locs,-1,sizeof(locs));

    	for(int i=0;i<len;i++){
    		if(locs[s[i]] > idex){
    			idex = locs[s[i]];
    		}

    		if(i - idex > max){
    			max = i - idex;
    		}

    		locs[s[i]] = i;
    	} 

    	return max;
    }
};

int main(){

	return 0;
}
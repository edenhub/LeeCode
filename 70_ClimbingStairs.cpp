#include <iostream>
#include <vector>
#include <math.h>


using namespace std;

class Solution {
public:
    int climbStairs(int n) {
        int s1 = 1, s2 = 1;
        int sum = 0;

        if(n == 1) return 1;
        if(n == 2) return 2;

        for(int i=2;i<n;i++){
        	s1 = s1 + s2;
        	swap(s1,s2);
        }

        sum = s1 + s2;
        
        return sum;
    }
};

int main(){
	Solution s = Solution();

	int n = 7;

	cout<<s.climbStairs(n)<<endl;
	return 0;
}
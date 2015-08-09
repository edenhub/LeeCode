#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int size = gas.size();
        if(size == 1) return 0;
        vector<int> diff;
        int sum=0;
        for(int i=0;i<size;i++){
        	int tmp = gas[i] - cost[i];
        	sum += tmp;
        	diff.push_back(tmp);
        }
    }
};

int main(){

	return 0;
}
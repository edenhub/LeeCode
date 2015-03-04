#include <vector>
#include <map>
#include <iostream>

using namespace std;

/**
题目卡O^2时间，只能一次循环列表
使用HashTable存储arr[i](查询时间为O(n))
遍历过程中将arr[i]作为key，i作为value存储在HashTable中
再将target-arr[i]的值从HashTable中查找，避免两次查找


tip：利用index1+index2=target的条件避免两次循环
**/

class Solution{
public:
	vector<int> twoSum(vector<int> &number,int target){
		vector<int> res;
		map<int,int> hashTable;

		for(int i=0;i<number.size();i++){
			int curr = number[i], minus = target - curr;

			if(hashTable.find(curr) == hashTable.end()){
				hashTable[curr] = i;
			}

			if(hashTable.find(minus) != hashTable.end() && hashTable[minus] != i){
				res.push_back(hashTable[minus]+1);
				res.push_back(i+1);

				return res;
			}
		} 
	}
};

int main(){
	vector<int> numbers,res;
	numbers.push_back(2);
	numbers.push_back(7);
	numbers.push_back(11);
	numbers.push_back(15);

	int target = 9;

	Solution solution;

	res = solution.twoSum(numbers,target);

	cout<<res[0]<<" "<<res[1]<<endl;

	return 0;
}
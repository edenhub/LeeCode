#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        if(gas.size() != cost.size()) return -1;
        int size = gas.size();
        if(size == 0) return -1;
        
        int total=0,sum=0,s=0;

        for(int i=0;i < size; i++){
            total += (gas[i] - cost[i]);
            if(sum < 0){
                //在上一步才得到sum的结果，所以这一步从i开始
                sum = (gas[i] - cost[i]);
                s = i;
            }
            else sum += (gas[i] - cost[i]);
        }

        return total < 0 ? -1 : s;
    }

    int maxIndex(vector<int>& diff,int size){
        int s=0,i=1;
        int maxS=diff[0];

        for(;i<size;i++){
            if(diff[i]+maxS > diff[i]){
                maxS = diff[i] + maxS;
            }else{
                maxS = diff[i];
                s = i;
            }
        }

        return s;
    }

    int minIndex(vector<int>& diff,int size){
        int s = 0, i=1;
        int minS = diff[0];

        for(;i<size;i++){
            if(diff[i] + minS < diff[i]){
                minS = diff[i] + minS;
                s = i;
            }else{
                minS = diff[i];
            }
        }

        return s;
    }
};

int main(){
    // -4 , 3 ,56 , -15 , 34 , 0 , -14 , 4
    vector<int> v;
    v.push_back(-4); v.push_back(3); v.push_back(56);
    v.push_back(-15); v.push_back(35); v.push_back(0);
    v.push_back(-14); v.push_back(4);
    Solution s;

    cout<<s.minIndex(v,8);


	return 0;
}
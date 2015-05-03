#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int size = prices.size();
        if(size <= 1) return 0;
        int profit=0, min = prices[0], idx=1;

        for(;idx<size;idx++){
            int curr = prices[idx];
            if(curr <= min) min = curr;
            else{
                profit = (curr - min > profit) ? (curr - min) : profit;
            }
        }

        return profit;
    }
};

int main(){
    int T; cin>>T;
    vector<int> v;
    while(T--){
        int t; cin>>t;
        v.push_back(t);
    }

    Solution s;
    int res = s.maxProfit(v);
    cout<<res<<endl;

    return 0;
}
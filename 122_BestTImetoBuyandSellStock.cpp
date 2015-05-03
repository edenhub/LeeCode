#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    //in the same day,the user can sell it than buy it again,so greedy...... -_-!!!
    int maxProfit(vector<int>& prices){
        int len = prices.size();
        if(len <= 1) return 0;

        int profit=0;

        for(int i=1;i<len;i++){
            if(prices[i] > prices[i-1]) profit += prices[i] - prices[i-1];
        }

        return profit;
    }

    int maxProfit2(vector<int>& prices) {
        int len = prices.size();
        if(len <= 1) return 0;

        int min=prices[0], profit = 0;

        for(int idx=1;idx<len;idx++){
            int curr = prices[idx];

            if(min < curr){
                if(idx+1 < len && prices[idx+1] > curr) continue;
                else{
                    profit += ( curr - min);
                    min = curr;
                }
            }else{
                min = curr;

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
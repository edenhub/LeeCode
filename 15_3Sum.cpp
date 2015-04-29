#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int> > threeSum(vector<int> &num) {
        vector<vector<int> > result;
        if(num.size() < 3) return result;
        if(num.size() == 3){
            int sum = num[0]+num[1]+num[2];
            if(sum == 0){
                sort(num.begin(),num.end());
                result.push_back(num);
            }

            return result;
        }
        set<vector<int> > cnt;
        sort(num.begin(),num.end());

        for(int i=0;i<num.size();i++){
            int target = -num[i];
            if(i>0 && num[i-1] == num[i]) continue;
             hasTwoSum(num,target,i,cnt);
        }

        set<vector<int> >::iterator iter = cnt.begin();
        while(iter != cnt.end()){
            result.push_back(*iter);
            iter++;
        }

        return result;
    }

    void hasTwoSum(vector<int> &num,int target,int without,set<vector<int> >& cnt){
        int s=without+1,e=num.size()-1;
        //warning:cause the result dose not have same solutino,and the data is sorted
        //then each time we do not need to begin from the idx[0],we just from i+1
        while(s<e){
            if(s == without){
                s++;
                continue;
            }

            if(e == without){
                e--;
                continue;
            }

            int curr = num[s]+num[e];
            if(curr == target){
                 vector<int> tmp;
                tmp.push_back(num[s]);
                tmp.push_back(num[e]);
                tmp.push_back(num[without]);

                sort(tmp.begin(),tmp.end());
                cnt.insert(tmp);

                s++; e--;
            }
            else if(curr > target) e--;
            else s++;
        }
    }
};

int main(){
    vector<vector<int> > cnt;
    vector<int> num;
    int T;  cin>>T;
    while(T--){
        int n; cin>>n;
        num.push_back(n);
    }
    
    Solution s;
    cnt = s.threeSum(num);


    cout<<cnt.size();
    return 0;
}
#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

// struct TPair{
// public:
//     int first,second;
//     bool hasTwo;
// };

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
          hasTwoSum(num,target,i,cnt);
            // if(isHasTwoSum.hasTwo){
            //     vector<int> tmp;
            //     tmp.push_back(isHasTwoSum.first);
            //     tmp.push_back(isHasTwoSum.second);
            //     tmp.push_back(num[i]);

            //     sort(tmp.begin(),tmp.end());
            //     cnt.insert(tmp);
            // }
        }

        set<vector<int> >::iterator iter = cnt.begin();
        while(iter != cnt.end()){
            result.push_back(*iter);
            iter++;
        }

        return result;
    }

    void hasTwoSum(vector<int> &num,int target,int without,set<vector<int> >& cnt){
        int s=0,e=num.size()-1;
        // TPair res;

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
                // res.first = num[s];
                // res.second = num[e];
                // res.hasTwo = true;
                 vector<int> tmp;
                tmp.push_back(num[s]);
                tmp.push_back(num[e]);
                tmp.push_back(num[without]);

                sort(tmp.begin(),tmp.end());
                cnt.insert(tmp);

                s++; e--;
                // return res;
            }
            else if(curr > target) e--;
            else s++;
        }

        // res.hasTwo = false;
        // return res;
    }
};

int main(){
    vector<vector<int> > cnt;
    vector<int> num;
    // // 7,-1,14,-12,-8,7,2,-15,8,8,-8,-14,-4,-5,7,9,11,-4,-15,-6,1,-14,4,3,10,-5,2,1,6,11,2,-2,-5,-7,-6,2,-15,11,-6,8,-4,2
    // num.push_back(7);num.push_back(-1);num.push_back(14);num.push_back(2);num.push_back(-1);num.push_back(-4);
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
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;



class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        if(digits.size() == 0) return digits;
        reverse(digits.begin(),digits.end());

        bool addition = false;
            int curr = digits[0]+1;
               if(curr>9){
                addition = true;
                digits[0] = curr - 10;
            }else{
                addition = false;
                digits[0] = curr;
            }
        for(int i=1;i<digits.size();i++){
            curr = digits[i];
            if(addition) curr++;
            if(curr>9){
                addition = true;
                digits[i] = curr - 10;
            }else{
                addition = false;
                digits[i] = curr;
            }
        }

        if(addition) digits.push_back(1);
        reverse(digits.begin(),digits.end());
        return digits;
    }
};

int main(){
    vector<int> digits;
    digits.push_back(1);
    digits.push_back(0);
    Solution s;
    digits = s.plusOne(digits);

    vector<int>::iterator iter = digits.begin();
    while(iter!=digits.end())
        cout<<*iter++;

    return 0;
}
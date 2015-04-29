#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

// 设P是1～n的一个全排列:p=p1p2......pn=p1p2......pj-1pjpj+1......pk-1pkpk+1......pn
// 1）从排列的右端开始，找出第一个比右边数字小的数字的序号j（j从左端开始计算），即  j=max{i|pi<pi+1}
// 2）在pj的右边的数字中，找出所有比pj大的数中最小的数字pk，即 k=max{i|pi>pj}（右边的数从右至左是递增的，因此k是所有大于pj的数字中序号最大者）
// 3）对换pj，pk
// 4）再将pj+1......pk-1pjpk+1pn反转，这就是排列p的下一个下一个排列。

// 例如839647521是数字1～9的一个排列。从它生成下一个排列的步骤如下： 
// 自右至左找出排列中第一个比右边数字小的数字4          839647521
// 在该数字后的数字中找出比4大的数中最小的一个5        839647521
// 将5与4交换                                                                         839657421
// 将7421倒转                                                                          839651247
// 所以839647521的下一个排列是839651247。

class Solution {
public:
    void nextPermutation(vector<int> &num) {
        int size = num.size();
        int pre=-1,next;

        for(int i=size-1;i>=0;i--){
            if(i-1>=0 && num[i-1] < num[i] ){
                pre = i-1; break;
            }
        }

        if(pre == -1){
            reverse(num.begin(),num.end());
            return;
        }

        for(int i=size-1;i>=pre;i--){
            if(num[i] > num[pre]){
                next = i;
                break;
            }
        }

        swap(num[next],num[pre]);
        vector<int>::iterator iter = num.begin();
        reverse(iter+pre+1,num.end());

    }
};

int main(){
    vector<int> num;
    num.push_back(1);num.push_back(1);num.push_back(5);
    Solution s;

    s.nextPermutation(num);

    vector<int>::iterator iter = num.begin();
    while(iter != num.end())
        cout<<*iter++<<" ";
    cout<<endl;

    return 0;
}
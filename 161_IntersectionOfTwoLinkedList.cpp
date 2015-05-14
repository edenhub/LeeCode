#include <iostream>

using namespace std;

struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int cntA = calculateNodeCnt(headA);
        int cntB = calculateNodeCnt(headB);

        ListNode *ptFir,*ptSec;

        if(cntA > cntB){
            ptFir = headA;
            ptSec = headB;
        }else{
            ptFir = headB;
            ptSec = headA;

            cntA = cntA^cntB;
            cntB = cntA^cntB;
            cntA = cntA^cntB;
        }

        while(cntA-- != cntB) ptFir = ptFir->next;

        while(ptFir != 0){
            if(ptFir->val == ptSec->val) return ptFir;

            ptFir = ptFir->next;
            ptSec = ptSec->next;
        }

        return 0;

    }

private:
    inline int calculateNodeCnt(ListNode* head){
        int cnt = 0;
        ListNode *pt = head;

        while(pt != 0){
            cnt++;
            pt = pt->next;
        }

        return cnt;
    }
};

int main(){

    return 0;
}
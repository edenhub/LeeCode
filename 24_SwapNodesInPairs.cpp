#include <iostream>

using namespace std;

struct ListNode{
    int val;
    ListNode *next;
    ListNode(int x):val(x),next(0){}
};

class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if(head == 0 || head->next == 0) return head;

        ListNode *p1,*p2,*pHead = new ListNode(0),*pTail=pHead;
        p1 = head;
        p2 = p1->next;
        pHead->next = head;

        while(p1 != 0 && p2 != 0){
            p1->next = p2->next;
            p2->next = p1;

            pTail->next = p2;
            pTail = p1;

            p1 = p1->next;
            // cout<<"in"<<endl;
            if(p1!=0)
                p2 = p1->next;
            else
                p2 = 0;
        }

        return pHead->next;
    }
};

int main(){
    ListNode *l1 = new ListNode(1);
    ListNode *l2 = new ListNode(2);
    ListNode *l3 = new ListNode(3);
    ListNode *l4 = new ListNode(4);

    l1->next = l2;
    l2->next = l3;
    l3->next = l4;

    Solution s;

    ListNode *l = s.swapPairs(l1);

    ListNode *pt = l;
    while(pt != 0){
        cout<<pt->val<<" ";
        pt = pt->next;
    }

    cout<<endl;

    return 0;
}
#include <iostream>

using namespace std;

 struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
 };

class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        if(head == 0 || head->next == 0) return head;

        ListNode *hLittle = new ListNode(0),*tLittle = hLittle;
        // ListNode *hEqual = new ListNode(0),*tEqual = hEqual;
        ListNode *hLarget = new ListNode(0),*tLarget = hLarget;

        ListNode *pt = head;
        while(pt != 0){
            if(pt->val >= x){
                tLarget->next = pt;
                tLarget = pt;
            }else{
                tLittle->next = pt;
                tLittle = pt;
            }

            pt = pt->next;
        }

        // ListNode *ret = new ListNode(0);
            tLarget->next = 0;

        if(hLittle->next == 0) return hLarget->next;
        else{
            tLittle->next = hLarget->next;
            return hLittle->next;
        }
    }
};

int main(){
    ListNode *n1 = new ListNode(2);
    ListNode *n2 = new ListNode(1);
    // ListNode *n3 = new ListNode(3);
    // ListNode *n4 = new ListNode(2);
    // ListNode *n5 = new ListNode(5);
    // ListNode *n6 = new ListNode(2);
    // ListNode *n7 = new ListNode(3);
    // ListNode *n8 = new ListNode(4);
    // ListNode *n9 = new ListNode(6);

    n1->next = n2;
    // n2->next = n3;
    // n3->next = n4;
    // n4->next = n5;
    // n5->next = n6;
    // n6->next = n7;
    // n7->next = n8;
    // n8->next = n9;

    ListNode *p1 = n1;
    while(p1!=0){
        cout<<p1->val<<" ";
        p1 = p1->next;
    }
    cout<<endl;

    Solution s;

    ListNode *node = s.partition(n1,1);

    ListNode *p = node;
    while(p!=0){
        cout<<p->val<<" ";
        p = p->next;
    }


    return 0;
}
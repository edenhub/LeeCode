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
        ListNode *headH,*tailHead;
        ListNode *headP,*tailP,*headLa,*tailLa;

        headH = new ListNode(0);headH->next = head;tailHead = headH;
        headP = new ListNode(0); tailP = headP;
        headLa = new ListNode(0); tailLa = headLa;
        
        while(tailHead->next != 0){
            cout<<"in"<<tailHead->next->val<<" "<<endl;
            if(tailHead->next->val == x){
                ListNode *node = tailHead->next;
                tailHead->next = node->next;
                tailP->next = node;
                tailP = node;
                tailHead = tailHead->next;
                cout<<"equal"<<endl;
            }else if(tailHead->next->val > x){
                ListNode *node = tailHead->next;
                tailHead->next = node->next;
                tailLa->next = node;
                tailLa = node;
                tailHead = tailHead->next;
                cout<<"large"<<endl;
            }else
                tailHead = tailHead->next;

        }

        tailHead->next = headP->next;
        tailP->next = headLa->next;

        return headH->next;
    }
};

int main(){
    ListNode *n1 = new ListNode(1);
    ListNode *n2 = new ListNode(4);
    ListNode *n3 = new ListNode(3);
    ListNode *n4 = new ListNode(2);
    ListNode *n5 = new ListNode(5);
    ListNode *n6 = new ListNode(2);
    ListNode *n7 = new ListNode(3);
    ListNode *n8 = new ListNode(4);
    ListNode *n9 = new ListNode(6);

    n1->next = n2;
    n2->next = n3;
    n3->next = n4;
    n4->next = n5;
    n5->next = n6;
    n6->next = n7;
    n7->next = n8;
    n8->next = n9;

    ListNode *p1 = n1;
    while(p1!=0){
        cout<<p1->val<<" ";
        p1 = p1->next;
    }
    cout<<endl;

    Solution s;

    ListNode *node = s.partition(n1,3);

    // ListNode *p = node;
    // while(p!=0){
    //     cout<<p->val<<" ";
    //     p = p->next;
    // }


    return 0;
}
#include <iostream>

using namespace std;

struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode *p1=l1,*p2=l2,*head = new ListNode(0),*tail = head;

        while(p1!=0 && p2 != 0){
            if(p1->val < p2->val){
                tail->next = p1;
                tail = p1;
                p1 = p1->next;
            }else{
                tail->next = p2;
                tail = p2;
                p2 = p2->next;
            }
        }

        if(p1 != 0) tail->next = p1;
        if(p2 != 0) tail->next = p2;

        return head->next;
    }
};

int main(){

    return 0;
}
#include <iostream>

using namespace std;


struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
 };

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if(head == 0 || head->next == 0) return head;

         ListNode *pre=0,*curr=head,*nex;

         while(curr != 0){
            nex = curr->next;
            curr->next = pre;

            pre = curr;
            curr = nex;
         }

         return pre;
    }
};

int main(){

    return 0;
}
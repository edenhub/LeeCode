#include <iostream>

using namespace std;

struct ListNode{
    int val;
    ListNode *next;
    ListNode(int x):val(x),next(0){}
};

class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        if(head == 0 || head->next == 0) return head;
        if(m == n && m == 1) return head;
    }

private:
    ListNode* reverseList(ListNode* head){
        ListNode *pre=0,*curr=head,*next;

        while(curr!=0){
            next = curr->next;
            curr->next = pre;

            curr = next;
            pre = curr;
        }

        return pre;
    }
};

int main(){

    return 0;
}
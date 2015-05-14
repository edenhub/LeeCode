#include <iostream>

using namespace std;

struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if(head == 0 || head->next == 0) return head;
        ListNode *pt = head;

        while(pt != 0){
            int val = pt->val;
            while(pt->next != 0 && pt->next->val == val){
                ListNode *node = pt->next;
                pt->next = node->next;
                delete node;
            }
            pt = pt->next;
        }

        return head;
    }
};

int main(){
    ListNode *l1 = new ListNode(1);
    ListNode *l2 = new ListNode(1);
    ListNode *l3 = new ListNode(1);
    ListNode *l4 = new ListNode(1);
    ListNode *l5 = new ListNode(1);
    ListNode *l6 = new ListNode(1);
    ListNode *l7 = new ListNode(1);

    l1->next = l2; l2->next = l3; l3->next = l4; l4->next = l5; l5->next = l6; l6->next=l7;

    Solution s;

    ListNode *l = s.deleteDuplicates(l1);

    ListNode *pt = l;

    while(pt != 0){
        cout<<pt->val<<" ";
        pt = pt->next;
    }

    cout<<endl;

    return 0;
}
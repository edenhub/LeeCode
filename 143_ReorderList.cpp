#include <iostream>

using namespace std;

struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    void reorderList(ListNode* head) {
        int size = calculateNums(head);
        if(size <= 2 ) return;

        int half = (size+1)/2;
        ListNode *pt = head;
        while(half-- != 1) pt = pt->next;

        ListNode *now = pt;
        pt = pt->next;
        now->next = 0;

        ListNode *tail = reverseList(pt);
        ListNode *pt1 = head, *pt2 = tail;

        while(pt2 != 0){
            ListNode *tmp = pt2;
            pt2 = pt2->next;

            tmp->next = pt1->next;
            pt1->next = tmp;

            pt1 = tmp->next;
        }
    }

private:
    inline ListNode* reverseList(ListNode* head){
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

    inline int calculateNums(ListNode* head){
        int cnt=0;
        ListNode *pt = head;

        while(pt != 0){
            cnt++;
            pt = pt->next;
        }

        return cnt;
    }
};

int main(){
    ListNode *l1 = new ListNode(1);
    ListNode *l2 = new ListNode(2);
    ListNode *l3 = new ListNode(3);
    ListNode *l4 = new ListNode(4);
    ListNode *l5 = new ListNode(5);
    ListNode *l6 = new ListNode(6);
    // ListNode *l7 = new ListNode(7);

    l1->next = l2; l2->next = l3; l3->next = l4; l4->next = l5; l5->next = l6;
     // l6->next=l7;

    Solution s;

    s.reorderList(l1);

     ListNode *pt = l1;

    while(pt != 0){
        cout<<pt->val<<" ";
        pt = pt->next;
    }

    cout<<endl;

    return 0;
}
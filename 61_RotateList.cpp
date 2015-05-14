#include <iostream>

using namespace std;

struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if(head == 0 || k == 0 || head->next == 0) return head;
        int size = caculateNums(head);
        k = (k > size) ? (k%size) : k;
        if(k == 0) return head;

        ListNode *pt = reverseList(head);
        // cout<<k<<" "<<size<<endl;
        ListNode *p1,*p2,*tmp = new ListNode(0);
        tmp->next = pt;
        p1 = tmp;

        while(p1!=0 && k-- !=0) p1 = p1->next;
        if(k>=0){
            return reverseList(tmp->next);
        } else{
            p2 = p1->next;
            p1->next = 0;

            ListNode *mid = tmp->next;
            ListNode *r1 = reverseList(tmp->next);
            ListNode *r2 = reverseList(p2);
            mid->next = r2;

            return r1;
        }
    }

private:
    ListNode* reverseList(ListNode* head){
        if(head == 0 || head->next == 0) return head;
        ListNode *pre=0, *curr = head, *next = 0;

        while(curr != 0){
            next = curr->next;
            curr->next = pre;

            pre = curr;
            curr = next;
        }

        return pre;
    }

    int caculateNums(ListNode *head){
        int cnt=0;
        ListNode *pt = head;
        while(pt!=0){
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
    // ListNode *l6 = new ListNode(6);
    // ListNode *l7 = new ListNode(7);

    l1->next = l2; l2->next = l3; l3->next = l4; l4->next = l5;
     // l5->next = l6;
     // l6->next=l7;

    Solution s;

    ListNode *l = s.rotateRight(l1,10);
    ListNode *pt = l;

    while(pt!=0){
        cout<<pt->val<<" ";
        pt = pt->next;
    }
    cout<<endl;

    return 0;
}
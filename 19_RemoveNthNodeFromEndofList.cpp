#include <iostream>

using namespace std;

struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(head == 0 || n == 0) return head;

        ListNode *pt = head;
        int cnt=0;

        while(pt != 0){
            cnt++;
            pt = pt->next;
        }

        
        pt = head;
        if(n == cnt){
            ListNode *ret = pt->next;
            delete pt;
            return ret;
        }

        while(cnt-- != n+1){
            pt = pt->next;
        }

        ListNode *removeNode = pt->next;
        pt->next = removeNode->next;

        delete removeNode;

        return head;
    }
};

int main(){
    ListNode *l1 = new ListNode(0);
    ListNode *l2 = new ListNode(1);
    ListNode *l3 = new ListNode(2);
    ListNode *l4 = new ListNode(3);

    l1->next = l2;
    l2->next = l3;
    l3->next = l4;

    Solution s;

    ListNode *l = s.removeNthFromEnd(l1,4);
    ListNode *pt = l;

    while(pt != 0){
        cout<<pt->val<<" ";
        pt = pt->next;
    }

    cout<<endl;

    return 0;
}
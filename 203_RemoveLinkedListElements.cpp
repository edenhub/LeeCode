#include <iostream>

using namespace std;

struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        ListNode *tmp = new ListNode(0);
        tmp->next = head;
        ListNode *pt = tmp;
        bool de;

        while(pt!=0){
            de = false;
            if(pt->next != 0 && pt->next->val == val){
                ListNode *node = pt->next;
                pt->next = pt->next->next;
                if(node != 0)
                    delete node;
                de = true;
            }
            if(!de)
                pt = pt->next;
        }

        return tmp->next;
    }
};

int main(){
     // 1 --> 2 --> 6 --> 3 --> 4 --> 5 --> 6, val = 6
    ListNode *l1 = new ListNode(1);
    ListNode *l2 = new ListNode(1);
    ListNode *l3 = new ListNode(1);
    ListNode *l4 = new ListNode(2);
    ListNode *l5 = new ListNode(1);
    ListNode *l6 = new ListNode(1);
    ListNode *l7 = new ListNode(1);

    l1->next = l2; l2->next = l3; l3->next = l4; l4->next = l5; l5->next = l6; l6->next=l7;

    Solution s;

    ListNode *l = s.removeElements(l1,1);
    // cout<<"out"<<endl;
    ListNode *pt = l;

    while(pt != 0){
        cout<<pt->val<<" ";
        pt = pt->next;
    }

    cout<<endl;

    return 0;
}
#include <iostream>
#include <set>

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
        set<int> duplications;

        ListNode *pt = head;
        while(pt != 0){
            int val = pt->val;
            while(pt->next != 0 && pt->next->val == val){
                ListNode *node = pt->next;
                pt->next = node->next;
                delete node;
                duplications.insert(val);
            } 
            pt = pt->next;
        }
        
        ListNode *tmp = new ListNode(0);
        tmp->next = head;
        pt = tmp;
        while(pt != 0){
            bool isDel = false;
            if(pt->next != 0){
                int val = pt->next->val;
                if(duplications.find(val) != duplications.end()){
                    ListNode *node = pt->next;
                    pt->next = node->next;
                    delete node;
                    isDel = true;
                }
            }
            if(!isDel) 
                pt = pt->next;
        }

        return tmp->next;

    }
};

int main(){
    ListNode *l1 = new ListNode(1);
    ListNode *l2 = new ListNode(1);
    ListNode *l3 = new ListNode(2);
    ListNode *l4 = new ListNode(2);
    ListNode *l5 = new ListNode(2);
    ListNode *l6 = new ListNode(2);
    ListNode *l7 = new ListNode(2);

    l1->next = l2; l2->next = l3; l3->next = l4; l4->next = l5; l5->next = l6; l6->next=l7;

    Solution s;

    ListNode *l = s.deleteDuplicates(l1);
    cout<<"out"<<endl;
    ListNode *pt = l;

    while(pt != 0){
        cout<<pt->val<<" ";
        pt = pt->next;
    }

    cout<<endl;

    return 0;
}
#include <iostream>

using namespace std;

struct RandomListNode {
     int label;
     RandomListNode *next, *random;
     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
};

class Solution {
public:
    RandomListNode *copyRandomList(RandomListNode *head) {
        RandomListNode *pt = head;

        while(pt != 0){
            RandomListNode *copy = new RandomListNode(pt->label);
            copy->next = pt->next;
            pt->next = copy;
            
            pt = pt->next->next;
        }

        pt = head;
        while(pt != 0){
            if(pt->random != 0)
                pt->next->random = pt->random->next;
            else
                pt->next->random = 0;

            pt = pt->next->next;
        }

        RandomListNode *deepHead=new RandomListNode(0),*tail=deepHead;
        pt = head;

        while(pt != 0){
            tail->next = pt->next;
            tail = tail->next;

            pt->next = pt->next->next;

            pt=pt->next;
        }

        return deepHead->next;
    }
};

int main(){
        RandomListNode *head = new RandomListNode(-1);

    Solution s;

    RandomListNode *copy = s.copyRandomList(head);
    cout<<"out"<<endl;
    RandomListNode *pt = copy;

    while(pt != 0){
        cout<<pt->label<<" "<<pt->next->label<<" ";
        if(pt->random == 0) cout<<" NULL "<<endl;
        else cout<<pt->random->label<<endl;

        pt = pt->next;
    }

    return 0;
}
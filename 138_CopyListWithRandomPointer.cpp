#include <iostream>
#include <map>

using namespace std;

struct RandomListNode {
     int label;
     RandomListNode *next, *random;
     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
};

class Solution {
public:
    RandomListNode *copyRandomList(RandomListNode *head) {
        map<int,RandomListNode*> m;
        RandomListNode *copy=0, *tail =0, *pt = head;

        while(pt!=0){
            if(copy == NULL){
                copy = new RandomListNode(pt->label);
                tail = copy;
                m[pt->label] = copy;
            }else{
                RandomListNode *node = new RandomListNode(pt->label);
                tail->next = node;
                tail = node;
                m[pt->label] = node;
            }

            pt = pt->next;
        }

        pt = head;
        RandomListNode *ptC = copy;
        while(pt !=0){
            // cout<<(pt->random == 0)<<endl;
            if(pt->random == 0) ptC->random = NULL;
            else
                ptC->random = m[pt->random->label];
            pt = pt->next;
            ptC = ptC->next;
        }

        return copy;
    }
};


int main(){
    RandomListNode *head = new RandomListNode(-1);

    Solution s;

    RandomListNode *copy = s.copyRandomList(head);
    RandomListNode *pt = copy;

    while(pt != 0){
        cout<<pt->label<<" "<<pt->next->label<<" ";
        if(pt->random == 0) cout<<" NULL "<<endl;
        else cout<<pt->random->label<<endl;

        pt = pt->next;
    }


    return 0;
}
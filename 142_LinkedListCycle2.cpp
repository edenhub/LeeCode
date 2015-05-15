#include <iostream>

using namespace std;

struct ListNode{
    int val;
    ListNode *next;
    ListNode(int x):val(x),next(0){}
};

class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if(head == 0) return 0;
        ListNode *p1,*p2;

        p1 = head;
        p2 = head;

        while(p2 != 0 && p2->next != 0){
            p2 = p2->next->next;
            p1 = p1->next;

            if(p2 == p1) break;
        }

        if(p2 == 0 || p2->next == 0) return 0;

        p1 = head;

        while(p1 != p2){
            p1 = p1->next;
            p2 = p2->next;
        }

        return p2;
    }
};

int main(){

    return 0;
}
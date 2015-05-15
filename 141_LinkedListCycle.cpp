#include <iostream>

using namespace std;

struct ListNode{
    int val;
    ListNode *next;
    ListNode(int x):val(x),next(0){}
};

class Solution {
public:
    bool hasCycle(ListNode *head) {
        if(head == 0) return false;
        ListNode *p1,*p2;
        p1 = head;
        p2 = head;

        while(p2 != 0 && p2->next!=0){
            p2 = p2->next->next;
            p1 = p1->next;
            if(p1 == p2) return true;
        }

        return false;
    }
};

int main(){

    return 0;
}
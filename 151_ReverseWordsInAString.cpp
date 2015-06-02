#include <iostream>
#include <algorithm>
#include <sstream>

using namespace std;

class Solution {
public:
    void reverseWords(string &s) {
        preHold(s);
        int size = s.size();
        if(size == 0) return;
        reversePartition(s,0,size-1);
        int front=0,tail=0;

        while(front<size && tail <size){
            front=tail;
            while(front<size && s[front] == ' '){
                front++;
            }
            tail = front;
            while(tail<size && s[tail] != ' ') tail++;
            reversePartition(s,front,tail-1);
        }
    }

private:
    void preHold(string& s){
        int size = s.size();
        if(size == 0) return;
        stringstream ss;
        char pre = s[0],curr = '\0';
        if(pre != ' ') ss<<pre;
        for(int i=1;i<size;i++){
            pre = s[i-1];
            curr = s[i];

            if(curr == ' ' && pre == ' ') continue;
            else if(curr != ' ' || (curr == ' ' && pre != ' ')) ss<<curr;
        }

        s = ss.str();
        size = s.size();
        if(s[size - 1] == ' ') s.erase(size-1);
    }
    void reversePartition(string &str,int s,int e){
        if(s>=e) return;

        while(s<e){
            swap(str[s],str[e]);
            s++; e--;
        }
    }
};

int main(){
    string s = "a";
    Solution so;
    so.reverseWords(s);
    cout<<s<<endl;

    return 0;
}
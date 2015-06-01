#include <iostream>
#include <algorithm>

using namespace std;

class Solution {
public:
    void reverseWords(string &s) {
        preHold(s);
        int size = s.size();
        if(size == 0) return;
        reversePartition(s,0,size-1);
        cout<<size<<endl;
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
        int idx = 0;
        while(idx<size && s[idx] == ' ') idx++;
        s.erase(s.begin(),s.begin()+idx-1);
        size = s.size();
        idx = size;
        while(0<idx && s[idx] == ' ')idx--;
        s.erase(s.end()-idx,s.end());
        size = s.size();
        for(int i=0;i<size;i++){
        }
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
    string s = "       the   sky   is       blue    ";
    Solution so;
    so.reverseWords(s);
    cout<<s<<endl;

    return 0;
}
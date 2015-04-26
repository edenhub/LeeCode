#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct puke{
    char num;
    char color;

    puke(){}
    puke(char n,char c):num(n),color(c){};
    bool operator==(puke& pu){
        if(num == pu.num) return true;
        else return false;
        // return num==pu.num && color==pu.color;
    }
};
int total=0;
unsigned long long under=2^64;
int calDiff(vector<puke>& data){
    int size = data.size();
    if(size == 0) return 0;
    if(size == 1) return 1;
    puke tmp = data[0];
    int num=0;
    for(int i=1;i<size;i++){
        if(!(tmp==data[i])) num++;
        tmp = data[i];
    }

    return num;
}

void permutation(vector<puke>& data,int s,int e){
    if(s == e){
        // vector<puke>::iterator iter=data.begin();
        // while(iter != data.end()){
        //     cout<<iter->num<<iter->color<<" ";
        //      iter++;
        // }
        if(e == 0) {
            total++;return;
        }
        int tmp = calDiff(data);
        if(tmp == e) total++;
        // cout<<" "<<total;
        // cout<<endl;
    }

    for(int i=s;i<=e;i++){
        swap(data[s],data[i]);
        permutation(data,s+1,e);
        swap(data[s],data[i]);
    }
}

void run(int T){
    int n;
    cin>>n;
    vector<puke> t;
    for(int i=0;i<n;i++){
        string str;
        cin>>str;
        puke p(str[0],str[1]);
        t.push_back(p);
    }
    permutation(t,0,n-1);
    cout<<"Case #"<<T<<": "<<total<<endl;
    // cout<<total<<endl;
    total=0;
}

int main(){
    int T;
    cin>>T;
    for(int i=1;i<=T;i++){
        
        run(i);
    }

    // puke p('2','S'),p2('4','S'),p3('3','S');
    // vector<puke> t;
    // t.push_back(p);
    //     t.push_back(p2);
    // t.push_back(p3);

    // permutation(t,0,2);


    return 0;
}
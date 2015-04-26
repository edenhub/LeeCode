#include <iostream>
#include <memory.h>

using namespace std;
const int M_N=100,M_M=100;

bool user[M_N];
int qinmi[M_N+1][M_N+1];
bool diffSex[M_N+1][M_N+1];
void run(int N,int M,int Q){
    // bool user[N+1];
    memset(user,0,sizeof(user));
    memset(qinmi,0,sizeof(qinmi));
    memset(diffSex,0,sizeof(diffSex));

    for(int i=1;i<=N;i++){
        int sex; cin>>sex;
        user[i] = sex;
    }
    // bool diffSex[N+1][N+1];

    for(int i=1;i<=N;i++){
        for(int j=1;j<=N;j++){
                        diffSex[i][j] = user[i]^user[j];
            diffSex[j][i] = user[i]^user[j];
        }
    }

    // int qinmi[N+1][N+1];
    for(int i=1;i<=N;i++){
        for(int j=1;j<=N;j++)
            qinmi[i][j]=0;
    }
    for(int i=1;i<=M;i++){
        int x,y,z; cin>>x>>y>>z;
        qinmi[x][y] = z;
        qinmi[y][x] = z;
    }

    // cout<<"-"<<endl;
    // for(int i=1;i<=N;i++){
    //     for(int j=1;j<=N;j++)
    //         cout<<qinmi[i][j]<<" ";
    //     cout<<endl;
    // }
    // cout<<"-"<<endl;
    // for(int i=1;i<=N;i++){
    //     for(int j=1;j<=N;j++)
    //         cout<<diffSex[i][j]<<" ";
    //     cout<<endl;
    // }

    for(int i=1;i<=Q;i++){
        int op; cin>>op;

        switch(op){
            case 1 :{
                int u; cin>>u;
                user[u] = !user[u];
                for(int i=1;i<=N;i++){
                    diffSex[i][u] = !diffSex[i][u];
                    diffSex[u][i] = diffSex[i][u];
                }
                break;
            }
            case 2 :{
                int x,y,z; cin>>x>>y>>z;
                qinmi[x][y]=z;
                qinmi[y][x]=z;
                break;
            }
            case 3: {
                int sum=0;
                for(int i=1;i<=N;i++){
                    for(int j=i;j<=N;j++){
                        if(diffSex[i][j]) {
                            sum += qinmi[i][j];
                        }
                    }
                }

                cout<<sum<<endl;
                break;
            }
        }
    }


} 

int main(){
    int T; cin>>T;
    for(int i=1;i<=T;i++){
        int N,M,Q; cin>>N>>M>>Q;
        cout<<"Case #"<<i<<":"<<endl;
        run(N,M,Q);
    }

    return 0;
}
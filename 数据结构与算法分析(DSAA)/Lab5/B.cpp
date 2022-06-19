#include "iostream"
using namespace std;
typedef int Position,Group,Time;
Group G[2][100010]; //Position of the Group
Position P[2][100010]; //Group at every Position
Time t[100010];// Wait time of every Group

void moveForward(int p,int q){
    int i=1,j=1,m=1;
    for (; i <= p && j <= q; ++m) {
        if (P[0][i] == P[1][j]){
            t[P[0][i]] = m;
            G[0][P[0][i]] = G[1][P[0][i]] =0;
        } else {
            t[P[0][i]] = t[P[1][j]] = m;
            G[0][P[0][i]] = G[1][P[0][i]] = 0;
            G[0][P[1][j]] = G[1][P[1][j]] = 0;
        }
        ++i,++j;
        while (!G[0][P[0][i]] && i <= p){
            ++i;
        }
        while (!G[1][P[1][j]] && j <= q){
            ++j;
        }
    }
    for (; j <= q;++m) {
        while (!G[1][P[1][j]] && j <= q){
            ++j;
        }
        t[P[1][j]] = m;
        ++j;
    }
    for (; i <= p;++m) {
        while (!G[0][P[0][i]] && i <= p){
            ++i;
        }
        t[P[0][i]] = m;
        ++i;
    }
}
void out(int num){
    for (int i = 1; i <= num; ++i) {
        cout<<t[i]<<" ";
    }
}
int main(){
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n,p,q;
    cin>>n>>p>>q;
    //memset(G,0,sizeof G);
    //memset(P,0,sizeof P);
    for (int i = 1; i <= p; ++i) {
        cin>>P[0][i];
        G[0][P[0][i]] = i;
    }
    for (int i = 1; i <= q; ++i) {
        cin>>P[1][i];
        G[1][P[1][i]] = i;
    }
    moveForward(p,q);
    out(n);
    return 0;
}
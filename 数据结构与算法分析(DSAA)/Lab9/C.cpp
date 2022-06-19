#include "cstdio"
#include "cstring"
using namespace std;
typedef int SetName;
typedef int Vertex;
int S[100010];

void initSet(){
    memset(S, -1, sizeof S);
}
void Union(SetName Root1,SetName Root2){
    if (S[Root1] > S[Root2]){ // 2 > 1
        S[Root2] += S[Root1];
        S[Root1] = Root2;
    } else { // 1 > 2
        S[Root1] += S[Root2];
        S[Root2] = Root1;
    }
}
SetName findRoot(Vertex X){
    if(S[X] < 0)
        return X;
    else
        return findRoot(S[X]);
}
int main(){
    int n,m,u,v,b;
    // freopen("test1.in","r",stdin);
    scanf("%d%d",&n,&m);
    initSet();
    for (int i = 0; i < m; ++i) {
        scanf("%d%d",&u,&v);
        Vertex r1 = findRoot(u), r2 = findRoot(v);
        if (r1 != r2)
            Union(r1, r2);
    }
    int cnt=0;
    for (int i = 1; i <= n; ++i) {
        if (S[i] < 0)
            ++cnt;
    }
    printf("%s\n",n >= m+cnt ? "Good" : "Bad");
    // fclose(stdin);
}
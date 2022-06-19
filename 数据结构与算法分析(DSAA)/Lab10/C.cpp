#include "cstdio"
#include "queue"
#include "cstring"
using namespace std;
#define maxn 100010

typedef int Vertex;
typedef int SetName;
struct Edge{
    Vertex V1;
    Vertex V2;
    long long weight;
    Edge(int a,int b,int c){
        V1 = a,V2 = b,weight = c;
    }
    bool operator < (const Edge &x)const{
        return weight > x.weight;
    }
};
int n,m;
SetName S[maxn];
priority_queue<Edge> q;

void Union(SetName Root1,SetName Root2){
    if (S[Root1] < S[Root2]) {
        S[Root1] += S[Root2];
        S[Root2] = Root1;
    } else {
        S[Root2] += S[Root1];
        S[Root1] = Root2;
    }
}
SetName find(Vertex V){
    if (S[V] < 0)
        return V;
    else
        return find(S[V]);
}
bool check(Vertex v,Vertex u){
    SetName r1,r2;
    r1 = find(v);
    r2 = find(u);
    if (r1 == r2)
        return false;
    else{
        Union(r1,r2);
        return true;
    }
}
void Insert(Vertex u,Vertex v,int w){
    q.push(Edge(u,v,w));
}
void Kruskal(){
    long long ans=0;
    for (int i = 1; i < n;) {
        Edge tmp = q.top();
        q.pop();
        if (check(tmp.V1,tmp.V2)){
            ans += tmp.weight;
            ++i;
        }
    }
    printf("%lld\n",ans);
}

int main(){
    int u,v,w;
    scanf("%d%d",&n,&m);
    memset(S, -1, sizeof S);
    for (int i = 0; i < m; ++i) {
        scanf("%d%d%d",&u,&v,&w);
        Insert(u,v,w);
    }
    Kruskal();
    return 0;
}
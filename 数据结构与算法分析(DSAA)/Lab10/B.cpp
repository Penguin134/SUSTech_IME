#include "cstdio"
#include "vector"
#include "stack"
#include "cstring"
using namespace std;

#define maxn 100010
typedef int Vertex;
typedef Vertex SetName;
vector<Vertex> Adj[maxn];
stack<Vertex> s;
SetName scc[maxn],S[maxn];
int n_ssc,dfn[maxn],low[maxn],indge[maxn],oudge[maxn];
int dftc = 0,n,m,n_S=0;


inline void initSet(){
    memset(S, -1, sizeof S);
    n_S = n;
}
void Union(SetName Root1,SetName Root2){
    if (S[Root1] > S[Root2]){
        S[Root2] += S[Root1];
        S[Root1] = Root2;
    } else {
        S[Root1] += S[Root2];
        S[Root2] = Root1;
    }
}
SetName findRoot(Vertex X){
    if (S[X] < 0)
        return X;
    else
        return findRoot(S[X]);
}
inline void connect(Vertex V1,Vertex V2){
    int R1 = findRoot(V1),R2 = findRoot(V2);
    if (R1 != R2){
        Union(R1,R2);
        --n_S;
    }
}

void DFS(Vertex v){
    dfn[v] = low[v] = ++dftc;
    s.push(v);
    for (int i = 0; i < Adj[v].size(); ++i) {
        Vertex u = Adj[v][i];
        if (!dfn[u]){
            DFS(u);
            low[v] = low[v] < low[u] ? low[v] : low[u];
        } else if (!scc[u]){
            low[v] = low[v] < dfn[u] ? low[v] : dfn[u];

        }
    }
    if (dfn[v] == low[v]){
        ++n_ssc;
        Vertex u;
        do {
            u = s.top();
            s.pop();
            scc[u] = n_ssc;
        }while (v != u);
    }
}
int a=0,b=0;
inline void degree_cal(){
    for (int i = 1; i <= n; ++i) {
        for (int j = 0; j < Adj[i].size(); ++j) {
            Vertex v = Adj[i][j];
            if (scc[i] != scc[v]){
                ++oudge[scc[i]];
                ++indge[scc[v]];
            }
        }
    }
    for (int k = 1; k <= n_ssc; ++k) {
        if (!indge[k])
            ++a;
        if (!oudge[k])
            ++b;
    }
}
inline void update_dge(Vertex u,Vertex v){ // u -> v

    if (!oudge[scc[u]]){
        --b;
    }
    if (!indge[scc[v]]){
        --a;
    }
    ++ oudge[scc[u]];
    ++ indge[scc[v]];
}
int main(){
    int u,v,i;
    scanf("%d%d",&n,&m);
    initSet();
    for (i = 0; i < m; ++i) {
        scanf("%d%d",&u,&v);
        Adj[u].push_back(v);
        connect(u,v);
        if (n_S == 1)
            break;
    }
    if (n_S != 1){
        printf("-1");
        return 0;
    }
    for (int j = 1; j <= n; ++j) {
        if (!dfn[j])
            DFS(j);
    }
    degree_cal();
    for (++i; i < m; ++i) {
        scanf("%d%d",&u,&v);
        if (u != v)
            update_dge(u,v);
        if (!a && !b){
            printf("%d",i+1);
            return 0;
        }
    }
    return 0;
}
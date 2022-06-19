#include "cstdio"
#include "vector"
#include "stack"
using namespace std;

#define maxn 100010
typedef int Vertex;
typedef Vertex SetName;
vector<Vertex> Adj[maxn];
stack<Vertex> s;
SetName S[maxn];
int n_ssc,dfn[maxn],low[maxn],indge[maxn],oudge[maxn];
int dftc = 0,n,m;

void DFS(Vertex v){
    dfn[v] = low[v] = ++dftc;
    s.push(v);
    for (int i = 0; i < Adj[v].size(); ++i) {
        Vertex u = Adj[v][i];
        if (!dfn[u]){
            DFS(u);
            low[v] = low[v] < low[u] ? low[v] : low[u];
        } else if (!S[u]){
            low[v] = low[v] < dfn[u] ? low[v] : dfn[u];
        }
    }
    if (dfn[v] == low[v]){
        ++n_ssc;
        Vertex u;
        do {
            u = s.top();
            s.pop();
            S[u] = n_ssc;
        }while (v != u);
    }
}
void degree_cal(){
    for (int i = 1; i <= n; ++i) {
        for (int j = 0; j < Adj[i].size(); ++j) {
            Vertex v = Adj[i][j];
            if (S[i] != S[v]){
                ++oudge[S[i]];
                ++indge[S[v]];
            }
        }
    }
}
int main(){
    int u,v;
    scanf("%d%d",&n,&m);
    for (int i = 0; i < m; ++i) {
        scanf("%d%d",&u,&v);
        Adj[u].push_back(v);
    }
    for (int i = 1; i <= n; ++i) {
        if (!dfn[i])
            DFS(i);
    }
    degree_cal();
    int a=0,b=0;
    for (int i = 1; i <= n_ssc; ++i) {
        if (!indge[i])
            ++a;
        if (!oudge[i])
            ++b;
    }
    if (n_ssc == 1){
        printf("0");
        return 0;
    }
    printf("%d",a > b ? a : b);
}
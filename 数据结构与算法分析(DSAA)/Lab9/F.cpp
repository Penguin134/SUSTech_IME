#include "cstdio"
#include "cstring"
#include "vector"
#include "queue"
using namespace std;
#define maxn 100010
#define M 1000000007ll

typedef int Vertex;
vector<Vertex> Adj[maxn];
int inDegree[maxn],TopOrder[maxn];
long long paths[maxn];
int a[maxn],b[maxn],n,m,u,v;
queue<Vertex> q;

inline void init(){
    memset(inDegree,0,sizeof inDegree);
    memset(TopOrder,0,sizeof TopOrder);
    memset(paths,0,sizeof paths);
    memset(a,0,sizeof a);
    memset(b,0,sizeof b);
    for (int i = 0; i < maxn; ++i) {
        Adj[i].clear();
    }
    scanf("%d%d",&n,&m);
    for (int i = 1; i <= n; ++i) {
        scanf("%d%d",&a[i],&b[i]);
    }
    for (int i = 0; i < m; ++i) {
        scanf("%d%d",&u,&v);
        ++inDegree[v];
        Adj[u].push_back(v);
    }
}
inline void TopSort(){
    for (int i = 1; i <= n; ++i) {
        if (!inDegree[i])
            q.push(i);
    }
    int cnt = 0;
    while (!q.empty()){
        Vertex V = q.front();
        q.pop();
        TopOrder[cnt++] = V;
        for (int i = 0; i < Adj[V].size(); ++i) {
            Vertex tmp = Adj[V].at(i);
            if ( --inDegree[tmp] == 0 )
                q.push(tmp);
        }
    }
}
inline void cal(){
    memset(paths,0,sizeof paths);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < Adj[TopOrder[i]].size(); ++j) {
            Vertex tmp = Adj[TopOrder[i]].at(j);
            paths[tmp] += (paths[TopOrder[i]] + a[TopOrder[i]])%M;
            paths[tmp] %= M;
        }
    }
}
inline long long count(int y){
    return paths[y];
}
inline long long f(int j){
    long long ans = count(j);
    ans *= b[j];
    return ans % M;
}
inline void debug(){
    for (int i = 1; i <= n; ++i) {
        printf("%lld ",paths[i]);
    }
    printf("\n");
}
int main(){
    int T;
    scanf("%d",&T);
    while (T--){
        init();
        TopSort();
        // debug();
        long long ans = 0;
        cal();
        for (int j = 1; j <= n; ++j){
            ans += f(j);
            ans %= M;
        }
        printf("%lld\n",ans);
    }
}
#include "cstdio"
#include "vector"
#include "queue"
#include "cstring"
#include "algorithm"
#define maxn 50005
#define INF 100000000001ll
using namespace std;

typedef int Vertex;
struct AdjNode{
    Vertex key;
    long long weight;
    int layer;
    AdjNode(int k,long long w,int l){
        key = k;
        weight = w;
        layer = l;
    }
    bool operator < (const AdjNode &x)const{
        return weight > x.weight;
    }
};
vector<AdjNode> Adj[maxn];
bool visited[maxn][11];
int n,m,p,k;
long long dist[maxn][11],ans=INF;
priority_queue<AdjNode> q;

void Insert(Vertex u,Vertex v,int w){
    AdjNode a = AdjNode(v,w,0);
    Adj[u].push_back(a);
}
AdjNode findMin(){
    if (q.empty())
        return {-1,-1,-1};
    else{
        AdjNode tmp = q.top();
        q.pop();
        return tmp;
    }
}
void Dijkstra(Vertex start){
    for (int i = 1; i <= n; ++i) {
        for (int j = 0; j < 11; ++j) {
            dist[i][j] = INF;
        }
    }
    memset(dist[start],0,sizeof(dist[start]));
    q.push(AdjNode(start,0,0));
    while (true){
        AdjNode V = findMin();
        if (V.layer == -1)
            return;
        if (visited[V.key][V.layer])
            continue;
        visited[V.key][V.layer] = true;
        for (int i = 0; i < Adj[V.key].size(); ++i) {
            auto W = Adj[V.key].at(i);
            if (!W.weight){
                if (V.layer >= k)
                    continue;
                if (dist[W.key][V.layer+1] > dist[V.key][V.layer]){
                    dist[W.key][V.layer+1] = dist[V.key][V.layer];
                    if (!visited[W.key][V.layer+1]){
                        q.push(AdjNode(W.key, dist[W.key][V.layer+1], V.layer+1));
                    }
                }
            } else {
                if (dist[W.key][V.layer] > dist[V.key][V.layer] + W.weight){
                    dist[W.key][V.layer] = dist[V.key][V.layer] + W.weight;
                    if (!visited[W.key][V.layer]){
                        q.push(AdjNode(W.key, dist[W.key][V.layer], V.layer));
                    }
                }
            }
        }
    }
}

int main(){
    int u,v,w,s,t;
    freopen("test1.in","r",stdin);
    scanf("%d%d%d%d",&n,&m,&p,&k);
    for (int i = 0; i < m; ++i) {
        scanf("%d%d%d",&u,&v,&w);
        Insert(u,v,w);
    }
    for (int i = 0; i < p; ++i) {
        scanf("%d%d",&u,&v);
        Insert(u,v,0);
    }
    scanf("%d%d",&s,&t);
    Dijkstra(s);
    for (int i = 0; i <= k; ++i) {
        ans = min(ans,dist[t][i]);
    }
    printf("%lld",ans);
    return 0;
}
#include "cstdio"
#include "vector"
#include "queue"
using namespace std;
#define maxn 100010
#define INF 1000000000000000ll

typedef int Vertex;
struct AdjNode{
    Vertex key;
    long long weight;
    AdjNode(int k,long long w){
        key = k;
        weight = w;
    }
    bool operator < (const AdjNode &x)const{
        return weight > x.weight;
    }
};
vector<AdjNode> Adj[maxn];
bool visited[maxn];
int n,m;
long long path[maxn];
priority_queue<AdjNode> q;

void Insert(Vertex u,Vertex v,int w){
    AdjNode a = AdjNode(v,w);
    Adj[u].push_back(a);
}
Vertex findMin(){
    if (q.empty())
        return -1;
    else{
        AdjNode tmp = q.top();
        q.pop();
        return tmp.key;
    }
}
void Dijkstra(Vertex start){
    for (int i = 1; i <= n; ++i) {
        path[i] = INF;
    }
    path[start] = 0;
    q.push(AdjNode(start,0));
    while (true){
        Vertex V = findMin();
        if (V == -1)
            return;
        //assert(!visited[V]);
        if (visited[V])
            continue;
        visited[V] = true;
        for (int i = 0; i < Adj[V].size(); ++i) {
            auto W = Adj[V].at(i);
            if (path[W.key] > path[V] + W.weight){
                path[W.key] = path[V] + W.weight;
                if (!visited[W.key]){
                    q.push(AdjNode(W.key,path[W.key]));
                }
            }
        }
    }
}

int main(){
    int u,v,w;
    scanf("%d%d",&n,&m);
    for (int i = 0; i < m; ++i) {
        scanf("%d%d%d",&u,&v,&w);
        Insert(u,v,w);
    }
    Dijkstra(1);
    printf("%lld\n",path[n] == INF ? -1 : path[n]);
    return 0;
}

#include "cstdio"
#include "vector"
#include "cstring"
using namespace std;
#define maxn 100010

typedef int Position;
struct TreeNode{
    bool visited = false;
    int priority = 0;
    vector<int> edges;
}node[maxn];

bool out[maxn],visit[maxn];
int dist[maxn];
void init(){
    memset(out,0,sizeof out);
    for (int i = 0; i < maxn; ++i) {
        node[i].visited = false;
        node[i].priority = 0;
        node[i].edges.clear();
    }
}
bool cutTree(Position pos){
    node[pos].visited = true;
    bool flag = false;
    for (int i = 0; i < node[pos].edges.size(); ++i) {
        int temp = node[pos].edges.at(i);
        if (!node[temp].visited && !out[temp]) {
            if (cutTree(temp))
                flag = true;
            else
                out[temp] = true;
        }
    }
    return node[pos].priority == 1 || flag;
}
void dfs(int bng){
    for (int temp : node[bng].edges){
        if (!visit[temp] && !out[temp]){
            visit[temp] = true;
            dist[temp] = dist[bng]+1;
            dfs(temp);
        }
    }
}
int longest(int n, int root){
    memset(visit,0,sizeof visit);
    memset(dist,0,sizeof dist);
    dfs(root);
    int maxlen=0,M=root,ans=0;
    for (int i = 1; i <= n; ++i) {
        if (dist[i]>maxlen){
            maxlen = dist[i];
            M = i;
        }
    }
    memset(visit,0,sizeof visit);
    memset(dist,0,sizeof dist);
    dfs(M);
    for (int i = 1; i <= n; ++i) {
        if (dist[i]>ans){
            ans = dist[i];
        }
    }
    return ans;
}

int main(){
    // freopen("test1.in","r",stdin);
    int T,n,k,u,v,ttt;
    scanf("%d",&T);
    while (T--){
        init();
        scanf("%d%d",&n,&k);
        for (int i = 0; i < n-1; ++i) {
            scanf("%d%d%d",&u,&v,&ttt);
            node[u].edges.push_back(v);
            node[v].edges.push_back(u);
        }
        int pos;
        for (int i = 0; i < k; ++i) {
            scanf("%d",&pos);
            node[pos].priority = 1;
        }
        cutTree(pos);
        printf("%d\n", (longest(n,pos)+1)/2);
    }
    // fclose(stdin);
    return 0;
}
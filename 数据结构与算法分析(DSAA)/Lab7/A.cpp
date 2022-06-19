#include "cstdio"
#include "vector"
#include "queue"
using namespace std;
#define maxn 500010

typedef struct TreeNode *ptrToNodes;
struct TreeNode{
    int visited=0;
    int dis=0;
    vector<ptrToNodes> edges;
    vector<int> weight;
}node[maxn];

int main(){
    int n,num,u,v,w;
    scanf("%d %d",&n,&num);
    for (int i = 1; i < n; ++i) {
        scanf("%d %d %d",&u,&v,&w);
        node[u].edges.push_back(&node[v]);
        node[u].weight.push_back(w);
        node[v].edges.push_back(&node[u]);
        node[v].weight.push_back(w);
    }
    queue<ptrToNodes> q;
    q.push(&node[1]);
    node[1].visited=1;
    while (!q.empty()){
        ptrToNodes temp = q.front();
        q.pop();
        for (int i = 0; i < temp->edges.size(); ++i) {
            if (!temp->edges.at(i)->visited){
                q.push(temp->edges.at(i));
                temp->edges.at(i)->visited=1;
                temp->edges.at(i)->dis = temp->dis + temp->weight.at(i);
            }
        }
    }
    int ans=0;
    for (int i = 1; i <= n; ++i) {
        if (node[i].edges.size()==1 && node[i].dis==num)
            ++ans;
    }
    printf("%d",ans);
    return 0;
}

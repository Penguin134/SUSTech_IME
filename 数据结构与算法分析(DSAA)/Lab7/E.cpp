#include "cstdio"
#include "vector"
#include "stack"
using namespace std;
#define maxn 5010

typedef int Position;
struct TreeNode{
    bool visited = 0;
    vector<int> edges;
}node[maxn];

vector<vector<int>> path;
vector<int> p,ans;
int leaves[5001], order[5001], nxt[5001];
int cnt[5001];

void dfs(Position root, vector<int> p1,vector<vector<int>> &p2){
    p1.push_back(root);
    node[root].visited = 1;
    if (node[root].edges.size()==1 && root!=1)
        p2.push_back(p1);
    else {
        stack<int> s;
        for (int i = 0; i < node[root].edges.size(); ++i) {
            int t = node[root].edges.at(i);
            if (!node[t].visited)
                s.push(t);
        }
        while (!s.empty()){
            int r = s.top();
            s.pop();
            dfs(r,p1,p2);
        }
    }
}
void buildPath_1(int index, int start){
    for (int i = start; i < path.at(index).size(); ++i) {
        //printf("%d ",path.at(index).at(i));
        ans.push_back(path.at(index).at(i));
    }
}
void buildPath_2(int index, int terminal){
    for (int i = path.at(index).size()-2; i >= terminal ; --i) {
        //printf("%d ",path.at(index).at(i));
        ans.push_back(path.at(index).at(i));
    }
}

int main(){
    int n,u,v;
    scanf("%d",&n);
    for (int i = 1; i < n; ++i) {
        scanf("%d%d",&u,&v);
        node[u].edges.push_back(v);
        node[v].edges.push_back(u);
    }
    dfs(1,p,path);
    for (int i = 0; i < path.size(); ++i) {
        leaves[path.at(i).back()] = i;
    }
    int len=0;
    int k1=0;
    for (int i = 0;i < path.size(); ++i){
        scanf("%d",&k1);
        order[len] = k1;
        ++len;
    }
    for (int i = 1; i < len; ++i) {
        for (int j = 0; j < min(path.at(leaves[order[i-1]]).size(),
                                path.at(leaves[order[i]]).size()); ++j) {
            if (path.at(leaves[order[i-1]]).at(j)==path.at(leaves[order[i]]).at(j))
                nxt[i]++;
        }
    }
    buildPath_1(leaves[order[0]], 0);
    for (int i = 1; i < len; ++i) {
        buildPath_2(leaves[order[i - 1]], nxt[i] - 1);
        buildPath_1(leaves[order[i]], nxt[i]);
    }
    buildPath_2(leaves[order[len - 1]], 0);

    for (int i = 0; i < ans.size(); ++i) {
        cnt[ans.at(i)]++;
    }
    cnt[1]--;
    for (int i = 1; i <= n; ++i) {
        if (cnt[i]!=node[i].edges.size()){
            printf("-1\n");
            return 0;
        }
    }
    for (int an : ans) {
        printf("%d ",an);
    }
    return 0;
}
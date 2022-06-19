#include "cstdio"
#include "cstring"
using namespace std;

struct Tree{
    int value;
    Tree *left;
    Tree *right;
};

int in[1030],post[1030],map[1030];
int now;

Tree *findRoot(int l,int r){
    if (l > r || now < 0)
        return NULL;
    int root_id = post[now];
    Tree *root = new Tree();
    root->value = root_id;
    int idx = map[root_id];
    --now;
    root->right = findRoot(idx+1,r);
    root->left = findRoot(l,idx-1);
    return root;
}
inline Tree *build(int n){
    now = n-1;
    memset(in,0,sizeof in);
    memset(post,0,sizeof post);
    memset(map,0,sizeof map);
    for (int i = 0; i < n; ++i) {
        scanf("%d",&in[i]);
    }
    for (int i = 0; i < n; ++i) {
        scanf("%d",&post[i]);
    }
    for (int i = 0; i < n; ++i) {
        map[in[i]] = i;
    }
    return findRoot(0,n-1);
}
void PreOrder(Tree *T){
    if (!T)
        return;
    printf("%d ",T->value);
    PreOrder(T->left);
    PreOrder(T->right);
}
int main(){
    int q,n;
    scanf("%d",&q);
    while (q--){
        scanf("%d",&n);
        Tree *T = build(n);
        PreOrder(T);
        printf("\n");
    }
    return 0;
}
#include "cstdio"
#include "cstdlib"
using namespace std;
typedef struct Item *ptrToNode;
typedef ptrToNode List;
struct Item{
    int weight;
    int root;
    int tail;
    List next;
};
List Set[1000010];
typedef int Index;

void init(int n){
    for (int i = 1; i <= n; ++i) {
        Set[i] = (List)malloc(sizeof (struct Item));
        scanf("%d",&Set[i]->weight);
        Set[i]->next = NULL;
        Set[i]->root = Set[i]->tail = i;
    }
}
void link(Index a,Index b){
    Set[Set[a]->tail]->next = Set[b];
    Set[a]->tail = Set[b]->tail;
    Set[b]->root = a;
}
int main(){
    int n,p,q;
    scanf("%d%d%d",&n,&p,&q);
    init(n);
    while (p--){
        int a,b;
        scanf("%d %d",&a,&b);
        link(a,b);
    }
    for (int i = 1; i <= n; ++i) {
        if (Set[i]->root == i){
            List tmp = Set[i];
            int j=1;
            for (; j < q && tmp->next; ++j) {
                tmp = tmp->next;
            }
            if (j == q)
                printf("%d ",tmp->weight);
        }
    }
    return 0;
}
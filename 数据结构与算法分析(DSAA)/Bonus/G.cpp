#include "cstdio"
#include "cstdlib"
using namespace std;

struct node{
    int next;
    int pre;
};

int n,m,k,x;
node total[1000010];

inline void exchange(int a,int b){
    total[total[b].pre].next = total[a].next;
    total[total[a].next].pre = total[b].pre;
    total[a].next = b;
    total[b].pre = a;
}
inline void init(){
    for (int i = 0; i < n*m; ++i){
        total[i].next = i+1;
        total[i].pre = i-1;
    }
    for (int i = 0; i < n; ++i){
        total[i*m].pre = -1;
        total[i*m + m - 1].next = -1;
    }
}
int main(){
    scanf("%d%d%d%d",&n,&m,&k,&x);
    init();
    int a,b;
    for (int i = 0; i < k; ++i) {
        scanf("%d%d",&a,&b);
        exchange(a,b);
    }
    int c = x;
    while (total[c].pre >= 0){
        c = total[c].pre;
    }
    while (c >= 0){
        printf("%d ",c);
        c = total[c].next;
    }
}
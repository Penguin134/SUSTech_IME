#include "cstdio"
#include "algorithm"
#define hrh 500005
#define INF 1000000007ll
using namespace std;

long long heap[3][hrh]; //n
long long a[hrh], b[hrh]; //n m
int size = 0;

void build(long long val);
void init(int n, int m){
    for (int i = 1; i <= n; ++i) {
        scanf("%lld",&a[i]);
        heap[1][i] = i;
        heap[2][i] = 1;
    }
    for (int i = 1; i <= m; ++i) {
        scanf("%lld",&b[i]);
    }
    sort(a+1,a+1+n);
    sort(b+1,b+1+m);
    b[m+1] = INF;
    for (int i = 1; i <= n; ++i) {
        build(a[i] * b[1]);
    }
}
void build(long long val){
    int p = ++size;
    heap[0][size] = val;
    while(p > 1){
        if (heap[0][p] < heap[0][p/2]){
            swap(heap[0][p],heap[0][p/2]);
            swap(heap[1][p],heap[1][p/2]);
            swap(heap[2][p],heap[2][p/2]);
            p/=2;
        } else
            break;
    }
}
long long update(){
    long long up = heap[0][1];
    ++heap[2][1];
    if (b[heap[2][1]] == INF)
        heap[0][1] = INF*INF;
    else
        heap[0][1] = a[heap[1][1]] * b[heap[2][1]];
    int s = 2, t = 1;
    while (s <= size){
        if (s <= size - 1 && heap[0][s] > heap[0][s + 1])
            ++s;
        if (heap[0][t] > heap[0][s]){
            swap(heap[0][s], heap[0][t]);
            swap(heap[1][s], heap[1][t]);
            swap(heap[2][s], heap[2][t]);
            t = s;
            s*=2;
        }
        else
            break;
    }
    return up;
}

int main(){
    int N,M,K;
    scanf("%d%d%d",&N,&M,&K);
    init(N,M);
    while (K--){
        printf("%lld ",update());
    }
    return 0;
}
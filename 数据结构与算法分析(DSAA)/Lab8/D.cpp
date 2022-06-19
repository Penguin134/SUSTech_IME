#include "cstdio"
#include "algorithm"
#define hrh 500005
using namespace std;

long long heap[hrh];
int size = 0;

void build(long long val);
void init(int len){
    for (int i = 1; i <= len; ++i) {
        scanf("%lld",&heap[i]);
        build(heap[i]);
    }
}
void build(long long val){
    int p = ++size;
    heap[size] = val;
    while(p > 1){
        if (heap[p] < heap[p/2]){
            swap(heap[p],heap[p/2]);
            p = p / 2;
        }
        else
            break;
    }
}
void min_remove_top(){
    int s = 2, t = 1;
    heap[1] = heap[size--];
    while (s <= size){
        if (s <= size - 1 && heap[s+1] < heap[s])
            ++s;
        if (heap[s] < heap[t]){
            swap(heap[s], heap[t]);
            t = s;
            s*=2;
        }
        else
            break;
    }
}
long long get_top(){
    return heap[1];
}

int main(){
    int N;
    scanf("%d",&N);
    init(N);
    long long ans = 0;
    while (size >= 2){
        long long a = get_top();
        remove_top();
        long long b = get_top();
        remove_top();
        ans += (a + b);
        build(a + b);
    }
    printf("%lld\n",ans);
    return 0;
}

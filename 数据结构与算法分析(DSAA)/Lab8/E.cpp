#include "cstdio"
#include "algorithm"
#define hrh 500005
using namespace std;

int heap1[hrh],heap2[hrh];
// size in heap[0]
// 1~max 2~min

void build1(int val);
void build2(int val);
void remove_top1();
void remove_top2();
int get_top(int *heap);
void Insert(int val){
    if (!heap1[0] || get_top(heap1) >= val){
        build1(val);
        if (heap1[0] > heap2[0] + 1){
            build2(get_top(heap1));
            remove_top1();
        }
    } else {
        build2(val);
        if (heap1[0] < heap2[0]){
            build1(get_top(heap2));
            remove_top2();
        }
    }
}
int main(){
    int N,A;
    heap1[0] = heap2[0] = 0;
    scanf("%d",&N);
    for (int i = 1; i <= N; ++i) {
        scanf("%d",&A);
        Insert(A);
        printf("%d ", get_top(heap1));
    }
    return 0;
}
void build1(int val){
    int p = ++heap1[0];
    heap1[heap1[0]] = val;
    while(p > 1){
        if (heap1[p] > heap1[p/2]){
            swap(heap1[p],heap1[p/2]);
            p = p / 2;
        }
        else
            break;
    }
}
void build2(int val){
    int p = ++heap2[0];
    heap2[heap2[0]] = val;
    while(p > 1){
        if (heap2[p] < heap2[p/2]){
            swap(heap2[p],heap2[p/2]);
            p = p / 2;
        }
        else
            break;
    }
}
void remove_top1(){
    int s = 2, t = 1;
    heap1[1] = heap1[heap1[0]--];
    while (s <= heap1[0]){
        if (s <= heap1[0] - 1 && heap1[s+1] > heap1[s])
            ++s;
        if (heap1[s] > heap1[t]){
            swap(heap1[s], heap1[t]);
            t = s;
            s*=2;
        }
        else
            break;
    }
}
void remove_top2(){
    int s = 2, t = 1;
    heap2[1] = heap2[heap2[0]--];
    while (s <= heap2[0]){
        if (s <= heap2[0] - 1 && heap2[s+1] < heap2[s])
            ++s;
        if (heap2[s] < heap2[t]){
            swap(heap2[s], heap2[t]);
            t = s;
            s*=2;
        }
        else
            break;
    }
}
int get_top(int *heap){
    return heap[1];
}
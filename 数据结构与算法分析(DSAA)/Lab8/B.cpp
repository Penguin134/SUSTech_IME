#include "cstdio"
using namespace std;
#define maxn 1000010

int heap[maxn];
bool isMax=0,isMin=0;

void check(int size){
    for (int i = 1; i <= size; ++i) {
        int l = 2*i, r = 2*i +1;
        if (l <= size){
            isMin = isMin ? isMin : heap[l] > heap[i];
            isMax = isMax ? isMax : heap[l] < heap[i];
        }
        if (r <= size){
            isMin = isMin ? isMin : heap[r] > heap[i];
            isMax = isMax ? isMax : heap[r] < heap[i];
        }
        if (isMax && isMin){
            printf("Neither\n");
            return;
        }
    }
    printf("%s\n",isMax ? "Max" : "Min");
}

int main(){
    int N;
    scanf("%d",&N);
    for (int i = 1; i <= N; ++i) {
        scanf("%d",&heap[i]);
    }
    check(N);
}
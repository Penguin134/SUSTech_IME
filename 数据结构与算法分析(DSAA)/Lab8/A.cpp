#include "cstdio"
using namespace std;
#define maxn 300006

int heap[maxn],size=0;

int up(int index){
    int ans=0;
    while (index > 1){
        int p = index/2,temp;
        if(heap[p] < heap[index]){
            temp = heap[p];
            heap[p] = heap[index];
            heap[index] = temp;
            ++ans;
            index/=2;
        }else
            break;
    }
    return ans;
}

void insert(int num){
    heap[++size] = num;
    printf("%d ", up(size));
}

int main(){
    int N,a;
    scanf("%d",&N);
    for (int i = 1; i <= N; ++i) {
        scanf("%d",&a);
        insert(a);
    }
}

#include "iostream"
#include "cstring"
#include "cmath"
#define Infinity 1l<<60
// value, row, column
long long heap[3][50005];
int size,n;

long long f(long long i,long long j){
    return i*i + 12345*i + j*j - 12345*j + i*j;
}

void BuildHeap(int row,int column){
    heap[0][++size] = f(row,column);
    heap[1][size] = row;
    heap[2][size] = column;
    int p = size;
    while (p > 1){
        if (heap[0][p] < heap[0][p/2]){
            std :: swap(heap[0][p],heap[0][p/2]);
            std :: swap(heap[1][p],heap[1][p/2]);
            std :: swap(heap[2][p],heap[2][p/2]);
            p/=2;
        } else
            break;
    }
}
long long update(){
    long long up = heap[0][1];
    heap[2][1] ++;
    if (heap[2][1] > n)
        heap[0][1] = Infinity;
    else
        heap[0][1] = f(heap[1][1], heap[2][1]);
    int p=1,s=2;
    while (s <= size){
        if (s <= size - 1 && heap[0][s] > heap[0][s + 1])
            ++s;
        if (heap[0][p] > heap[0][s]){
            std :: swap(heap[0][p], heap[0][s]);
            std :: swap(heap[1][p], heap[1][s]);
            std :: swap(heap[2][p], heap[2][s]);
            p = s;
            s*=2;
        }
        else
            break;
    }
    return up;
}
void init(int n0){
    memset(heap,0,sizeof (heap));
    size = 0;
    for (int i = 1; i <= n0; ++i) {
        BuildHeap(1,i);
    }
}
int main(){
    int m,t;
    std :: cin>>t;
    while (t--){
        std :: cin>>n>>m;
        // (12345 - 1) / 2 = 6172
        // memset(A,0,sizeof (A));
        init(n);
        while (--m){
            update();
        }
        std :: cout<<update()<<std :: endl;
    }

    return 0;
}
/*
    5
    50000 250000
    100 1000
    200 10000
    200 2000
    200 1
    -37956629
    -785789
    -2284949
    -2225094
    -2416454
 */
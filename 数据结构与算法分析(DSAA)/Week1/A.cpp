//
// Created by Penguin on 2021/9/7.
//

#include "cstdio"
#include "iostream"
#include "algorithm"
using namespace std;
int heap[10001], len = 0;

void up(int ar[], int X);
void init(int ar[]){
    int N,ab;
    cin>>N;
    for (int i = 0; i < N; ++i) {
        cin>>ab;
        up(ar,ab);
    }
}
void up(int ar[], int X){
    int p = ++len;
    ar[len] = X;
    while(p > 1){
        if (ar[p] < ar[p/2]){
            swap(ar[p],ar[p/2]);
            p = p / 2;
        }
        else
            break;
    }
}
void Find(int ar[], int X){
    for (int i = 1; i < len; ++i) {
        if (ar[i] == X) {
            cout << "yes" << endl;
            return;
        }
    }
    cout<<"no"<<endl;
}

int main(){
    init(heap);
    int T,b;
    cin>>T;
    for (int i = 0; i < T; ++i) {
        cin>>b;
        Find(heap,b);
    }
}

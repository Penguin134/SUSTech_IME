//
// Created by Penguin on 2021/9/14.
//

#include "iostream"
using namespace std;
int a,T;
long long table[1000002];

long long f(long long i){
    return i * (i + 1) / 2l;
}
void FindAns(){
    for (long long i = 1; i <= 1000000; ++i){
        table[i] = table[i-1] + f(i);
    }
}
int main(){
    cin>>T;
    FindAns();
    for (int i = 0; i < T; ++i) {
        cin >> a;
        cout<<table[a]<<endl;
    }

}
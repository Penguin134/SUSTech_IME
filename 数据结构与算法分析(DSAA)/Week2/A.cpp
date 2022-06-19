//
// Created by Penguin on 2021/9/9.
//

#include "iostream"
#define MAX_NUM 1000001
using namespace std;
int a[MAX_NUM],N;

string BinSearch(int b){
    int left=0,right=N-1;
    int middle = (left + right) / 2;
    while (left <= right){
        if (a[middle] > b)
            right = middle - 1;
        else if (a[middle] < b)
            left = middle + 1;
        else if(left == right)
            return "YES";
        else
            right = middle;
        middle = (left + right) / 2;
    }
    return "NO";
}
int main(){
    int m,b;
    cin>>N;
    for (int i = 0; i < N; ++i)
        cin>>a[i];
    cin>>m;
    for (int i = 0; i < m; ++i) {
        cin>>b;
        cout<<BinSearch(b)<<endl;
    }
    return 0;
}

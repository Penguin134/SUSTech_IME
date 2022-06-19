//
// Created by Penguin on 2021/9/14.
//

#include "iostream"
#include "cstring"
#define MAX_NUM 100010
using namespace std;
int a[MAX_NUM],b[MAX_NUM],n;

void BinSearch(int l, int r){
    int l1 = l,l2 = l,r1 = r,r2 = r;
    int middle1;
    int middle2;
    while (l1 < r1 - 1 && l2 < r2 - 1) {

        if ((l1 - r1 + 1) % 2){
            middle1 = (l1+r1)/2;
            middle2 = (l2+r2)/2;
        } else{
            middle1 = (l1 + r1)/2 + 1;
            middle2 = (l2 + r2)/2;
        }

        if (a[middle1] == b[middle2]) {
            cout << a[middle1] << endl;
            return;
        }
        else if (a[middle1] < b[middle2]) {
            l1 = middle1;
            r2 = middle2;
        } else {
            r1 = middle1;
            l2 = middle2;
        }
    }
    if (l1 == r1 - 1){
        // assert(l2 == r2 - 1);
        if (b[l2] > a[l1])
            cout<<(b[l2] > a[r1] ? a[r1] : b[l2])<<endl;
        else
            cout<<(a[l1] > b[r2] ? b[r2] : a[l1])<<endl;

        return;
        // 5 7
        // 6 9
    }
    // assert(l1 == r1 && l2 == r2);
    if (a[l1] < b[l2])
        cout<<a[l1]<<endl;
    else
        cout<<b[l2]<<endl;
}


int main(){
    int T,l,r;
    cin>>n>>T;
    for (int i = 1; i <= n; ++i)
        cin>>a[i];
    for (int i = 1; i <= n; ++i){
        cin>>b[i];
    }
    for (int i = 0; i < T; ++i) {
        cin>>l>>r;
        BinSearch(l,r);
    }
    return 0;
}
//
// Created by Penguin on 2021/9/7.
//

#include "iostream"
#include "cmath"
#include "string.h"
using namespace std;

void Di(long long n){
    long long i=n;
    int l=1;
    while (i>0){
        i -= (int)pow(3,l);
        ++l;
    }
    i += (int)pow(3,--l);
    int digest[l+2];
    memset(digest,0,sizeof (digest));
    int len = l;
    --i;l=1;
    while(i){ //减1，后辗转相除法
        switch (i%3) {
            case 0: digest[l] = 0;break;
            case 1: digest[l] = 1;break;
            case 2: digest[l] = 4;break;
        }
        i/=3;++l;
    }
    for (int j = len; j >= 1; --j) {
        cout<<digest[j]+2;
    }
    cout<<endl;
}

int main(){
    int T;
    long long n;
    cin>>T;
    for (int i = 0; i < T; ++i) {
        cin>>n;
        Di(n);
    }
}
/**
* 2 3 6 22 23 26 32 33 36 62 63 66 222 223
 * 13 1 2 3 4 5 6 7 8 9 10 11 12 13
*/
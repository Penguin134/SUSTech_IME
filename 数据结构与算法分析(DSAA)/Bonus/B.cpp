#include "cstdio"
#include "cstring"
#include "cmath"
#define M 998244353ll
using namespace std;

int n;
long long ans[1001], C[1001][1001];

void init(){
    memset(ans,-1,sizeof ans);
    memset(C,-1,sizeof C);
}
// choose m from k
long long Combination(int m,int k){
    if (m > k)
        return 0;
    if (k <= 1)
        return 1;
    if (m == 0) // m == k == 0
        return 1;
    if (C[m][k] != -1)
        return C[m][k] % M;
    else{
        C[m][k] = Combination(m,k-1)%M + Combination(m-1,k-1)%M;
        C[m][k] %= M;
        return C[m][k]%M;
    }
}
inline int left(int m){
    int h = floor(log2(m));
    int button = m - (1 << h) + 1;
    return button >= (1<<h)/2 ? (1<<h)-1 : (1<<h)/2-1+button;
}
inline int right(int m){
    return m - 1 - left(m);
}
long long findAns(int m){
    if (m <= 1)
        return 1;
    if (ans[m] != -1)
        return ans[m] % M;
    int l = left(m), r = right(m);
    ans[m] = Combination(l,m-1)*findAns(l)%M;
    ans[m] = ans[m] * findAns(r) % M;
    return ans[m] % M;
}
int main(){
    scanf("%d",&n);
    init();
    printf("%lld", findAns(n));
    return 0;
}

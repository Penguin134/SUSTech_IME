#include "cstdio"
using namespace std;
#define maxn 1000001

int cnt[maxn];

int main(){
    int n,tmp1,tmp2;
    scanf("%d",&n);
    for (int i = 1; i < n; ++i) {
        scanf("%d %d",&tmp1,&tmp2);
        cnt[tmp1]++;
        cnt[tmp2]++;
    }
    for (int i = 1; i <= n; ++i) {
        if (cnt[i] == 1)
            printf("%d ",i);
    }
    return 0;
}
//
// Created by Penguin on 2021/9/22.
//
#include "cstdio"
#include "cstring"
using namespace std;
int c[200010],temp[200010];
long long num_of_inverse;

void merge(int n, int m){
    int left = 0, right = n, index = 0;
    while (left < n && right < n + m){
        if (c[left] <= c[right]){
            num_of_inverse += right - n;
            temp[index++] = c[left++];
        }
        else{
            temp[index++] = c[right++];
        }
    }
    while (left < n){
        num_of_inverse += m;
        temp[index++] = c[left++];
    }
    while (right < n + m)
        temp[index++] = c[right++];
}

int main(){
    int T,n,m;
    scanf("%d",&T);
    while (T--){
        memset(c,0,sizeof (c));
        memset(temp,0,sizeof (temp));
        num_of_inverse = 0;
        scanf("%d %d",&n,&m);
        for (int i = 0; i < n; ++i)
            scanf("%d",&c[i]);
        for (int i = n; i < n + m; ++i)
            scanf("%d",&c[i]);
        merge(n,m);
        printf("%lld\n",num_of_inverse);
        for (int i = 0; i < n+m; ++i)
            printf("%d ",temp[i]);
        printf("\n");
    }
    return 0;
}

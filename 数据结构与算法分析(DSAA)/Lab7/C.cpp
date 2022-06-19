#include "iostream"
#include "cmath"
using namespace std;

int main(){
    int T;
    long long num;
    scanf("%d",&T);
    while (T--){
        scanf("%lld",&num);
        int ans = log2(num)+1;
        printf("%d\n",ans);
    }
    return 0;
}
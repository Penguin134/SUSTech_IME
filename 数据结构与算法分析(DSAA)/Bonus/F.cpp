#include "cstdio"
#include "cmath"
using namespace std;

void check(){
    int t,a,b;
    scanf("%d",&t);
    while (t--){
        scanf("%d%d",&a,&b);
        if (a > b){
            printf("0\n");
            continue;
        }
        int l = ceil(log2(a));
        int r = 1<<l;
        int mod = b % r;
        if (mod < a){
            printf("0\n");
            continue;
        }
        int time = b/r;
        if (a % 2){
            printf("%d\n",(a^mod) > (a^(mod+1)) ? (a^(mod+1)) + l*time : (a^(mod+2)) + l*time);
        } else {
            // printf("%d\n",(a^(mod+1)) + l*time);
        }
    }
}
void print(){
    for (int i = 0; i <= 37; ++i) {
        printf("%d ",18^i);
    }
}
int main(){
    print();
}
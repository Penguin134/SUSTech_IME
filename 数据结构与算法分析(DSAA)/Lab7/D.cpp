#include "cstdio"
#include "cstring"
using namespace std;

char c1[26],c2[26];
int duplicate=0;
int main(){
    int T;
    scanf("%d",&T);
    while (T--){
        memset(c1,0,sizeof c1);
        memset(c2,0,sizeof c2);
        duplicate = 0;
        scanf("%s",&c1[0]);
        scanf("%s",&c2[0]);
        int n = strlen(c1);
        for (int i = 1; i < n; ++i)
            for (int j = 1; j < n; ++j)
                duplicate = c1[i-1]==c2[j]&&c1[i]==c2[j-1] ? duplicate+1 : duplicate;
        printf("%lld\n",1ll<<duplicate);
    }
    return 0;
}
/**
 * ABCD
 * DCBA
 *
*/
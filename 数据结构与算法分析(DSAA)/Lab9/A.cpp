#include "cstdio"
#include "cstring"
using namespace std;
int adjMatrix[1002][1002];

int main(){
    int T,n,m,u,v;
    scanf("%d",&T);
    while (T--){
        scanf("%d%d",&n,&m);
        memset(adjMatrix,0,sizeof adjMatrix);
        for (int i = 0; i < m; ++i) {
            scanf("%d%d",&u,&v);
            ++adjMatrix[u][v];
        }
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= n; ++j) {
                printf("%d ",adjMatrix[i][j]);
            }
            printf("\n");
        }
    }
    return 0;
}

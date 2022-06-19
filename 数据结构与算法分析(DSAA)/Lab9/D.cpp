#include "cstdio"
#include "stack"
#include "algorithm"
#include "cstring"
using namespace std;

struct Position{
    int x;
    int y;
    Position(int a,int b){x=a,y=b;}
};

int map[7][7];
bool v[7][7];
long long fal = 0;
int px[] = {-1,-1,-1,0,0,1,1,1};
int py[] = {1,0,-1,1,-1,1,0,-1};
int T,N,M;

bool judge(Position p){
    for (int i = 0; i < 8; ++i) {
        int x = p.x + px[i];
        int y = p.y + py[i];
        if (x < 0 || x >= N || y < 0 || y >= M)
            continue;
        if (v[x][y])
            return false;
    }
    return true;
}
Position next(Position p){
    if (p.x + 1 >= N){
        if (p.y + 1 >= M)
            return {-1,-1};
        else
            return {0,p.y+1};
    } else {
        return {p.x+1,p.y};
    }
}
void find(Position p, long long ans){
    if (p.x == -1) {
        fal = max(fal,ans);
        return;
    }
    if (judge(p)){
        v[p.x][p.y] = true;
        ans += map[p.x][p.y];
        find(next(p),ans);
        v[p.x][p.y] = false;
        ans -= map[p.x][p.y];
        find(next(p),ans);
    } else {
        find(next(p),ans);
    }
}

int main(){
    scanf("%d",&T);
    while (T--){
        scanf("%d%d",&N,&M);
        memset(map,0,sizeof map);
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < M; ++j) {
                scanf("%d",&map[i][j]);
            }
        }
        fal = 0;
        memset(v,0,sizeof v);
        find(Position(0,0),0);
        printf("%lld\n",fal);
    }
}
/**
 * 6 6
 * 10 10 10 10 10 10
 * 10 20 10 10 20 10
 * 10 10 10 10 10 10
 * 10 20 10 10 20 10
 * 10 10 10 10 10 10
 * 10 20 10 10 20 10
 */
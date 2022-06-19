#include "cstdio"
#include "cstdlib"
#include "cstring"
#include "queue"
using namespace std;

bool visited[10][10],flag= false;
queue<int> q1,q2,q3;
int px[] = {-2,-2,2,2,-1,-1,1,1};
int py[] = {-1,1,-1,1,-2,2,-2,2};

void view(int x1,int y1,int x2,int y2,int iter){
    visited[x1][y1] = true;
    if (x1 == x2 && y1 == y2){
        flag = true;
        printf("%d\n",iter);
    }
}
bool legal(int x1,int y1){
    if (x1 < 1 || y1 < 1 || x1 > 8 || y1 > 8)
        return false;
    if (visited[x1][y1])
        return false;
    return true;
}

void bfs(int x1,int y1,int x2,int y2,int iter){
    view(x1,y1,x2,y2,iter);
    for (int i = 0; i < 8; ++i) {
        if(legal(x1+px[i],y1+py[i])){
            q1.push(x1+px[i]);
            q2.push(y1+py[i]);
            q3.push(iter+1);
        }
    }
    while (!q1.empty() && !flag){
        int a = q1.front(), b = q2.front() ,c = q3.front();
        q1.pop(),q2.pop(),q3.pop();
        bfs(a,b,x2,y2,c);
    }
}
void init(){
    while (!q1.empty())
        q1.pop();
    while (!q2.empty())
        q2.pop();
    while (!q3.empty())
        q3.pop();
    memset(visited,0,sizeof visited);
    flag = false;
}
int main(){
    int T;
    scanf("%d",&T);
    char *begin,*destination;
    begin = (char *)malloc(2);
    destination = (char *)malloc(2);
    while (T--){
        init();
        scanf("%s %s",&begin[0],&destination[0]);
        // printf("%s %s\n",begin,destination);
        int x1 = begin[0] - 'a' + 1, y1 = begin[1] - '0';
        int x2 = destination[0] - 'a' + 1, y2 = destination[1] - '0';
        bfs(x1,y1,x2,y2,0);
    }
    return 0;
}
/**
 *  # # # # # # # # 8
 *  # # # # # # # # 7
 *  # # # # # # # # 6
 *  # # # # # # # # 5
 *  # # # # $ # # # 4
 *  # # # # # # # # 3
 *  # # # # $ # # # 2
 *  # # # # # # # # 1
 *  a b c d e f g h
*/
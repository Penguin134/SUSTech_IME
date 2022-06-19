#include "cstdio"
#include "queue"
#include "cstring"
#include "cmath"
#include "vector"
using namespace std;
#define maxn 200010

typedef int Vertex;
typedef int SetName;
struct Edge{
    Vertex V1;
    Vertex V2;
    long long weight;
    Edge(int a,int b,long long c){
        V1 = a,V2 = b,weight = c;
    }
    bool operator < (const Edge &x)const{
        return weight > x.weight;
    }
};
int n;
vector<long long> a[405];
SetName S[maxn];
priority_queue<Edge> q;
#define total (3*n*n + 3*n + 1)

void Union(SetName Root1,SetName Root2){
    if (S[Root1] < S[Root2]) {
        S[Root1] += S[Root2];
        S[Root2] = Root1;
    } else {
        S[Root2] += S[Root1];
        S[Root1] = Root2;
    }
}
SetName find(Vertex V){
    if (S[V] < 0)
        return V;
    else
        return find(S[V]);
}
bool check(Vertex v,Vertex u){
    SetName r1,r2;
    r1 = find(v);
    r2 = find(u);
    if (r1 == r2)
        return false;
    else{
        Union(r1,r2);
        return true;
    }
}
inline void Insert(Vertex u,Vertex v,long long w){
    q.push(Edge(u,v,w));
}
void Kruskal(){
    long long ans=0;
    for (int i = 1; i < total;) {
        Edge tmp = q.top();
        q.pop();
        if (check(tmp.V1,tmp.V2)){
            ans += tmp.weight;
            ++i;
        }
    }
    printf("%lld\n",ans);
}
inline int f(int i){
    return 2 * n + 1 - abs(i - n - 1);
}
void build(){
    int index = 1;
    for (int i = 1; i < n + 1; ++i) {
        int bnd = f(i);
        for (int j = 0; j < bnd; ++j,++index) {
            if (j + 1 < bnd){
                Insert(index,index+1,a[i].at(j)*a[i].at(j+1));
            }
            Insert(index, index + bnd, a[i].at(j) * a[i + 1].at(j));
            Insert(index, index + bnd + 1, a[i].at(j) * a[i + 1].at(j + 1));
        }
    }
    for (int j = 0; j < f(n + 1); ++j,++index) {
        if (j + 1 < f(n+1)){
            Insert(index,index+1,a[n+1].at(j)*a[n+1].at(j+1));
        }
    }
    index = total;
    for (int i = 2*n+1; i > n + 1; --i) {
        int bnd = f(i);
        for (int j = bnd-1; j >= 0; --j,--index) {
            if (j - 1 >= 0){
                Insert(index,index-1,a[i].at(j)*a[i].at(j-1));
            }
            Insert(index,index-bnd-1,a[i].at(j)*a[i-1].at(j));
            Insert(index,index-bnd,a[i].at(j)*a[i-1].at(j+1));
        }
    }
}
void debug(){
    while (!q.empty()){
        Edge E = q.top();
        q.pop();
        printf("%d %d %lld\n",E.V1,E.V2,E.weight);
    }
}
int main(){
    scanf("%d",&n);
    memset(S, -1, sizeof S);
    int b;
    for (int i = 1; i <= 2*n + 1; ++i) {
        for (int j = 0; j < f(i); ++j) {
            scanf("%d",&b);
            a[i].push_back(b);
        }
    }
    build();
    // debug();
    Kruskal();
    return 0;
}
/**
 * 2 2
 * 2 1 2
 * 2 2
*/
#pragma GCC optimize(2)
#include<stdio.h>
#include<string.h>
#include<iostream>
#include<cmath>
#include<queue>
#include<algorithm>
using namespace std;
#define F(i,s,t) for(ll i=s;i<=t;i++)
#define ll long long
#define INF 1000000007
struct node{
    int val;
    int las,nxt;
    int isout;
}a[233333];
int n,cnm[233333],cnt,temp[233333],cmt;

inline void write(int x){
    if(x<0){
        putchar('-');
        x=-x;
    }
    if(x>9)
        write(x/10);
    putchar(x%10+'0');
}

inline int read(){
    int s=0,f=1;
    char ch=getchar();
    while(ch<'0'||ch>'9'){
        if(ch=='-')
            f=-1;
        ch=getchar();
    }
    while(ch>='0'&&ch<='9'){
        s=s*10+ch-'0';
        ch=getchar();
    }
    return s*f;
}

inline void show(){
    for(int t=a[0].nxt;t<=n;t=a[t].nxt) write(a[t].val),printf(" ");
    cout<<endl;
    return ;
}

inline void del(int i){
//  cout<<"del:"<<a[i].val<<endl;
//  show();
    a[a[i].las].nxt=a[i].nxt;
    a[a[i].nxt].las=a[i].las;
    a[i].isout=1;
//  cout<<"del:"<<a[i].val<<endl;
//  show();
    return ;
}

int main(){
//  ll qwq=-7;
//  cout<<qwq/2<<" "<<(qwq>>1)<<endl;
//      freopen("qwq.txt","r",stdin);
//      freopen("ans.txt","w",stdout);
    int T;
    cin>>T;
    while(T--){
        int qwq=1;
        scanf("%d",&n);
        memset(a,0,sizeof(a));
        a[0].nxt=1,a[0].val=-INF,a[n+1].val=INF;
        F(i,1,n) a[i].val=read(),a[i].las=i-1,a[i].nxt=i+1;
        while(qwq!=0){
            qwq=0;
            int t=a[0].nxt;
            while(a[t].val!=0&&t<=n){
                int QAQ=0;
                while(a[t].val>a[a[t].nxt].val){
                    del(t);
                    t=a[t].nxt;
                    QAQ=1,qwq=1;
                }
                if(QAQ&&t<=n){
                    cnm[++cnt]=a[t].nxt;
                    del(t);
                }
                t=a[t].nxt;
            }
            while(cnt){
                F(i,1,cnt){
                    t=cnm[i];
                    if(a[t].isout) continue;
                    int left=a[t].las;
                    while(a[left].isout&&left>0) left=a[left].las;
//                  cout<<left<<" "<<t<<endl;
                    if(a[left].val>a[t].val) temp[i]=left;
                    else temp[i]=0;
                }
                cmt=cnt,cnt=0;
                F(i,1,cmt){
                    if(temp[i]){
                        del(temp[i]);
                        del(cnm[i]);
                        cnm[++cnt]=a[cnm[i]].nxt;
                    }
                }
                F(i,1,cmt) temp[i]=0;
            }
        }
        show();
    }
    return 0;
}

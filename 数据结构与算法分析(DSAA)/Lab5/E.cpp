#include "cstdlib"
#include "string"
#include "cstring"
using namespace std;
typedef int ElementType;
typedef struct Node *PtrToNode;
struct Node {
    ElementType Data;
    PtrToNode Next;
    PtrToNode Previous;
};
typedef PtrToNode Position;

struct QNode {
    Position Front, Rear;
};
typedef struct QNode *Queue;

Queue initQueue(ElementType X){
    Queue Q;
    Q = (Queue) malloc(sizeof (struct QNode));
    Position P;
    P = (Position) malloc(sizeof (struct Node));
    P->Data = X;
    P->Next = NULL;
    P->Previous = NULL;
    Q->Front = Q->Rear = P;
    return Q;
}
bool isEmpty(Queue Q){
    if (!Q)
        return true;
    else
        return Q->Front == NULL;
}
void link(Position P1,Position P2){
    if (!P1){
        P2->Previous = P1;
        return;
    }
    if (!P2){
        P1->Next = P2;
        return;
    }
    P1->Next = P2;
    P2->Previous = P1;
}
void inQueue(Queue &Q, ElementType X){
    if (!Q){
        Q = initQueue(X);
        return;
    }
    Position TmpCell;
    TmpCell = (Position)malloc(sizeof(struct Node));
    TmpCell->Data = X;
    TmpCell->Next = NULL;
    link(Q->Rear,TmpCell);
    Q->Rear = TmpCell;
}
void frontInsert(Queue &Q, ElementType X){
    if (!Q){
        Q = initQueue(X);
        return;
    }
    Position TmpCell;
    TmpCell = (Position)malloc(sizeof(struct Node));
    TmpCell->Data = X;
    TmpCell->Previous = NULL;
    link(TmpCell,Q->Front);
    Q->Front = TmpCell;
}
ElementType deQueueF(Queue &Q){
    if (!isEmpty(Q)){
        if (Q->Front == Q->Rear){
            ElementType p = Q->Front->Data;
            Q->Front = Q->Rear = NULL;
            Q = NULL;
            return p;
        }
        Position p = Q->Front;
        Q->Front = Q->Front->Next;
        return p->Data;
    } else
        return -1;
}
ElementType deQueueR(Queue &Q){
    if (!isEmpty(Q)){
        if (Q->Front == Q->Rear){
            ElementType p = Q->Rear->Data;
            Q->Front = Q->Rear = NULL;
            Q = NULL;
            return p;
        }
        Position p = Q->Rear;
        Q->Rear = Q->Rear->Previous;
        return p->Data;
    } else
        return -1;
}
Queue reverse(Queue Q){
    Queue p=NULL;
    Position tmp=Q->Rear;
    while (tmp){
        inQueue(p,tmp->Data);
        tmp = tmp->Previous;
    }
    return p;
}
void Type1(Queue &Q,bool w,ElementType val){
    if (w)
        inQueue(Q,val);
    else
        frontInsert(Q,val);
}
void Type2(Queue &Q,bool w){
    if (w)
        printf("%d\n", deQueueR(Q));
    else
        printf("%d\n", deQueueF(Q));

}
void Type3(Queue &Q1,Queue Q2,bool w){
    if (!Q2)
        return;
    if (w)
        Q2 = reverse(Q2);
    if (!Q1){
        Q1 = initQueue(Q2->Front->Data);
        Q1->Front = Q2->Front;
        Q1->Rear = Q2->Rear;
        return;
    }
    link(Q1->Rear,Q2->Front);
    Q1->Rear = Q2->Rear;
}
Queue Q[100005];
int main(){
    int n,q,u,v,w,val,op;
    while (scanf("%d%d",&n,&q)==2){
        memset(Q,0,sizeof Q);
        for (int i = 0; i < q; ++i) {
            scanf("%d",&op);
            switch (op) {
                case 1:
                    scanf("%d%d%d",&u,&w,&val);
                    Type1(Q[u],w,val);
                    break;
                case 2:
                    scanf("%d%d",&u,&w);
                    Type2(Q[u],w);
                    break;
                case 3:
                    scanf("%d%d%d",&u,&v,&w);
                    Type3(Q[u],Q[v],w);
                    Q[v]=NULL;
                    break;
            }
        }
    }
    return 0;
}
/**
* 2 10
  2 1 1
  1 1 1 10
  2 1 0
  2 1 1
  3 1 2 0
  2 2 0
  1 1 1 19
  3 2 1 0
  9:
  10:
*/
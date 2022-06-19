#include "cstdlib"
#include "iostream"
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
int k,n,a[3000001];

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
    if (!Q->Front)
        Q->Front = TmpCell;
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
void deQueueF(Queue &Q){
    if (!isEmpty(Q)){
        if (Q->Front == Q->Rear){
            Position p = Q->Front;
            Q->Front = Q->Rear = NULL;
            free(p);
            return;
        }
        Position p = Q->Front;
        Q->Front = Q->Front->Next;
        free(p);
    } else
        return;
}
void deQueueR(Queue &Q){
    if (!isEmpty(Q)){
        if (Q->Front == Q->Rear){
            Position p = Q->Rear;
            Q->Front = Q->Rear = NULL;
            free(p);
            return;
        }
        Position p = Q->Rear;
        Q->Rear = Q->Rear->Previous;
        free(p);
    } else
        return;
}
int main(){
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin>>k>>n;
    Queue maxQue=NULL,minQue=NULL;
    int l=0,r=0;
    int ans=0;
    for (int i = 0; i < n; ++i) {
        cin>>a[i];
    }
    while (r < n){
        while (!isEmpty(maxQue) && maxQue->Rear->Data < a[r])
            deQueueR(maxQue);
        while (!isEmpty(minQue) && minQue->Rear->Data > a[r])
            deQueueR(minQue);

        inQueue(maxQue,a[r]);
        inQueue(minQue,a[r]);

        while (!isEmpty(maxQue) && !isEmpty(minQue)
                && maxQue->Front->Data - minQue->Front->Data > k){
            if (a[l] == minQue->Front->Data)
                deQueueF(minQue);
            if (a[l] == maxQue->Front->Data)
                deQueueF(maxQue);
            ++l;
        }
        ans = max(ans,r-l+1);
        ++r;
    }
    cout<<ans<<endl;
    return 0;
}
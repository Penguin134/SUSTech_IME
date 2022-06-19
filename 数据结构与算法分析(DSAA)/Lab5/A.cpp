#include "cstdlib"
#include "iostream"
#include "string"
#include "cstring"
using namespace std;
typedef char* ElementType;
typedef int Position;
typedef struct SNode *ptrToStack;
struct SNode{
    ElementType Data[10002];
    Position top;
};
typedef ptrToStack Stack;
typedef struct QNode *ptrToQueue;
struct QNode{
    ElementType Favorite;
    ptrToQueue next;
};
ptrToQueue fst,lst;
int numQ=0;
typedef ptrToQueue Queue;

Stack initStack(){
    Stack S;
    S = (Stack)malloc(sizeof(struct SNode));
    S->top = -1;
    return S;
}
bool isEmpty(Stack S){
    return S->top == -1;
}
bool Push(Stack S,ElementType X){
    ++S->top;
    S->Data[S->top] = (ElementType)malloc(sizeof (ElementType)*10);
    strcpy(S->Data[S->top],X);
    return true;
}
bool Pop(Stack S){
    if( isEmpty(S) ) {
        return false;
    }
    else {
        S->Data[S->top] = NULL;
        --S->top;
        return true;
    }
}
int leftNum(Stack S){
    return S->top+1;
}
ElementType Top(Stack S){
    if( isEmpty(S) ) {
        //printf("Stack is empty\n");
        return NULL;
    }
    else {
        char * ch;
        ch = S->Data[S->top];
        return ch;
    }
}
Queue initQueue(ElementType X){
    Queue Q;
    Q = (Queue) malloc(sizeof (struct QNode));
    Q->next = NULL;
    Q->Favorite = (char*)malloc(sizeof(char*)*10);
    strcpy(Q->Favorite,X);
    fst = lst = Q;
    ++numQ;
    return Q;
}
bool isEmpty(Queue Q){
    return fst == NULL;
}
void inQueue(Queue &Q, ElementType X){
    if (!Q){
        Q = initQueue(X);
        return;
    }
    Queue TmpCell;
    TmpCell = (Queue)malloc(sizeof(struct QNode));
    TmpCell->Favorite = (char*)malloc(sizeof(char*)*10);
    strcpy(TmpCell->Favorite,X);
    TmpCell->next = NULL;
    lst->next = TmpCell;
    lst = TmpCell;
    ++numQ;
}
bool deQueue(Queue &Q){
    if (!isEmpty(Q)){
        Q = Q->next;
        fst = fst->next;
        --numQ;
        return true;
    } else
        return false;
}
ElementType Fst(Queue Q){
    if (isEmpty(Q))
        return NULL;
    else
        return fst->Favorite;
}
int leftNum(Queue Q){
    return numQ;
}
void takeFood(Stack S,Queue &Q){
    if (isEmpty(S) || isEmpty(Q))
        return;
    if (strcmp(Top(S), Fst(Q)) == 0){
        Pop(S);
        deQueue(Q);
    } else{
        inQueue(Q,fst->Favorite);
        deQueue(Q);
    }
}
int main(){
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int T;
    cin>>T;
    char op[10],ch[233];
    Stack S = initStack();
    Queue Q = NULL;
    while (T--){
        memset(op,0,sizeof op);
        memset(ch,0,sizeof ch);
        cin>>op;
        switch (op[3]) {
            case 'C':
                cin>>ch;
                inQueue(Q,ch);
                break;
            case 'F':
                cin>>ch;
                Push(S,ch);
                break;
            case 'e':
                takeFood(S,Q);
                break;
        }
    }
    for (int i = 1; i <= leftNum(Q); ++i) {
        if (strcmp(Top(S), Fst(Q)) == 0){
            Pop(S);
            deQueue(Q);
            i=0;
        } else{
            inQueue(Q,fst->Favorite);
            deQueue(Q);
        }
    }
    if (!leftNum(Q))
        cout<<"Qi Fei!"<<endl;
    else
        cout<<leftNum(Q)<<endl;
    return 0;
}

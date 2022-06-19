#include "cstdlib"
#include "iostream"
#include "string"
using namespace std;
typedef long long ElementType;
typedef int Position;
typedef struct SNode *ptrToStack;
struct SNode{
    ElementType Data[100002];
    Position top;
};
typedef ptrToStack Stack;
long long ans=0;

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
    S->Data[S->top] = X;
    return true;
}
bool Pop(Stack S){
    if( isEmpty(S) ) {
        return false;
    }
    else {
        long long temp = S->Data[S->top];
        S->Data[S->top] = NULL;
        temp = (temp ? temp * 2 : 1 + temp)%514329;
        --S->top;
        if (!isEmpty(S)){
            S->Data[S->top] += temp;
        } else{
            ans += temp;
        }
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
        return S->Data[S->top];
    }
}
int main(){
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    string s;
    cin>>s;
    Stack S = initStack();
    for (int i = 0; i < s.length(); ++i) {
        if (s[i] == '('){
            Push(S,0);
        } else {
            Pop(S);
        }
    }
    cout<<(ans % 514329)<<endl;
}
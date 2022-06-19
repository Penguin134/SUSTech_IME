#include "iostream"
#include "string"
using namespace std;
typedef char ElementType;
typedef int Position;
typedef ElementType Stack;

Position top;
Stack S[30003];

void initStack(){
    top = -1;
}
bool isEmpty(){
    return top == -1;
}
bool Push(ElementType X){
    S[++top] = X;
    return true;
}
bool Pop(){
    if( isEmpty() ) {
        return false;
    }
    else {
        --top;
        return true;
    }
}
ElementType Top(){
    if( isEmpty() ) {
        return NULL;
    }
    else {
        return S[top];
    }
}

int main(){
    int T,n;
    cin>>T;
    while (T--){
        cin>>n;
        string s;
        bool flag= true;
        initStack();
        cin>>s;
        for (int i = 0; i < n; ++i) {
            if (s[i] == '(' || s[i] == '[' || s[i] == '{'){
                switch (s[i]) {
                    case '(':
                        Push(')');
                        break;
                    case '[':
                        Push(']');
                        break;
                    case '{':
                        Push('}');
                        break;
                }
            }
            else{
                if (Top() != s[i]){
                    flag = false;
                    break;
                } else{
                    Pop();
                }
            }
        }
        if (!isEmpty())
            flag = false;
        if (flag)
            cout<<("YES\n");
        else
            cout<<("NO\n");
    }
    return 0;
}
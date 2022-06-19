#include "cstdlib"
#include "cstdio"
using namespace std;

typedef struct List *ptrToNode;
typedef ptrToNode Item;
struct List{
    int value;
    int exp;
    Item next;
};
Item Insert(Item item, int value, int exp, Item& tail){
    Item tmp;
    if (!item){
        item = (Item)malloc(sizeof (struct List));
        item->value = value;
        item->exp = exp;
        item->next = NULL;
        tail = item;
        return item;
    }
    tmp = (Item)malloc(sizeof (struct List));
    tmp->value = value;
    tmp->exp = exp;
    tmp->next = NULL;
    tail->next = tmp;
    tail = tail->next;
    return item;
}
Item Insert(Item item,int n){
    Item tmp,pre;
    if (n){
        item = (Item)malloc(sizeof (struct List));
        scanf("%d%d",&item->value,&item->exp);
        item->next = NULL;
    }
    pre = item;
    for (int i = 1; i < n; ++i) {
        tmp = (Item)malloc(sizeof (struct List));
        scanf("%d%d",&tmp->value,&tmp->exp);
        tmp->next = NULL;
        pre->next = tmp;
        pre = pre->next;
    }
    return item;
}
/*Item Delete(Item item,int X){
    if(item){
        if (X < item->exp)
            item->next = Delete(item->next,X);
        else if (X == item->exp){
            item = item->next;
        }
    }
    return item;
}*/
Item A,B,C;
int main(){
    int n,m,k=0;
    scanf("%d%d",&n,&m);
    A = Insert(A,n);
    B = Insert(B,m);
    Item tail = NULL;
    while (A && B){
        if (A->exp > B->exp){
            C = Insert(C,A->value,A->exp,tail);
            A = A->next;
            ++k;
        } else if(A->exp < B->exp){
            C = Insert(C,B->value,B->exp,tail);
            B = B->next;
            ++k;
        } else {
            int c = A->value + B->value;
            if (c){
                C = Insert(C,c,A->exp,tail);
                ++k;
            }
            A = A->next;
            B = B->next;
        }
    }
    while (A){
        C = Insert(C,A->value,A->exp,tail);
        A = A->next;
        ++k;
    }
    while (B){
        C = Insert(C,B->value,B->exp,tail);
        B = B->next;
        ++k;
    }
    printf("%d\n",k);
    while (C){
        printf("%d %d\n",C->value,C->exp);
        C = C->next;
    }
    return 0;
}

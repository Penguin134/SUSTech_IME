#include "cstdio"
#include "algorithm"
using namespace std;

typedef struct TNode *Position;
typedef Position BinTree;
struct TNode{
    int Data;
    BinTree Left;
    BinTree Right;
    int Height;
};
BinTree BT1=NULL,BT2=NULL;
long long ans=0;

int h(BinTree BT){
    return BT ? BT->Height : 0;
}
BinTree RR(BinTree BT){
    BinTree temp = BT->Right;
    BT->Right = temp->Left;
    temp->Left = BT;
    BT->Height = max(h(BT->Left), h(BT->Right)) + 1;
    temp->Height = max(h(temp->Left), h(temp->Right)) + 1;
    return temp;
}
BinTree LR(BinTree BT){
    BinTree temp = BT->Left;
    BT->Left = temp->Right;
    temp->Right = BT;
    BT->Height = max(h(BT->Left), h(BT->Right)) + 1;
    temp->Height = max(h(temp->Left), h(temp->Right)) + 1;
    return temp;
}
BinTree LRR(BinTree BT){
    BT->Left = RR(BT->Left);
    return LR(BT);
}
BinTree RLR(BinTree BT){
    BT->Right = LR(BT->Right);
    return RR(BT);
}
BinTree Insert(BinTree BT,int val){
    if (!BT){
        BT = (BinTree) malloc(sizeof(struct TNode));
        BT->Data = val;
        BT->Left = BT->Right = NULL;
        BT->Height = 1;
        return BT;
    }
    if (val < BT->Data){
        BT->Left = Insert(BT->Left, val);
        if (h(BT->Left) - h(BT->Right) == 2){
            BT = val < BT->Left->Data ? LR(BT) : LRR(BT);
        }
    } else {
        BT->Right = Insert(BT->Right,val);
        if (h(BT->Left) - h(BT->Right) == -2){
            BT = val > BT->Right->Data ? RR(BT) : RLR(BT);
        }
    }
    BT->Height = max(h(BT->Left), h(BT->Right)) + 1;
    return BT;
}
int findMin(BinTree BT){
    while (BT->Left)
        BT = BT->Left;
    return BT->Data;
}
int findMax(BinTree BT){
    while (BT->Right)
        BT = BT->Right;
    return BT->Data;
}
BinTree Delete(BinTree BT,int val){
    if (BT == NULL)
        return NULL;
    if (val < BT->Data){
        BT->Left = Delete(BT->Left,val);
        if (h(BT->Left) - h(BT->Right) == -2){
            BT = h(BT->Right->Left)>h(BT->Right->Right) ? RLR(BT) : RR(BT);
        }

    } else if (val > BT->Data){
        BT->Right = Delete(BT->Right,val);
        if (h(BT->Left) - h(BT->Right) == 2){
            BT = h(BT->Left->Right)>h(BT->Left->Left) ? LRR(BT) : LR(BT);
        }

    } else {
        if (BT->Left && BT->Right){
            if (h(BT->Left) > h(BT->Right)){
                BT->Data = findMax(BT->Left);
                BT->Left = Delete(BT->Left,BT->Data);
            } else {
                BT->Data = findMin(BT->Right);
                BT->Right = Delete(BT->Right,BT->Data);
            }
        } else {
            BinTree temp = BT;
            BT = BT->Left ? BT->Left : BT->Right;
            free(temp);
        }
    }

    return BT;
}
bool cmp(int a,int b,int c){
    if (abs(a-c) == abs(b-c))
        return a<b;
    else
        return abs(a-c) < abs(b-c);
}
int findClosed(BinTree BT, int val){
    int mis=0,mas=0;
    BinTree tmp = BT;
    while (tmp){
        if (tmp->Data == val)
            return val;
        if (tmp->Data < val){
            mis = tmp->Data;
            tmp = tmp->Right;
        } else {
            mas = tmp->Data;
            tmp = tmp->Left;
        }
    }
    if (!mis || cmp(mas,mis,val)){
        return mas;
    } else {
        return mis;
    }
}
void debug(){
    for (int i = 1; i <= 100; ++i) {
        BT1 = Insert(BT1,10*i);
    }
    printf("%d\n", findClosed(BT1,52));
    printf("%d\n", findClosed(BT1,155));
    printf("%d\n", findClosed(BT1,257));
    printf("%d\n", findClosed(BT1,359));
    printf("%d\n", findClosed(BT1,451));
    printf("%d\n", findClosed(BT1,550));
}
int main(){
    // debug();
    int M,op,C;
    scanf("%d",&M);
    while (M--){
        scanf("%d%d",&op,&C);
        if (op){
            if (!BT2)
                BT1 = Insert(BT1,C);
            else{
                int t = findClosed(BT2,C);
                // printf("t=%d\n",t);
                ans += abs(t - C);
                BT2 = Delete(BT2,t);
            }
        } else {
            if (!BT1)
                BT2 = Insert(BT2,C);
            else {
                int t = findClosed(BT1,C);
                // printf("t=%d\n",t);
                ans += abs(t - C);
                BT1 = Delete(BT1,t);
            }
        }
    }
    printf("%lld",ans);
    return 0;
}
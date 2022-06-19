#include "cstdio"
#include "map"
#include "string"
using namespace std;

string s;
int size = 0,k;
struct node{
    string s;
    node* next;
    node* pre;
    node():s(""),next(nullptr),pre(nullptr){}
};
node* head,*tail;
map<string,node*> m;

void Read(){
    char tmp;
    s = "";
    while (s.size() < 256){
        tmp = getchar();
        if (tmp == '\n' || tmp == ' ')
            continue;
        s += tmp;
    }
}
void addHead(node* x){
    x->pre = head;
    x->next = head->next;
    x->next->pre = x;
    head->next = x;
}
node* rm(node *x){
    x->pre->next = x->next;
    x->next->pre = x->pre;
    return x;
}

int main(){
    int n;
    scanf("%d%d",&n,&k);
    head = new node();
    tail = new node();
    head->next = tail;
    tail ->pre = head;
    while (n--){
        //Read();
        int c;
        s = "";
        for (int i = 0; i < 256; ++i) {
            scanf("%d",&c);
            s += to_string(c);
        }
        if (m.count(s)){
            printf("hit\n");
            node * temp = m[s];
            rm(temp);
            addHead(temp);
        } else {
            printf("miss\n");
            node * temp = new node();
            temp->s = s;
            m[s] = temp;
            addHead(temp);
            ++size;
            if (size > k){
                node * rmn = rm(tail->pre);
                m.erase(rmn->s);
                free(rmn);
                --size;
            }
        }
    }
    return 0;
}
/**
 *  10 2
 *  1 1 1 2 1 1 2 3 1 2
 */
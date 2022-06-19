#include "cstdio"
#include "cstdlib"
using namespace std;
typedef struct Item *ptrToNode;
typedef ptrToNode Line;
struct Item{
    int id;
    Line next;
    //Line preview;
};
Line init(int len){
    Line line = (Line) malloc(sizeof (struct Item)),tmp,pre;
    line->id = 1;
    line->next = NULL; //line->preview = NULL;
    pre = line;
    for (int i = 2; i <= len; ++i) {
        tmp = (Line) malloc(sizeof (struct Item));
        tmp->id = i;
        tmp->next = NULL;
        pre->next = tmp;
        //tmp->preview = pre;
        pre = pre->next;
    }
    return line;
}
Line Delete(Line line,int step,int len){
    printf("%d ",line->id);
    Line tmp = line;
    for (int index = 1; index <= len; index+=step) {
        for(int j = 1;j < step;++j){
            tmp = tmp->next;
            if (!tmp)
                return line->next;
        }
        if (!tmp->next)
            break;
        printf("%d ",tmp->next->id);
        tmp->next = tmp->next->next;
        //tmp->preview->next = tmp->next;

        //tmp->next->preview = tmp->preview;
    }
    return line->next;
}
int main(){
    int len,m;
    Line line;
    scanf("%d%d",&len,&m);
    line = init(len);
    while (line){
        line = Delete(line,m,len);
    }
    return 0;
}
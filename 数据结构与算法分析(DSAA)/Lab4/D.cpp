#include "cstdio"
#include "cstdlib"
using namespace std;
struct Item{
    int value;
    int address;
    int ans;
} H[2000020];
int n;
void init(int n1){
    for (int i = 0; i < n1; ++i) {
        scanf("%d", &H[i].value);
        H[i].address = i;
    }
}
bool operator < (Item &a,Item &b){
    return a.value < b.value;
}
void MergeSort(Item *arr,Item *temp , int left, int right, int R_end){
    int L_end = right - 1, index = left, num = R_end - left + 1;

    while (left <= L_end && right <= R_end){
        if (arr[left] < arr[right])
            temp[index++] = arr[left++];
        else
            temp[index++] = arr[right++];
    }

    while (left <= L_end)
        temp[index++] = arr[left++];
    while (right <= R_end)
        temp[index++] = arr[right++];

    for(int i = 0; i < num; i++, R_end -- )
        arr[R_end] = temp[R_end];
}
void ToMerge(Item *arr, Item *temp, int left, int right){
    int middle;
    if (left < right){
        middle = (left + right) / 2;
        ToMerge(arr,temp,left,middle);
        ToMerge(arr,temp,middle + 1,right);
        MergeSort(arr,temp,left,middle + 1,right);
    }
}
void TLE(Item *arr, int len){
    Item temp[len];
    ToMerge(arr,temp,0,len - 1);
}
void judge(int index){
    int left=index-1,right=index+1;
    while(left >= 0 && H[left].address < H[index].address){
        --left;
    }
    while(right <= n-1 && H[right].address < H[index].address){
        ++right;
    }
    if (left < 0){
        H[index].ans = H[right].value - H[index].value;
        //printf("%d",H[right].value - H[index].value);
    } else if(right > n-1){
        H[index].ans = H[index].value - H[left].value;
        //printf("%d",H[index].value - H[left].value);
    } else {
        int a = H[right].value - H[index].value;
        int b = H[index].value - H[left].value;
        H[index].ans = a < b ? a : b;
        //printf("%d ",a < b ? a : b);
    }
}
int main(){
    scanf("%d",&n);
    init(n);
    TLE(H,n);
    for (int i = 0; i < n; ++i){
        if (H[i].address != n-1)
            judge(i);
    }
    for (int i = 0; i < n; ++i){
        H[i].value = H[i].address;
    }
    TLE(H,n);
    for (int i = 0; i < n-1; ++i){
        printf("%d ",H[i].ans);
    }
    return 0;
}
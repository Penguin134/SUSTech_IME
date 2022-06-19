#include "iostream"
using namespace std;
int a[100010];
long long ans=0;

void MergeSort(int *arr,int *temp , int left, int right, int R_end){
    int L_end = right - 1, index = left, num = R_end - left + 1;

    while (left <= L_end && right <= R_end){
        if (arr[left] <= arr[right])
            temp[index++] = arr[left++];
        else{
            ans += arr[right]*(L_end - left + 1l);
            temp[index++] = arr[right++];
        }
    }

    while (left <= L_end)
        temp[index++] = arr[left++];
    while (right <= R_end)
        temp[index++] = arr[right++];

    for(int i = 0; i < num; i++, R_end--)
        arr[R_end] = temp[R_end];
}
void ToMerge(int *arr, int *temp, int left, int right){
    int middle;
    if (left < right){
        middle = (left + right) / 2;
        ToMerge(arr,temp,left,middle);
        ToMerge(arr,temp,middle + 1,right);
        MergeSort(arr,temp,left,middle + 1,right);
    }
}
void LBWNB(int *arr, int len){
    int temp[len];
    ToMerge(arr,temp,0,len - 1);
}

int main(){
    int n;
    cin>>n;
    for (int i = 0; i < n; ++i) {
        cin>>a[i];
    }
    LBWNB(a,n);
    cout<<ans<<endl;
    return 0;
}

/*
5
1 3 4 5 1

3
 */
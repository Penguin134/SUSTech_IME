//
// Created by Penguin on 2021/9/22.
//
#include "iostream"
#include "cstring"
using namespace std;
int Insert_num, Select_num;
int a[1010],b[1010];

void InsertSort(int *arr, int len){
    int i,temp;
    for (int p = 1; p < len; ++p) {
        temp = p;
        for (i = p; i > 0; --i) {
            ++Insert_num;
            if (arr[i - 1] <= arr[temp]){
                break;
            } else {
                swap(arr[temp],arr[i - 1]);
                temp = i - 1;
                ++Insert_num;
            }
        }
    }
}
void SelectionSort(int *arr, int len){
    int temp,p;
    for (p = 0; p < len; ++p){
        temp = p;
        for (int i = p + 1; i < len; ++i) {
            temp = (arr[temp] < arr[i]) ? temp : i;
            ++Select_num;
        }
        swap(arr[temp],arr[p]);
        ++Select_num;
    }
    --Select_num;
}
void print(int n){
    for (int i = 0; i < n; ++i) {
        cout<<a[i]<<" ";
    }
    cout<<endl;
    //cout<<Insert_num<<" "<<Select_num<<endl;
    if (Insert_num < Select_num)
        cout<<"Insertion Sort wins!"<<endl;
    else
        cout<<"Selection Sort wins!"<<endl;
}

int main(){
    int T,n,buf;
    cin>>T;
    while (T--){
        cin>>n;
        memset(a,0,sizeof (a));
        memset(b,0,sizeof (b));
        Insert_num = Select_num = 0;
        for (int i = 0; i < n; ++i) {
            cin>>buf;
            a[i] = b[i] = buf;
        }
        InsertSort(a,n);
        SelectionSort(b,n);
        print(n);
    }
    return 0;
}
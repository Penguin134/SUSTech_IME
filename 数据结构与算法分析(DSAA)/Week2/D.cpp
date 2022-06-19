//
// Created by Penguin on 2021/9/14.
//

#include "iostream"
using namespace std;
int a[50005],N,ans=0;

int BinSearchL(long long num,int left,int right){
    if (num <= 0)
        return -1;
    int middle = (left + right) / 2;
    while (left <= right){
        if (a[middle] > num)
            right = middle - 1;
        else if (a[middle] < num)
            left = middle + 1;
        else if (left == right)
            return middle;
        else
            right = middle;
        middle = (left + right) / 2;
    }
    return -1;
}
int BinSearchR(long long num,int left,int right){
    if (num <= 0)
        return -1;
    int middle = (left + right + 1) / 2;
    while (left <= right){
        if (a[middle] > num)
            right = middle - 1;
        else if (a[middle] < num)
            left = middle + 1;
        else if (left == right)
            return middle;
        else
            left = middle;
        middle = (left + right + 1) / 2;
    }
    return -1;
}
void calculate(int start){
    for (long long i = 1; i <= 31; ++i) {
        int leftIndex,rightIndex;
        leftIndex = BinSearchL((1<<i) - a[start],start+1,N-1);
        if (leftIndex != -1){
            //cout<<leftIndex<<" ";
            rightIndex = BinSearchR((1<<i) - a[start],start+1,N-1);
            //cout<<rightIndex<<endl;
            ans += rightIndex - leftIndex + 1;
        }
    }
}
int main(){
    cin>>N;
    for (int i = 0; i < N; ++i) {
        cin>>a[i];
    }
    for (int i = 0; i < N - 1; ++i) {
        calculate(i);
    }
    cout<<ans<<endl;
    return 0;
}

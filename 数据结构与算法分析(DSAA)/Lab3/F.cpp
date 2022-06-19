#include "iostream"
#include "cstdio"
using namespace std;

long long sum=0;
struct Attributes{
    long long height;
    long long strength;
    long long up_limit;
} Plants[200020];

bool operator < (Attributes &a,Attributes &b){
    return a.up_limit < b.up_limit;
}

void MergeSort(Attributes *arr,Attributes *temp , int left, int right, int R_end){
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
void ToMerge(Attributes *arr, Attributes *temp, int left, int right){
    int middle;
    if (left < right){
        middle = (left + right) / 2;
        ToMerge(arr,temp,left,middle);
        ToMerge(arr,temp,middle + 1,right);
        MergeSort(arr,temp,left,middle + 1,right);
    }
}
void LetsRock(Attributes *arr, int len){
    Attributes temp[len];
    ToMerge(arr,temp,0,len - 1);
}

int main(){
    int n,p,q;
    cin>>n>>p>>q;
    for (int i = 0; i < n; ++i){
        scanf("%lld%lld",&Plants[i].height,&Plants[i].strength);
        // Plants[i].up_limit = (Plants[i].height<<p) - Plants[i].strength;
        Plants[i].up_limit = Plants[i].height - Plants[i].strength;
    }
    LetsRock(Plants,n);

    if (q>n) q=n;
    long long temp1 = q ? Plants[n-q].up_limit : 0;
    long long temp2 = q>1 ? Plants[n-q+1].up_limit : temp1;
    if (temp1 < 0) temp1=0;
    if (temp2 < 0) temp2=0;
    for (int i = 1; i <= n; ++i) {
        if (i <= q)
            Plants[n-i].up_limit=(Plants[n-i].height<<p)
                    -max(Plants[n-i].height,Plants[n-i].strength);
        else
            Plants[n-i].up_limit=(Plants[n-i].height<<p)
                    -Plants[n-i].strength-temp2;
    }
    LetsRock(Plants,n);
    Plants[n-1].height = Plants[n-1].height<<p;

    for (int i = 0; i < n; ++i) {
        Plants[i].up_limit = Plants[i].height-Plants[i].strength;
    }
    LetsRock(Plants,n);

    int j = n-1;
    while (j>=0 && Plants[j].height - Plants[j].strength > 0 && q>0){
        sum += Plants[j].height;
        --q;--j;
    }
    while (j>=0){
        sum += Plants[j--].strength;
    }
    printf("%lld\n",sum);
    return 0;
}
/*
4 1 3
8 1
10 5
11 7
20 26

66

20 2 8
26501 6335
15725 19170
29359 11479
24465 26963
28146 5706
16828 23282
492 9962
11943 2996
5437 4828
14605 32392
154 3903
12383 293
18717 17422
19896 19719
21727 5448
11539 14772
19913 1870
26300 25668
9895 17036
23812 28704
 */
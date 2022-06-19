#include "iostream"
#include "algorithm"
using namespace std;
// value, row, column
struct matrix{
    long long value;
    int column;
}a[50005];
int n;

// row, column
long long f(long long i,long long j){
    return i*i + 12345*i + j*j - 12345*j + i*j;
}

bool sp_cmp(matrix b,matrix c){
    return b.value < c.value;
}

void init(){
    for (int i = 1; i <= n; ++i) {
        a[i].value = f(1,i);
        a[i].column = i;
    }
    sort(a+1,a+1+n, sp_cmp);
}

bool check(long long middle, long long m){
    int row = n,column = 1;
    int count = 0;
    while (row >= 1 && column <= n){
        if (f(row,a[column].column) <= middle){
            count += row;
            ++column;
        } else{
            --row;
        }
    }
    return count >= m;
}

long long calculate(long long m){
    long long left = f(1,a[1].column),right = f(n,a[n].column);
    while (left < right){
        long long middle = (left + right) / 2;
        middle = middle < 0 ? (middle-1) : middle;
        if (check(middle,m))
            right = middle;
        else
            left = middle + 1;
    }
    return left;
}

int main(){
    int t;
    long long m;
    cin>>t;
    while (t--){
        cin>>n>>m;
        init();
        cout<<calculate(m)<<endl;
    }

    return 0;
}
/*
    5
    50000 250000
    100 1000
    200 10000
    200 2000
    200 1
    -37956629
    -785789
    -2284949
    -2225094
    -2416454
 */
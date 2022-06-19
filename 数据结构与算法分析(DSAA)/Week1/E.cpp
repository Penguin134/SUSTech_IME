#include "iostream"
#include "cmath"
#include "cstring"
using namespace std;

int up_down[]={0,1,8};
int mirror[]={0,1,6,8,9};
long long L, R;
int combine[8];

int getDigest(long long num){
    int di=0;
    while (num){
        num/=10;++di;
    }
    return di;
}
int getCombine(){
    int ans=0;
    for (int i = 7; i >= 1 ; --i) {
        ans += (int)pow(10,i) * mirror[combine[i]];
    }
    // cout<<"Combine: "<<ans<<endl;
    return ans;
}
void check(){
    for (int i = 1; i <= 6; ++i) {
        if (combine[i] >= 5){
            combine[i+1]++;
            combine[i]%=5;
        } else if (combine[i] < 0){
            combine[i+1]--;
            combine[i]+=5;
        }
    }
    //if (combine[7] < 0)
    //    memset(combine,0,sizeof (combine));
}
long long tran(long long num, bool isOdd){
    int temp=getDigest(num);
    string str="",snum = to_string(num);
    if (isOdd){
        for (int i = 0; i < temp - 1; ++i) {
            switch (snum[temp - 2 -i]) {
                case '6': str += "9";break;
                case '9': str += "6";break;
                default: str += snum[temp - 2 -i];break;
            }
        }
    }else{
        for (int i = 0; i < temp; ++i) {
            switch (snum[temp - 1 - i]) {
                case '6': str += "9";break;
                case '9': str += "6";break;
                default: str += snum[temp - 1 - i];break;
            }
        }
    }
    return stol(snum + str);
    cout<<snum<<str<<" ";
}
void even1(int di){
    long long L0 = L / (long long) pow(10,(int)di/2);
    memset(combine,0,sizeof (combine));
    while (getCombine() + mirror[combine[0]] <= L0){
        combine[0] ++;
        if (combine[0] >= 5){
            combine[1]++;
            combine[0]%=5;
        }
        check();
    }
    long long n = getCombine() + mirror[combine[0]];
    if (getDigest(n) - di/2 >= 1){
        cout<<1;
        for (int i = 1; i <= di; ++i) {
            cout<<(i == di ? 1 : 0);
        }
        cout<<" ";
    }else {
        long long X = tran(n, false);
        combine[0]--;
        if (combine[0] < 0){
            combine[1]--;
            combine[0]+=5;
        }
        check();
        n = getCombine() + mirror[combine[0]];
        long long Y = tran(n, false);
        if (Y>L)
            cout<<Y<<" ";
        else
            cout<<X<<" ";
    }
}
void even2(int di){
    long long R0 = R / (long long) pow(10,(int)di/2);
    for (int i = 0; i < 8; ++i)
        combine[i] = 4;

    while (getCombine() + mirror[combine[0]] >= R0){
        combine[0] --;
        if (combine[0] < 0){
            combine[1]--;
            combine[0]+=5;
        }
        check();
    }
    long long n = getCombine() + mirror[combine[0]];
    if (getDigest(n) - di/2 <= -1){
        for (int i = 0; i < getDigest(n); ++i)
            cout<<9;
        cout<<8;
        for (int i = 0; i < getDigest(n); ++i)
            cout<<6;
        cout<<" ";
    }else {
        long long X = tran(n, false);
        combine[0]++;
        if (combine[0] >= 5){
            combine[1]++;
            combine[0]%=5;
        }
        check();
        n = getCombine() + mirror[combine[0]];
        long long Y = tran(n, false);
        if (Y<R)
            cout<<Y<<" ";
        else
            cout<<X<<" ";
    }
}
void odd1(int di){
    long long L0 = L / (long long) pow(10,(int)di/2);
    memset(combine,0,sizeof (combine));
    while (getCombine() + up_down[combine[0]] <= L0){
        combine[0] ++;
        if (combine[0] >= 3){
            combine[1]++;
            combine[0]%=3;
        }
        check();
    }
    long long n = getCombine() + up_down[combine[0]];
    if (getDigest(n) - di/2 >= 2){
        cout<<1;
        for (int i = 1; i <= di; ++i)
            cout<<( i == di ? 1 : 0);
        cout<<" ";
    }else {
        long long X = tran(n, true);
            combine[0]--;
            if (combine[0] < 0){
                combine[1]--;
                combine[0]+=3;
            }
            check();
            n = getCombine() + up_down[combine[0]];
            long long Y = tran(n, true);
        if (Y>L)
            cout<<Y<<" ";
        else
            cout<<X<<" ";
    }
}
void odd2(int di){
    long long R0 = R / (long long) pow(10,(int)di/2);
    for (int i = 0; i < 8; ++i)
        combine[i] = 4;
    combine[0] = 2;
    while (getCombine() + up_down[combine[0]] >= R0){
        combine[0] --;
        if (combine[0] < 0){
            combine[1]--;
            combine[0]+=3;
        }
        check();
    }
    long long n = getCombine() + up_down[combine[0]];
    if (getDigest(n) - di/2 <= 0){
        for (int i = 0; i < (di-1)/2; ++i)
            cout<<9;
        for (int i = 0; i < (di-1)/2; ++i)
            cout<<6;
        cout<<" ";
    }else{
        long long X = tran(n, true);
            combine[0]++;
            if (combine[0] >= 3){
                combine[1]++;
                combine[0]%=3;
            }
            check();
            n = getCombine() + up_down[combine[0]];
            long long Y = tran(n, true);
        if (Y<R)
            cout<<Y<<" ";
        else
            cout<<X<<" ";
    }
}

int main(){
    while(cin>>L>>R) {
        int dL = getDigest(L), dR = getDigest(R);
        if (dL % 2)
            odd1(dL);
        else
            even1(dL);
        if (dR % 2)
            odd2(dR);
        else
            even2(dR);
    }
    return 0;
}
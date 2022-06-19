#include "string"
#include "cstdio"
#include "algorithm"
#include "iostream"
using namespace std;
int len[300000];
string s0;

inline string init(string s){
    string out = "@#";
    for (char i : s) {
        out += i;
        out += "#";
    }
    out += "$";
    return out;
}
inline int Min(int a,int b){
    return a < b ? a : b;
}
inline int Max(int a,int b){
    return a > b ? a : b;
}
int main(){
    //freopen("data.in","r",stdin);
    //freopen("ans.out","w",stdout);
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin>>s0;
    s0 = init(s0);
    int n = s0.size() - 1;
    int  ans = 0, r = 0, ctr = 0;
    for (int i = 1; i < n; ++i) {
        len[i] = (i <= r) ? Min(r - i + 1, len[2 * ctr - i]) : 1;
        while (s0[i + len[i]] == s0[i - len[i]])
            ++len[i];
        if (i + len[i] - 1 > r) {
            ctr = i;
            r = i + len[i] - 1;
        }
        ans = Max(ans,len[i]);
    }
    cout<<ans-1;
    //fclose(stdin);
    //fclose(stdout);
    return 0;
}
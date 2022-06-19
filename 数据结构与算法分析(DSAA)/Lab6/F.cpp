#include "cstring"
#include "cstdio"
#include "string"
#include "iostream"
#define NotFound -1
using namespace std;
typedef int Position;

string s0,s1,s2;
char cipher[26];

void BuildMatch( string pattern, int match[] )
{
    Position i, j;
    int m = pattern.length();
    for ( j=1; j<m; j++ ) {
        i = match[j-1];
        if ( i >= 0 && pattern[i+1] != pattern[j] )
            i = match[i];
        if ( pattern[i+1] == pattern[j] )
            match[j] = i+1;
    }
}
Position KMP(string stri, string pattern)
{
    int n = stri.length();
    int m = pattern.length();
    Position s, p, match[m];

    //if ( n < m ) return NotFound;
    memset(match,-1,sizeof match);
    BuildMatch(pattern, match);
    s = p = 0;
    while ( s<n && p<m ) {
        if (stri[s] == pattern[p] ) {
            s++; p++;
        }
        else if (p>0) p = match[p-1]+1;
        else s++;
    }
    return p;
}
int main(){
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    for (int i = 0; i < 26; ++i) {
        cin>>cipher[i];
    }
    cin>>s0;
    for (int i = s0.size()-1; i >= 0; --i) {
        s1 += s0[i];
    }
    s2 = s1.substr(0,s1.size()/2);
    for (int i = 0; i < s2.size(); ++i) {
        s2[i] = cipher[s2[i] - 'a'];
    }
    int ans = KMP(s1.substr(s0.size()/2),s2);
    ans = s0.size() - ans;
    cout<<ans;
    return 0;
}
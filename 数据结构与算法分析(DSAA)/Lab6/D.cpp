#include "string"
#include "cstdio"
#include "cstdlib"
using namespace std;
typedef int Position;
#define NotFound -1

string Read() {
    string str;
    char s = getchar();
    while (s == ' ' || s == '\n' || s == '\r'){
        s = getchar();
    }
    while (s != ' ' && s != '\n' && s != '\r'){
        str += s;
        s = getchar();
    }
    return str;
}
void BuildMatch(string pattern, int *match)
{
    Position i, j;
    int m = pattern.length();
    match[0] = -1;

    for ( j=1; j<m; j++ ) {
        i = match[j-1];
        while ( (i>=0) && (pattern[i+1]!=pattern[j]) )
            i = match[i];
        if ( pattern[i+1]==pattern[j] )
            match[j] = i+1;
        else match[j] = -1;
    }
}
Position KMP(string stri, string pattern)
{
    int n = stri.length();
    int m = pattern.length();
    Position s, p, *match;

    if ( n < m ) return NotFound;
    match = (Position *)malloc(sizeof(Position) * m);
    BuildMatch(pattern, match);
    s = p = 0;
    while ( s<n && p<m ) {
        if (stri[s] == pattern[p] ) {
            s++; p++;
        }
        else if (p>0) p = match[p-1]+1;
        else s++;
    }
    return ( p==m )? (s-m) : NotFound;
}
int main(){
    string s1,s2;
    s1 = Read();
    s2 = Read();
    if (s1.length() != s2.length()){
        printf("No");
        return 0;
    }
    s1 += s1;
    if (KMP(s1,s2) == NotFound){
        printf("No");
    }else{
        printf("Yes");
    }
    return 0;
}
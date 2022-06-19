#include "cstring"
#include "cstdio"
#include "string"
using namespace std;

typedef int Position;
int Next[1000010];
string s0;

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
string Read()
{
    string str;
    char s = getchar();
    while (s == ' ' || s == '\n' || s == '\r')
    {
        s = getchar();
    }
    while (s != ' ' && s != '\n' && s != '\r')
    {
        str += s;
        s = getchar();
    }
    return str;
}
int main(){
    memset(Next,-1,sizeof Next);
    s0 = Read();
    BuildMatch(s0, Next);
    for (int i = 0; i < s0.length(); ++i) {
        printf("%d\n",Next[i] + 1);
    }
    return 0;
}
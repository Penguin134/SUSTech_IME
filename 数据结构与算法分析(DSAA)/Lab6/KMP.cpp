#include <cstring>
#include <cstdlib>
#include <cstdio>
using namespace std;

typedef int Position;
#define NotFound -1

void BuildMatch( char *pattern, int *match )
{
    Position i, j;
    int m = strlen(pattern);
    match[0] = -1;

    for ( j=1; j<m; j++ ) {
        i = match[j-1];
        while ( (i>=0) && (pattern[i+1]!=pattern[j]) )
            i = match[i]; /* 如果不匹配，则回到上一次匹配处 */
        if ( pattern[i+1]==pattern[j] )
            match[j] = i+1;
        else match[j] = -1;
    }
}

Position KMP( char *string, char *pattern )
{
    int n = strlen(string);
    int m = strlen(pattern);
    Position s, p, *match;

    if ( n < m ) return NotFound;
    match = (Position *)malloc(sizeof(Position) * m);
    BuildMatch(pattern, match);
    s = p = 0;
    while ( s<n && p<m ) {
        if ( string[s]==pattern[p] ) {
            s++; p++;
        }
        else if (p>0) p = match[p-1]+1;
        else s++;
    }
    return ( p==m )? (s-m) : NotFound;
}
int read(){
    int s=0,f=1;
    char ch=getchar();
    while(ch<'0'||ch>'9'){
        if(ch=='-')
            f=-1;
        ch=getchar();
    }
    while(ch>='0'&&ch<='9'){
        s=s*10+ch-'0';
        ch=getchar();
    }
    return s*f;
}
void write(int x){
    if(x<0){
        putchar('-');
        x=-x;
    }
    if(x>9)
        write(x/10);
    putchar(x%10+'0');
}
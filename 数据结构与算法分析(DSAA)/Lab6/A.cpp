#include "iostream"
#include "cstring"
#include "string"
using namespace std;

int main(){
    string s;
    cin>>s;
    int l = s.length(),count = 0;
    for (int i = 1; i <= l; ++i) {
        for (int j = 0; j <= l - i; ++j) {
            string temp = s.substr(j,i);
            ++count;
            for (int k = j+1; k <= l - i; ++k) {
                if (temp == s.substr(k,i)) {
                    --count;
                    break;
                }
            }
        }
    }
    cout<<count<<endl;
    return 0;
}

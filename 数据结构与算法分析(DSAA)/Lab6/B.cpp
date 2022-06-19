#include "iostream"
#include "string"
using namespace std;
int Tf[100005][26],step=0;

int main(){
    string s;
    cin>>s;
    Tf[0][s[0] - 'a'] = 1;
    // Build Transition Function
    for (int i = 1; i < s.length(); ++i) {
        for (int j = 0; j < 26; ++j) {
            Tf[i][j] = Tf[step][j];
        }
        Tf[i][s[i] - 'a'] = i+1;
        step = Tf[step][s[i] - 'a'];
    }
    for (int i = 0; i < s.length(); ++i) {
        for (int j = 0; j < 26; ++j) {
            cout<<Tf[i][j]<<' ';
        }
        cout<<endl;
    }
    return 0;
}
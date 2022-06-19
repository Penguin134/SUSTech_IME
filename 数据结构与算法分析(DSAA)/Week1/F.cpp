#include "iostream"
#include "cmath"
using namespace std;
char patterns[]={'s','c','/','x','+','^'};
bool Flag = true;

void find(string str, char pattern){
    int len,j,num;
    for (int i = 0; i < str.size() && Flag; ++i) {
        if (str[i] == pattern){
            j = i - 1; num =0; len = 0;
            while (isdigit(str[j])) {
                num += (str[j] - '0') * (int)pow(10,len);
                len ++; --j;
                // cout<<num<<endl;
                if (num)
                    Flag = false;
            }
        }
    }
}
int main(){
    int n;
    string str;
    cin>>n;
    // cout<<&patterns[0]<<endl;
    while (n--){
        Flag = true;
        cin>>str;
        for (int i = 0; i < 6  && Flag; ++i) {
            find(str, patterns[i]);
        }

        if (Flag) {
            int len = 0, j = str.size() - 1, num = 0;
            while (isdigit(str[j])) {
                num += (str[j] - '0') * (int) pow(10, len);
                len++;
                --j;
                // cout << num << endl;
                if (num)
                    Flag = false;
            }
        }

        if (Flag)
            cout<<"yes"<<endl;
        else
            cout<<"no"<<endl;
    }
    return 0;
}
/*

1
10sinx+20cos+30x+40/sinx+50^x+60/cosx+70/x+0

*/
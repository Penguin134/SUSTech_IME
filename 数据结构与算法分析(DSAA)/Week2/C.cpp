//
// Created by Penguin on 2021/9/14.
//

// 0 < x < 240
#include "iostream"
#include "cmath"
using namespace std;
int T;
double f_left,f_right,f_middle;

double f(double x){
    return x*pow(2.7182818,x/20.0);
}

double init_var(double b){
    f_left = 0.0; f_right = 239.1234567;
    f_middle = (f_left + f_right) / 2.0;
    while (f(f_right) - f(f_left) > 1e-4){
        //printf("%.10f %.10f\n",f(f_right),f(f_left));
        if (f(f_middle) > b)
            f_right = f_middle;
        else
            f_left = f_middle;
        f_middle = (f_left + f_right) / 2;
    }
    return f_middle;
}
int main(){
    double b;
    cin>>T;
    for (int i = 0; i < T; ++i) {
        cin>>b;
        printf("%.10f\n", init_var(b));
    }
}
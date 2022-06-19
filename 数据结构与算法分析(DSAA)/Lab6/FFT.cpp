#include "iostream"
#include "cmath"
#include "cstdio"
using namespace std;
typedef long long ll;
#define fu(ty,a,b,c) for(ty a=b;a<c;++a)
#define fd(ty,a,b,c) for(ty a=b;a>c;++a)
const ll maxn = (1000);
const double pi =  acos(-1.0);

struct Complex{
    double real,imag;
    Complex(double x=0,double y=0):real(x),imag(y){};
    Complex operator + (Complex b){
        return {real+b.real,imag+b.imag};
    }
    Complex operator - (Complex b){
        return {real-b.real,imag-b.imag};
    }
    Complex operator * (Complex b){
        return {real*b.real - imag*b.imag,real*b.imag + imag*b.real};
    }
};

Complex a[maxn];
/**
 * The FFT computes Fourier Series from x[0] to x[n]
 * @param cm the DT signal x
 * @param num the least log2 bigger than x
 * @param tag the value of either 1 or -1, which means FT or inverse-FT
 * @author HRH
 */
void FFT(Complex *cm,ll num,ll tag){
    if(tag != 1 && tag != -1){
        throw "Invalid tag value\n";
    }
    if (num == 1)
        return;
    ll half = num / 2;
    Complex cm1[half], cm2[half];
    for (ll i = 0; i < num; i += 2)
    {
        cm1[i / 2] = cm[i];
        cm2[i / 2] = cm[i + 1];
    }
    FFT(cm1, half, tag);
    FFT(cm2, half, tag);
    Complex wk = Complex(cos(2*pi / num), tag*sin(2*pi / num)), w(1,0);
    for (ll i = 0; i < half; i++){
        Complex buf = w * cm2[i];
        cm[i] = cm1[i] + buf;
        cm[i + half] = cm1[i] - buf;
        w = w * wk;
    }
}
int main(){
    ll n;
    cin>>n;
    fu(ll, i, 0, n)
        cin >> a[i].real;
    ll maxx = 1;
    while ((maxx) < n){
        maxx <<= 1;
    }
    FFT(a, maxx, 1);
    fu(ll, i, 0, n){
        char sign = a[i].imag >= 0 ? '+' : '-';
        printf("%.5f %c %.5fi  ",a[i].real/maxx,sign,abs(a[i].imag/maxx));
    }
    return 0;
}
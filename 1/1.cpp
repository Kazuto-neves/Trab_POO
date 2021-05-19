#include<iostream>
#include <iomanip>
#include <cmath>

using namespace std;

class TPoligono{
    private:
        double a[100],b[100],p=0;
        int q;
    public:
        void ler();
        double perimetro();
};

void TPoligono::ler(){
    cin >> q;
    for(int i=0;i<q;i++)cin >> a[i] >> b[i];
}

double TPoligono::perimetro(){
    for(int i=0;i<q;i++)
        i==q-1?p+=sqrt(((a[i]-a[0])*(a[i]-a[0]))+((b[i]-b[0])*(b[i]-b[0]))):p+=sqrt(((a[i]-a[i+1])*(a[i]-a[i+1]))+((b[i]-b[i+1])*(b[i]-b[i+1])));
    cout << setprecision(2) << fixed;
    return p;
}

int main(){
    TPoligono p;
	p.ler();
    cout << "perimetro - " << p.perimetro() << endl;
    return 0;
}
#include<iostream>
#include <iomanip>

using namespace std;

class TPoligono{
    private:
        double x[100],y[100];
        int q;
    public:
        void ler();
        double perimetro();
};

void TPoligono::ler(){
    cin >> q;
    for(int i=0;i<q;i++)cin >> x[i] >> y[i];
}

double TPoligono::perimetro(){
    double p;
    cout << setprecision(2) << fixed;
    for(int i=0;i<q;i++)p+=x[i]+y[i];
    return p;
}


int main(){
    TPoligono p;
	p.ler();
    cout << "perimetro - " << p.perimetro();
    return 0;
}
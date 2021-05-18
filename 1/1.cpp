#include<iostream>
#include <iomanip>

using namespace std;

class TPoligono{
    private:
        double x[100],y[100],p=0;
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
    for(int i=0;i<q;i++)p==0?p=x[i]+y[i]:p+=x[i]+y[i];
    cout << setprecision(2) << fixed;
    return p;
}

int main(){
    TPoligono p;
	p.ler();
    cout << "perimetro - " << p.perimetro() << endl;
    return 0;
}
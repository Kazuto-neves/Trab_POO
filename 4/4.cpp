#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

#define max 100

class TPotencia{
    private:
        float n;
	    int exp;
    public:
        void ler(){cin >> n >> exp;};
	    float calcular(float f){return n*pow(f,exp);};
};

class TPolinomio{
    private:
        TPotencia a[max];
   	    int q;
    public:
	    void ler();
	    float calcular(float f);
};

void TPolinomio::ler(){
    cin >> q;
    for(int i=0; i<q; i++)a[i].ler();     
}

float TPolinomio::calcular(float f){
    float s=0;
    for(int i=0; i<q; i++)s+=a[i].calcular(f);
    return s;
}

int main(){
	TPolinomio p;
	float x;
	p.ler();
	cin >> x;
    cout << fixed << setprecision(2);
	cout << "p(" << x << ") = " << p.calcular(x) << endl;
	return 0;
}
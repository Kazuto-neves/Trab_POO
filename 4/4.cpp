#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

#define MAX 100

class TPotencia{
    private:
        float n;
	    int exp;
    public:
        void ler();
	    float calcular(float b);
};

class TPolinomio{
    private:
        TPotencia a[MAX];
   	    int q;
    public:
	    void ler();
	    float calcular(float b);
};

void TPotencia::ler(){
   cout << "Coeficiente:";	cin >> n;
   cout << "Expoente:";	cin >> exp; 
}

float TPotencia::calcular(float b){
   return n*pow(b,exp);
}

void TPolinomio::ler(){
    cout << "Entre com a quantidade de termos:";
    cin >> q;
    for(int i=0; i<q; i++){
	cout << "termo "<< i+1 << " de " << q << endl;
        a[i].ler();
    }      
}

float TPolinomio::calcular(float b){
    float s=0;
    cout << setprecision(1) << fixed;
    for(int i=0; i<q; i++)s=s+a[i].calcular(b);
    return s;
}

int main(){
	TPolinomio p;
	float x;
	p.ler();
    cout << "entre com o valor de x:";
	cin >> x;
	cout << "p(" << x << ") = " << p.calcular(x) << endl;
	return 0;
}
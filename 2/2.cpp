#include<iostream>

using namespace std;

#define MAX 100

class TVetInt{
    private:
        int a[MAX],b[MAX],q;
    public:
        void ler();
        void inverter();
        void listar();
};

void TVetInt::ler(){
    cout << "Entre com a quantidade de elementos:";
    cin >> q;
    for(int i=0; i<q; i++){
       cout << "entre com o valor " << i+1 << " de " << q << ":";
       cin >> a[i]; 
    }
}

void TVetInt::inverter(){
 	int j = 0;
 	for (int i=q-1;i>=0;i--){
		b[j] = a[i];
		j++;
	}   
}

void TVetInt::listar(){
    for(int i=0;i<q;i++)
       cout << b[i] << " ";
    cout << endl;
}

int main(){
    TVetInt v;
    v.ler();
    v.inverter();
    v.listar();
    return 0;
}

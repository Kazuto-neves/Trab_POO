#include<iostream>

using namespace std;

#define MAX 100

class TVetInt{
    private:
        int a[MAX],q;
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
    int b[MAX];
    for(int i=q-1;i>=0;i--)
        for(int j=0;j<=q;j++)
            b[j]=a[i];
    for(int i=0;i<=q;i++)
        a[i]=b[i];
        
}

void TVetInt::listar(){
    for(int i=0;i<=q;i++)
       cout << a[i] << " ";
    cout << endl;
}

int main(){
    TVetInt v;
    v.ler();
    v.inverter();
    v.listar();
    return 0;
}

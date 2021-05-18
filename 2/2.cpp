#include<iostream>

using namespace std;

#define max 100

class TVetInt{
    private:
        int a[max],b[max],q;
    public:
        void ler();
        void inverter(){for (int i=q-1,x=0;i>=0;i--,x++)b[x] = a[i];};
        void listar();
};

void TVetInt::ler(){
    cin >> q;
    for(int i=0; i<q; i++)cin >> a[i]; 
}

void TVetInt::listar(){
    for(int i=0;i<q;i++)i==q-1?cout<<b[i]:cout << b[i] << " ";
    cout << endl;
}

int main(){
    TVetInt v;
    v.ler();
    v.inverter();
    v.listar();
    return 0;
}
#include<iostream>
#include <iomanip>

using namespace std;

#define max 100


class TMatriz{
    private:
        int l,c;
        char m[max][max];
    public:
        void ler();
        void transposta();
        void mostrar();
};

void TMatriz::ler(){
    cin >> l >> c;
    cin.ignore();
    for(int i=0;i<l;i++)
        for(int j=0;j<c;j++)
            cin >> m[i][j];
}

void TMatriz::transposta(){
    char t[max][max];
    for(int i=0;i<l;i++)
        for(int j=0;j<c;j++) 
            t[j][i]=m[i][j];

    for (int i=0;i<c;i++)
        for (int j=0; j<l;j++)
            m[i][j] = t[i][j];
}

void TMatriz::mostrar(){
    for (int i=0; i<c;i++) {
        for (int j=0; j<l;j++) {cout << m[i][j];}
        cout << endl;
    }
}

int main(){
    TMatriz a;
	a.ler();
	a.transposta();
    a.mostrar();
    return 0;
}
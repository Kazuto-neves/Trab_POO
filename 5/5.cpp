#include<iostream>
#include <iomanip>

using namespace std;

#define max 100

class aluno{
    private:
       string Nome;
       float n1,n2;
    public:
       void ler();
       float media(){return (n1+2*n2)/3;};
       string AouR(){return media()>=6?"Aprovado":"Reprovado";};
       string getNome(){return Nome;};
       float getN1(){return n1;};
       float getN2(){return n2;};
};

class TTurma{
    private:
       aluno a[max];
       int    q;
    public:
        void ler();
        void listar();
};

void aluno::ler(){
   cin.ignore();
   cout << "Nome:";		getline(cin,Nome);
   cout << "Nota1:";		cin >> n1;
   cout << "Nota2:";		cin >> n2;

}

void TTurma::ler(){
  cout << "Entre com a quantidade de aluno:";   cin >> q;
  for (int i=0; i<q ; i++)a[i].ler();
}

void TTurma::listar(){
   cout << setprecision(2) << fixed;
   for(int i=0;i<q;i++)
      cout << setw(30) << left << a[i].getNome() << right << setw(6) << a[i].getN1() << setw(6) << a[i].getN2() << setw(6) << a[i].media() << setw(10) << left << " " << a[i].AouR() << endl;       
}

int main(){
	TTurma t;
	t.ler();
	t.listar();
	return 0;
}
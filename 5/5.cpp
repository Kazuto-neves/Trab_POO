#include<iostream>
#include <iomanip>

using namespace std;

#define max 100

class aluno{
    private:
       string Nome;
       float N1,N2;
    public:
       void IncerirAluno();
       float Media(){return (N1+2*N2)/3;};
       string Condicao(){return Media()>=6?"Aprovado":"Reprovado";};
       string getNome(){return Nome;};
       float getN1(){return N1;};
       float getN2(){return N2;};
};

class TTurma{
    private:
       aluno a[max];
       int  q;
    public:
        void ler();
        void listar();
};

void aluno::IncerirAluno(){
   cin.ignore();
   cout << "Nome:";		getline(cin,Nome);
   cout << "Nota1:";		cin >> N1;
   cout << "Nota2:";		cin >> N2;
}

void TTurma::ler(){
  cout << "Entre com a quantidade de aluno:";   cin >> q;
  for (int i=0; i<q ; i++)a[i].IncerirAluno();
}

void TTurma::listar(){
   cout << setprecision(2) << fixed;
   for(int i=0;i<q;i++)
      cout << setw(30) << left << a[i].getNome() << right << setw(6) << a[i].getN1() << setw(6) << a[i].getN2() << setw(6) << a[i].Media() << setw(10) << left << " " << a[i].Condicao() << endl;       
}

int main(){
	TTurma t;
	t.ler();
	t.listar();
	return 0;
}
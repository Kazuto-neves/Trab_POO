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
   getline(cin,Nome);
   cin >> N1 >> N2;
}

void TTurma::ler(){
  cin >> q;
  for (int i=0; i<q ; i++)a[i].IncerirAluno();
}

void TTurma::listar(){
   cout << setprecision(2) << fixed;
   for(int i=0;i<q;i++)
      cout << setw(50) << left << a[i].getNome() << right << a[i].Media() << " " << a[i].Condicao() << endl;       
}

int main(){
	TTurma t;
	t.ler();
	t.listar();
	return 0;
}
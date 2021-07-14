#include <bits/stdc++.h>

using namespace std;

class Contato{
    private: string Nome,Email,Telefone;
    public:
        void ler();
        string getNome(){return Nome;}
        string getEmail(){return Email;}
        string getTelefone(){return Telefone;}
};

void Contato::ler(){
    getline(cin,Nome);      cin.ignore(1);
    getline(cin,Email);     cin.ignore(1);
    getline(cin,Email);     cin.ignore(1);
}

class Agenda{
    private: vector <Contato> C;
    public: 
        void inserir(Contato c);
        int obterIndice(string email);
        void remover(string email);
        void mostrar();
        void listar();
};

void Agenda::inserir(Contato c){C.push_back(c);}

int Agenda::obterIndice(string email){
	bool achou=false;
	int i=0;
	while (!achou && i<C.size())
		if (C.operator[i].string() == codigo)
			achou = true;
		else
			i++;	
	return achou?i : -1;
}

void Agenda::remover(string email){

}
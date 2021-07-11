#include <iostream>
#include <iomanip>
#include <cstring>
#include <cstdlib>
#include <list>

using namespace std;

class Contato{
    private:
        string Nome,Email,Telefone;
    public:
        void ler();
};

class Agenda{
    private:
        list <Contato> C;
    public:
        Agenda::Agenda(){C.clear();}
        Agenda::~Agenda();
        void inserir();
        void remover();
        void mostrar();
};

void Contato::ler(){
    getline(cin,Nome);
    getline(cin,Email);
    getline(cin,Telefone);
}

void Agenda::inserir(){
    
}
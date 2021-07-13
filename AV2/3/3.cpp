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
        string getNome(){return Nome;}
        string getEmail(){return Email;}
        string getTelefone(){return Telefone;}
};

void Contato::ler(){
    getline(cin,Telefone);  cin.ignore(1);
    getline(cin,Email);     cin.ignore(1);
    getline(cin,Nome);      cin.ignore(1);
}

class Agenda{
    private:
        list <Contato> C;
    public:
        void inserir(Contato c);
        void remover(string email);
        void mostrar();
        void listar();
};

void Agenda::inserir(Contato c){C.push_back(c);}

void Agenda::remover(string email){
    C.remove_if([email](const Contato& c){
        return((Contato)c).getEmail()==email;});
}

void Agenda::listar(){
    cout << left << setfill(' ') << setw(30) << "Nome"
    << left << setfill(' ') << setw(30) << "Email"
    << right << setfill(' ') << setw(20) << "Telefone" << endl;
}

void Agenda::mostrar(){
    listar();
    for(auto c : C)
        cout << left << setfill(' ') << setw(30) << c.getNome()
        << left << setfill(' ') << setw(30) << c.getEmail()
        << right << setfill(' ') << setw(20) << c.getTelefone() << endl;
}

int menu(){
    int opc;
    do{
        cout << "1 - inserir" << endl;
        cout << "2 - remover" << endl;
        cout << "3 - listar" << endl;
        cout << "4 - sair" << endl;
        cout << "Entre com a sua escolha:" << endl;
        cin >> opc;
    }while (opc < 1 || opc > 4);
    return opc;
}
int main(){
    Contato d;
    Agenda h;
    bool end = false;
    string s;
    while(!end){
        switch (menu()){
            case 1:
                d.ler();
                h.inserir(d);
                break;
            case 2:
                cin.ignore(1);
                getline(cin,s);
                h.remover(s);
                break;
            case 3:
                h.mostrar();
                break;
            case 4:
                cout << "Programa encerrado!" << endl;
                end = true;
                break;
            default:
                menu();
                break;
            }
        }
    return 0;
}
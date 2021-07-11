#include <iostream>
#include <iomanip>
#include <cstring>
#include <cstdlib>

using namespace std;

class Produto {
    private:
        string nome;
        int Codigo;
        double Preco;
    public:
        void ler();
        void mostrar();

        int getCodigo() {return Codigo;}
        string getNome() {return nome;} 
        double getPreco() {return Preco;}
};

class Cardapio {
    private:
        Produto v[20];
        int qtd;
    public:
        Cardapio();
        void inserirProduto(Produto d);
        int obterIndice(int &id);
        void listar();
        int excluir(int &id);
        void alterar(int &id, Produto d);
        void Mostrar();
        void Consultar(int &id);
};

void Produto::ler(){
    cin >> Codigo;
    cin.ignore(1);
    getline(cin, nome);
    cin >> Preco;
}

void Produto::mostrar(){
    cout << setfill('0') << setw(5) << right << Codigo << "  ";
    cout << setfill(' ') << setw(30) << left << nome;
    cout << setfill('0') << setw(3) << "R$  "<< Preco << endl;
}

int Cardapio::obterIndice(int &id){
    int i = 0;
    bool achou = 0;
    while (!achou && i<qtd){
        id == v[i].getCodigo() ? achou = 1 : i++;
    }
    return achou ? i : -1;
}

int Cardapio::excluir(int &id){
   int pos = obterIndice(id);
   if (pos>-1){
       v[pos] = v[qtd-1];
       qtd--;
       return 1;
   }else return 0;
}

void Cardapio::alterar(int &id, Produto d){
   int pos = obterIndice(id);
   v[pos] = d;
}

Cardapio::Cardapio(){qtd = 0;}

void Cardapio::inserirProduto(Produto d){
    v[qtd] = d;
    qtd++;
}

void Cardapio::listar(){cout << "Codigo Nome" << setw(34) << right << "Preco" << endl;}

void Cardapio::Mostrar(){
    int i;
    listar();
    for (i = 0; i < qtd; i++)v[i].mostrar();
}

void Cardapio::Consultar(int &id){
    int pos = obterIndice(id);
    pos>-1?cout<<"R$ "<<v[pos].getPreco()<<endl:cout<<"R$ 0.00"<<endl;
}

int menu(){
    int opc;
    do{
        cout << "1 - inserir" << endl;
        cout << "2 - remover" << endl;
        cout << "3 - consultar" << endl;
        cout << "4 - alterar" << endl;
        cout << "5 - listar" << endl;
        cout << "6 - sair" << endl;
        cout << "Entre com a sua escolha:" << endl;
        cin >> opc;
    }while (opc < 1 || opc > 6);
    return opc;
}
int main(){
    Produto d;
    Cardapio h;
    bool end = false;
    string ok,s;
    int i,j,k;
    string confirma, busca;
    int buscar;
    cout << setprecision(2) << fixed;
    while(!end){
        switch (menu()){
            case 1:
                d.ler();
                h.inserirProduto(d);
                //cout << "Produto inserida com sucesso!" << endl;
                break;
            case 2:
                cin >> i;
                h.excluir(i);
                //if(h.excluir(i))cout << "Produto removida com sucesso!" << endl;
                //else cout << "Produto nao encontrada!" << endl;
                break;
            case 3:
                cin >> i;
                h.Consultar(i);
            case 4:
                cin >> i;
                if(h.obterIndice(i) > -1){
                    d.ler();
                    h.alterar(i, d);
                    //cout << "Produto alterada com sucesso!" << endl;
                } //cout << "Produto nao encontrada!" << endl;
                break;
            case 5:
                h.Mostrar();
                break;
            case 6:
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
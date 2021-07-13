#include <iostream>
#include <string>
#include <iomanip>
#include <list>

using namespace std;

class IImposto {
public:
    virtual int getCodigo()             = 0;
    virtual void ler()                  = 0;
    virtual bool contains(string texto) = 0;
    virtual string getNome()            = 0;
    virtual double getRA()              = 0;
    virtual double IR()                 = 0;
    virtual ~IImposto(){}
};

class Pessoa : public IImposto {
private:
    int codigo;
    string nome;
    double RA;
public:
    int getCodigo(); /***/ void setCodigo(int v);
    string getNome(); /**/ void setNome(string v);
    double getRA(); /****/ void setRA(double v);

    virtual void ler();
    virtual bool contains(string texto);
};

int Pessoa::getCodigo(){return codigo;} /****/ void Pessoa::setCodigo(int v){codigo = v;}

string Pessoa::getNome(){return nome;} /*****/ void Pessoa::setNome(string v){nome = v;}

double Pessoa::getRA(){return RA;} /*********/ void Pessoa::setRA(double v){RA = v;}

void Pessoa::ler(){
    cin >> codigo;  cin.ignore(1);
    getline(cin, nome);
    cin >> RA;
}

class Juridica : public Pessoa {
private:
    string CNPJ;
    int NIM,NIN;
public:
    void ler();
    bool contains(string texto);
    double IR();

    string getCNPJ(); /***/ void setCNPJ(string v);
    int getNIM(); /*******/ void setNIM(int v);
    int getNIN(); /*******/ void setNIN(int v);
};

string Juridica::getCNPJ(){return CNPJ;} /****/ void Juridica::setCNPJ(string v){CNPJ = v;}

int Juridica::getNIM(){return NIM;} /********/ void Juridica::setNIM(int v){NIM = v;}
int Juridica::getNIN(){return NIN;} /********/ void Juridica::setNIN(int v){NIN = v;}

void Juridica::ler(){
    Pessoa::ler();
    getline(cin,CNPJ);
    cin >> NIM >> NIN;
}

double Juridica::IR(){return getRA()>200000? getRA()*0.25 : getRA()*0.15;}

class Fisico : public Pessoa {
private:
    int NumDep;
    string CPF,profissao;
public:
    void ler();
    bool contains(string texto);
    double IR();

    int getNumDep(); /********/ void setNumDep(int v);
    string getCPF(); /********/ void setCPF(string v);
    string getProfissao(); /**/ void setProfissao(string v);
};

int Fisico::getNumDep(){return NumDep;} /***********/ void Fisico::setNumDep(int v){NumDep = v;}

string Fisico::getCPF(){return CPF;} /**************/ void Fisico::setCPF(string v){CPF = v;}

string Fisico::getProfissao(){return profissao;} /**/ void Fisico::setProfissao(string v){profissao = v;}

void Fisico::ler(){
    Pessoa::ler();
    cin.ignore(1);
    getline(cin,CPF);
    getline(cin,profissao);
    cin >> NumDep;
}

double Fisico::IR(){return (0.07*getRA());}



class Imposto{
private:
    list <IImposto*> I; // Precisa de Ponteiro
    int obterIndice(int codigo);
public:
    Imposto();
    virtual ~Imposto();
    void inserir(IImposto *a);
    void remover(int codigo);
    void listar();
    bool existe(int codigo);
    void filtrar(string texto);
    void filtrarCPF(string CPF);
    double obterDiaria(int codigo);
};

Imposto::Imposto(){} // construtor não precisa ter nada

Imposto::~Imposto(){for(auto it=I.end();it!=I.begin();it--)I.erase(it);}

//int Imposto::obterIndice(int codigo){
//    bool achou=false;
//    int i=0;
//    while (!achou && i<I.size())
//        for(auto it=I.begin();it!=I.end();it++)
//            if (I->getCodigo() == codigo) achou = true;
//            else i++;
//    return achou?i : -1;
//}

void Imposto::inserir(IImposto *a){

   I.push_back(a); //Vc não está trabalhando com vetor[]

//    vet[qtd]=a;
//    qtd++;
}

void Imposto::remover(int codigo){
	for(auto it = I.begin(); it != I.end(); ++ it){
        if(it.operator*()->getCodigo() == codigo){
            I.erase(it);
        }
    }

//    int pos = obterIndice(codigo);
//    if (pos>-1){
//        for(int i=pos+1; i<qtd; i++)vet[i-1] = vet[i];
//        qtd--;
//    }
}

void Imposto::alterar(int codigo, IImposto *a){ //NÃO TEM ALTERAR NO EXERCICIO

//    int pos = obterIndice(codigo);
//    if (pos>-1){
//        delete vet[pos];
//        vet[pos]=a;
//    }
}

//bool Imposto::existe(int codigo){return obterIndice(codigo)>-1;}
//
//double Imposto::obterDiaria(int codigo){
//    int pos = obterIndice(codigo);
//    if (pos>-1) return vet[pos]->diaria();
//    else return 0;
//}

int menu(){
    int opc;
    do{
        cout << "1 - inserir pessoa fisica" << endl
             << "2 - inserir pessoa juridica" << endl
             << "3 - remover" << endl
             << "4 - consultar" << endl
             << "5 - ir" << endl
             << "6 - listar" << endl
             << "7. Sair" << endl
             << "Escolha uma opcao: ";
        cin >> opc;
    } while (opc < 1 || opc > 7);
    cin.ignore();
    cout << endl;
    return opc;
}

int main(){
    Pessoa* Pessoa;
    Imposto l;
    string texto;
    bool fim = false;
    int codigo;
    while (!fim){
        switch (menu()){
        case 1:
            Pessoa = cri;
            Pessoa->ler();
            l.inserir(Pessoa);
            cout << "Inserida com sucesso!" << endl; break;
        case 2:
            cout << "Digite o codigo do Pessoa a ser removido: ";
            cin >> codigo;
            cout << endl;
            if(l.existe(codigo)){
                l.remover(codigo);
                cout << "Removido com sucesso!" << endl;              
            }else
                cout << "Nao encontrado!" << endl; break;
        case 3:
            cout << "Digite o codigo do Pessoa a ser alterado: ";
            cin >> codigo;
            cout << endl;
            if(l.existe(codigo)){
                Pessoa = criarPessoa();
                Pessoa->ler();
                l.alterar(codigo, Pessoa);
                cout << "Alterada com sucesso!" << endl;
            }else
                cout << "Nao encontrado!" << endl; break;
        case 4:
            cout << "Digite o texto do filtro: ";
            getline(cin, texto);
            cout << endl;
            l.filtrar(texto);
            lerOk(); break;
        case 5:
            cout << "Digite o nome da CPF: ";
            getline(cin, texto);
            cout << endl;
            l.filtrarCPF(texto);                                          
            lerOk(); break;
        case 6:
            cout << "Digite o codigo do Pessoa: ";
            cin >> codigo;
            cout << endl;
            if(l.existe(codigo))
		        cout << "Aluguel: " << l.obterDiaria(codigo) << endl;
	        else
		        cout << "Nao encontrado!" << endl; break;
            lerOk(); break;
        case 7:
            fim = true; break;
        default:
            cout << "Opcao invalida!" << endl; break;
        }
    }
}

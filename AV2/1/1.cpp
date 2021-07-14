#include <iostream>
#include <string>
#include <iomanip>
#include <list>

using namespace std;

class IImposto {
public:
    virtual int getCod()                = 0;
    virtual void ler()                  = 0;
    virtual void status()               = 0;
    virtual string getNome()            = 0;
    virtual double getRA()              = 0;
    virtual string getClasse()		    = 0;
    virtual double IR()                 = 0;
    virtual ~IImposto(){}
};

class Pessoa : public IImposto{
    private:int Cod;    string Nome;    double RA;
    public:
        int getCod(){return Cod;} /***/ void setCod(int i){Cod = i;}
        string getNome(){return Nome;} /**/ void setNome(string i){Nome = i;}
        double getRA(){return RA;} /****/ void setRA(double i){RA=i;}

        virtual void ler();
        virtual string getClasse() {return "Pessoa";}
};

void Pessoa::ler(){
    cin >> Cod;  cin.ignore(1);
    getline(cin, Nome);
    cin >> RA;
}

class Juridica : public Pessoa{
    private:
        string CNPJ;
        int NIM,NIN;
    public:
        string getCNPJ(){return CNPJ;} /***/ void setCNPJ(string j){CNPJ = j;}
        int getNIM(){return NIM;} /*******/ void setNIM(int j){NIM = j;}
        int getNIN(){return NIN;} /*******/ void setNIN(int j){NIN = j;}

        void ler();
        double IR();
        void status();
        string getClasse() {return "Juridica";}
};

void Juridica::ler(){
    Pessoa::ler();
    cin.ignore(1);
    getline(cin,CNPJ);
    cin >> NIM >> NIN;
}

double Juridica::IR(){return getRA()>200000?getRA()*0.25:getRA()*0.15;}

void Juridica::status(){
     cout << "Codigo : " << getCod()        << endl;
     cout << "Nome : " << getNome()         << endl;
     cout << "Renda Anual : " << getRA()    << endl;
     cout << "CNPJ : " << getCNPJ()         << endl;
     cout << "Inscr. Mun. : " << getNIM()   << endl;
     cout << "Inscr. Est. : " << getNIN()   << endl;
}

class Fisico : public Pessoa {
    private:
        int NumDep;
        string CPF,Profissao;
    public:
        int getNumDep(){return NumDep;} /**/ void setNumDep(int f){NumDep = f;}
        string getCPF(){return CPF;} /**/ void setCPF(string f){CPF=f;}
        string getProfissao(){return Profissao;} /**/ void setProfissao(string f){Profissao=f;}

        void ler();
        double IR();
        void status();
        string getClasse() {return "Fisico";}
};

void Fisico::ler(){
    Pessoa::ler();      cin.ignore(1);
    getline(cin,CPF);   getline(cin,Profissao);
    cin >> NumDep;
}

double Fisico::IR(){return 0.07*getRA();}

void Fisico::status(){
     cout << "Codigo : " << getCod()            << endl;
     cout << "Nome : " << getNome()             << endl;
     cout << "Renda Anual : " << getRA()        << endl;
     cout << "CPF : " << getCPF()               << endl;
     cout << "Profissao : " << getProfissao()   << endl;
     cout << "Dependentes : " << getNumDep()    << endl;
}

class Imposto{
    private:
        list <IImposto*> I;
    public:
        Imposto();
        virtual ~Imposto();
        void inserir(IImposto* a);
        void remover (int id);
        void listar();
        void consultar(int id);
        void MostrarIR(int id);
        void mostrar();
};

Imposto::Imposto(){}

Imposto::~Imposto(){
   for(auto it : I)
        delete it;
   I.clear();
}

void Imposto::inserir(IImposto* a){I.push_back(a);}

void Imposto::remover(int id){
    I.remove_if([id](const IImposto* c){
        return((IImposto*)c)->getCod()==id;});
}

void Imposto::consultar(int id){
    for(auto it:I){
        if(it->getCod() == id)it->status();
    }
}

void Imposto::listar(){
    cout << "Codigo " << "Nome"
    << setfill(' ')
    << setw(30) << "F/J"
    << setw(21) << "CPF/CNPJ"
    << setw(13) << "IR" << endl;
}

void Imposto::mostrar(){
    listar();
    for(auto it:I){
        cout << setfill('0') << setw(5) << right << it->getCod() << "  "
        << setfill(' ') << setw(30) << left << it->getNome() << "  "
        << setw(2) << (it->getClasse() == "Juridica"?"J":"F")
        << right << setw(21) << (it->getClasse() == "Juridica"?((Juridica*)it)->getCNPJ() : ((Fisico*)it)->getCPF()) << " "
        << "R$" << setfill(' ')<< right << setw(10) << (it->IR()) << endl;
        }
}

void Imposto::MostrarIR(int id){
    for(auto it:I){
        if(it->getCod() == id)cout <<"R$ "<< it->IR() << endl;
    }
}

int menu(){
    int opc;
    do{
        cout << "1 - inserir pessoa fisica" << endl
             << "2 - inserir pessoa juridica" << endl
             << "3 - remover" << endl
             << "4 - consultar" << endl
             << "5 - ir" << endl
             << "6 - listar" << endl
             << "7 - Sair" << endl
             << "Entre com a sua escolha: ";
        cin >> opc;
    } while (opc < 1 || opc > 7);
    cin.ignore();
    cout << endl;
    return opc;
}

int main(){
    Pessoa* Pessoa;
    Imposto l;
    bool fim = false;
    int id;
    cout << setprecision(2) << fixed;
    while (!fim){
        switch (menu()){
        case 1:
            Pessoa = new Fisico();
            Pessoa->ler();
            l.inserir(Pessoa);
            break;
        case 2:
            Pessoa = new Juridica();
            Pessoa->ler();
            l.inserir(Pessoa);
            break;
        case 3:
            cin >> id;
            l.remover(id);
            break;
        case 4:
            cin >> id;
            l.consultar(id);
            break;
        case 5:
            cin >> id;
            l.MostrarIR(id);              
            break;
        case 6:
            l.mostrar();
            break;
        case 7:
            cout << "Programa encerrado!" << endl;
            fim = true;
            break;
        default:
          menu(); 
          break;
        }
    }
}

#include <iostream>
#include <string>
#include <iomanip>
#include <vector>

using namespace std;

class IImposto {
public:
    virtual int getCod()                = 0;
    virtual void ler()                  = 0;
    virtual void status()               = 0;
    virtual string getNome()            = 0;
    virtual double getRA()              = 0;
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
};

void Juridica::ler(){
    Pessoa::ler();
    cin.ignore(1);
    getline(cin,CNPJ);
    cin >> NIM >> NIN;
}

double Juridica::IR(){return getRA()>200000?getRA()*0.25:getRA()*0.15;}

void Juridica::status(){
     cout << "nome : " << getNome() << endl;
     cout << "Renda Anual : " << getRA() << endl;
     cout << "CNPJ : " << getCNPJ() << endl;
     cout << "Inscr. Mun. : " << getNIM() << endl;
     cout << "Inscr. Est. : " << getNIN() << endl;
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
};

void Fisico::ler(){
    Pessoa::ler();      cin.ignore(1);
    getline(cin,CPF);   getline(cin,Profissao);
    cin >> NumDep;
}

double Fisico::IR(){return 0.07*getRA();}

void Fisico::status(){
     cout << "nome : " << getNome() << endl;
     cout << "Renda Anual : " << getRA() << endl;
     cout << "CPF : " << getCPF() << endl;
     cout << "Profissao : " << getProfissao() << endl;
     cout << "Num. Dep. : " << getNumDep() << endl;
}

class Imposto{
    private:
        vector <IImposto*> I;
    public:
        Imposto();
        virtual ~Imposto();
        void inserir(IImposto *a);
        void remover (int id);
        void listar();
        void consultar(int id);
        double MostrarIR (int id);
};

Imposto::Imposto(){}

Imposto::~Imposto(){for(auto it=I.end();it!=I.begin();--it)I.erase(it);}

void Imposto::inserir(IImposto *a){I.push_back(a);}

void Imposto::remover(int id){
    for(auto it = I.begin();it!=I.end();++it){
        if(it.operator*()->getCod() == id)I.erase(it);
    }
}

void Imposto::consultar(int id){
    for(int i=0;i<I.size();i++){
        if (I[i]->getCod() == id){
            I[i]->status();
    }
}
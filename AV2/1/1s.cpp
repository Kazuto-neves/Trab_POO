#include <iostream>
#include <string>
#include <iomanip>
//#include <vector>

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
        IImposto *v[100];
		int        qtd;
		int obterIndice(int id);
    public:
        Imposto();
        virtual ~Imposto();
        void inserir(IImposto *a);
        void remover (int id);
        bool existe(int id);
        void listar();
        void consultar(int id);
        void MostrarIR (int id);
        void mostrar();
};

Imposto::Imposto(){qtd=0;}

Imposto::~Imposto(){for(int i=0;i<qtd;i++)delete v[i];}

int Imposto::obterIndice(int id){
	bool achou=false;
	int i=0;
	while (!achou && i<qtd)
		if (v[i]->getCod() == id)achou = true;
		else i++;	
	return achou?i : -1;
}

bool Imposto::existe(int id){return obterIndice(id)>-1;}

void Imposto::inserir(IImposto *a){
    v[qtd]=a;
    qtd++;
}

void Imposto::remover(int id){
	int pos = obterIndice(id);
	if (pos>-1){
		for(int i=pos+1; i<qtd; i++)v[i-1] = v[i];
		qtd--;
	}
}

void Imposto::consultar(int id){
    for(int i=0;i<qtd;i++){
        if ((typeid(Juridica) == typeid(*v[i])) && ((Juridica*)v[i])->getCod() == id){
            v[i]->status();
        }
    }
}

void Imposto::listar(){
    cout << setfill(' ') << "Codigo Nome"
    << setw(28) << right << "F/J"
    << setw(16) << right << "CPF/CNPJ"
    << setw(22) << right << "IR" << endl;
}

void Imposto::mostrar(){
    listar();
    for(int i=0; i< qtd; i++)
		cout << v[i]->getCod() << setfill('0') << setw(5) << "  " << setfill(' ')
			 << setw(30) << left << v[i]->getNome() << "  "
			 << setw(20) << left << ((typeid(Juridica) == typeid(*v[i])) ? "J" : "F") << " "
			 << setw(20) << left << ((typeid(Juridica) == typeid(*v[i])) ? ((Juridica*)v[i])->getCNPJ() : ((Fisico*)v[i])->getCPF()) << " R$  " 
			 << setw(10) << v[i]->IR() << endl; 
}

void Imposto::MostrarIR(int id){
        for(int i=0;i<qtd;i++){
            if ((typeid(Juridica) == typeid(*v[i])) && ((Juridica*)v[i])->getCod() == id){
                cout << v[i]->IR() << endl;
        }
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
            Pessoa = new Fisico();
            Pessoa->ler();
            l.inserir(Pessoa);
            cout << "Inserida com sucesso!" << endl; break;
        case 2:
            Pessoa = new Juridica();
            Pessoa->ler();
            l.inserir(Pessoa);
            cout << "Inserida com sucesso!" << endl; break;
        case 3:
            cin >> codigo;
            cout << endl;
            if(l.existe(codigo)){
                l.remover(codigo);
                cout << "Removido com sucesso!" << endl;              
            }else
                cout << "Nao encontrado!" << endl; break;
        case 4:
            cin >> codigo;
            l.consultar(codigo);
            break;
        case 5:
            cin >> codigo;
            l.MostrarIR(codigo);              
            break;
        case 6:
            l.mostrar();
            break;
        case 7:
            fim = true; break;
        default:
            cout << "Opcao invalida!" << endl; break;
        }
    }
}

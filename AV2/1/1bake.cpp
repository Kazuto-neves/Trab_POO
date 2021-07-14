#include<string>
#include<iostream>
#include<iomanip>
#include "IAlugavel.h"
#include "Locadora.h"
#include "Jogo.h"

using namespace std;

Locadora::Locadora()
{
	qtd = 0;
}		

Locadora::~Locadora()
{
	for(int i=0;i<qtd;i++)
		delete vet[i];
}

int Locadora::obterIndice(int codigo)
{
	bool achou=false;
	int i=0;
	while (!achou && i<qtd)
		if (vet[i]->getCodigo() == codigo)
			achou = true;
		else
			i++;	
	return achou?i : -1;
}

void Locadora::inserir(IAlugavel *a)
{
	vet[qtd]=a;
	qtd++;
}

void Locadora::remover(int codigo)
{
	int pos = obterIndice(codigo);
	if (pos>-1)
	{
		for(int i=pos+1; i<qtd; i++)
			vet[i-1] = vet[i];
		qtd--;
	}
}

void Locadora::alterar(int codigo, IAlugavel *a)
{
	int pos = obterIndice(codigo);
	if (pos>-1)
	{
		delete vet[pos];
		vet[pos]=a;
	}
}
bool Locadora::existe(int codigo)
{
	return obterIndice(codigo)>-1;
}

double Locadora::obterDiaria(int codigo)
{
	int pos = obterIndice(codigo);
	if (pos>-1)
		return vet[pos]->diaria();
	else
		return 0;
}

void Locadora::listar()
{
	cout << setfill(' ') << setw(3) << "Cod" << "!" 
			<< setw(50) << left << "Titulo" << "!"
			<< setw(20) << "Tipo" << "!"
			<< setw(30) << left << "Midia"  << "!"
			<< setw(4) << right << "Ano" << "!"
			<< setw(8) << "Diaria" << endl; 
	cout << setfill('-') << setw(3) << "-" << "+" 
			<< setw(50) << left << "-" << "+"
			<< setw(20) << "-" << "+"
			<< setw(30) << left << "-"  << "+"
			<< setw(4) << right << "-" << "+"
			<< setw(8) << "-" << endl; 
	for(int i=0; i< qtd; i++)
		cout << setfill('0') << setw(3) << vet[i]->getCodigo() << "!" << setfill(' ')
			 << setw(50) << left << vet[i]->getTitulo() << "!"
			 << setw(20) << ((typeid(Jogo) == typeid(*vet[i])) ? "Jogo" : "Filme") << "!"
			 << setw(30) << left << vet[i]->getMidia() << "!"
			 << setw(4) << right << vet[i]->getAno() << "!"
			 << setw(8) << vet[i]->diaria() << endl; 
	cout << setfill('-') << setw(3) << "-" << "+" 
			<< setw(50) << left << "-" << "+"
			<< setw(20) << "-" << "+"
			<< setw(30) << left << "-"  << "+"
			<< setw(4) << right << "-" << "+"
			<< setw(8) << "-" << endl; 
}
void Locadora::filtrar(string texto)
{
	cout << setfill(' ') << setw(3) << "Cod" << "!" 
			<< setw(50) << left << "Titulo" << "!"
			<< setw(20) << "Tipo" << "!"
			<< setw(30) << left << "Midia"  << "!"
			<< setw(4) << right << "Ano" << "!"
			<< setw(8) << "Diaria"  << endl; 
	cout << setfill('-') << setw(3) << "-" << "+" 
			<< setw(50) << left << "-" << "+"
			<< setw(20) << "-" << "+"
			<< setw(30) << left << "-"  << "+"
			<< setw(4) << right << "-" << "+"
			<< setw(8) << "-" << endl; 
	for(int i=0; i< qtd; i++)
		if (vet[i]->contains(texto))
			cout << setfill('0') << setw(3) << vet[i]->getCodigo() << "!" << setfill(' ')
				<< setw(50) << left << vet[i]->getTitulo() << "!"
				<< setw(20) << ((typeid(Jogo) == typeid(*vet[i])) ? "Jogo" : "Filme") << "!"
				<< setw(30) << left << vet[i]->getMidia() << "!"
				<< setw(4) << right << vet[i]->getAno() << "!"
				<< setw(8) << vet[i]->diaria() << endl; 
	cout << setfill('-') << setw(3) << "-" << "+" 
			<< setw(50) << left << "-" << "+"
			<< setw(20) << "-" << "+"
			<< setw(30) << left << "-"  << "+"
			<< setw(4) << right << "-" << "+"
			<< setw(8) << "-" << endl; 
}
void Locadora::filtrarPlataforma(string plataforma)
{
	cout << setfill(' ') << setw(3) << "Cod" << "!" 
			<< setw(50) << left << "Titulo" << "!"
			<< setw(20) << "Tipo" << "!"
			<< setw(30) << left << "Midia"  << "!"
			<< setw(4) << right << "Ano" << "!"
			<< setw(8) << "Diaria" << endl; 
	cout << setfill('-') << setw(3) << "-" << "+" 
			<< setw(50) << left << "-" << "+"
			<< setw(20) << "-" << "+"
			<< setw(30) << left << "-"  << "+"
			<< setw(4) << right << "-" << "+"
			<< setw(8) << "-" << endl; 
	for(int i=0; i< qtd; i++)
		if ((typeid(Jogo) == typeid(*vet[i])) && ((Jogo*)vet[i])->getPlataforma().find(plataforma)!=string::npos)
			cout << setfill('0') << setw(3) << vet[i]->getCodigo() << "!" << setfill(' ')
				<< setw(50) << left << vet[i]->getTitulo() << "!"
				<< setw(20) << ((typeid(Jogo) == typeid(*vet[i])) ? "Jogo" : "Filme") << "!"
				<< setw(30) << left << vet[i]->getMidia() << "!"
				<< setw(4) << right << vet[i]->getAno() << "!"
				<< setw(8) << vet[i]->diaria() << endl; 
	cout << setfill('-') << setw(3) << "-" << "+" 
			<< setw(50) << left << "-" << "+"
			<< setw(20) << "-" << "+"
			<< setw(30) << left << "-"  << "+"
			<< setw(4) << right << "-" << "+"
			<< setw(8) << "-" << endl; 
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

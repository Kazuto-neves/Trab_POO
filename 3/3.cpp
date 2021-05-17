#include<iostream>

using namespace std;

#define max 100

class TConjunto
{
	private:
		float a[max];
		int q,obterIndice(float n);
	public:
		void ler();
		void mostrar();
		void uniao(TConjunto a, TConjunto b);
		void intersecao(TConjunto a, TConjunto b);
		void subtracao(TConjunto a, TConjunto b);
		bool estacontido(TConjunto a){return a.contem(*this);};
		bool contem(TConjunto a);
		bool pertence(float n){return obterIndice(n)!=-1;};
		void inserir(float n);
		void remover(float n);
};

int TConjunto::obterIndice(float n){
	bool achou=false;
	int i=0;
	while (!achou && i<q)
		if (a[i] == n)achou = true;
		else i++;
	return achou?i:-1;
}

void TConjunto::inserir(float n){
	if (!pertence(n)){	
		a[q]=n;
		q++;	
	}
}
void TConjunto::remover(float n){
	int pst = obterIndice(n);
	if (pst!=-1){
		a[pst] = a[q-1];
		q--;	
	}
}

void TConjunto::ler(){
	int N;
	cout << "entre com a quantidade de numeros a digitar:";
	cin >> N;
	q = 0;
	for(int i=0; i<N; i++){
		float b;
		cout << "x=";
		cin >> b;
		inserir(b);		
	}
}
void TConjunto::mostrar(){
	cout << "{ ";
	for(int i=0; i<q; i++)cout << a[i] << " ";
	cout << "}" << endl;
}
void TConjunto::uniao(TConjunto a, TConjunto b){
	q = 0;
	for(int i=0;i<a.q;i++)inserir(a.a[i]);
	for(int i=0;i<b.q;i++)inserir(b.a[i]);
}
void TConjunto::intersecao(TConjunto a, TConjunto b){
	q = 0;
	for(int i=0;i<a.q;i++)
		if (b.pertence(a.a[i]))inserir(a.a[i]);
}
void TConjunto::subtracao(TConjunto a, TConjunto b){
	q = 0;
	for(int i=0;i<a.q;i++)
		if (!b.pertence(a.a[i]))inserir(a.a[i]);
}
bool TConjunto::contem(TConjunto a){
	bool ok=true;
	for(int i=0;i<a.q && ok;i++)
		if (!pertence(a.a[i]))ok = false;
	return ok;	
}

int main(){
	TConjunto a,b,c,d,e;
	int x;
	a.ler();
	b.ler();
	c.uniao(a,b);
	c.mostrar();
	d.intersecao(a,b);
	d.mostrar();
	cout << "d esta contido em a:" << d.estacontido(a) << endl;
	cout << "a contem d:" << a.contem(d) << endl;
	cout << "d esta contido em a:" << d.estacontido(a) << endl;
	cout << "c contem a:" << c.contem(a) << endl;
	cout << "c contem b:" << c.contem(b) << endl;
	cout << "a contem b:" << a.contem(b) << endl;
	cout << "a esta contido em b:" << a.estacontido(b) << endl;
	e.subtracao(a,b);
	e.mostrar();
	do{
		cout << "entre com um valor inteiro:";cin >> x;
		cout << x << " pertence ao conjunto A: " << a.pertence(x) << endl;
	}while (x>0);
	return 0;
}

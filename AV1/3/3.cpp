#include<iostream>

using namespace std;

#define max 100

class TConjunto{
	private:
		double a[max];
		int q;
		int obterIndice(double x);
	public:
		void ler();
		void mostrar();
		void uniao(TConjunto a, TConjunto b);
		void intersecao(TConjunto a, TConjunto b);
		void subtracao(TConjunto a, TConjunto b);
		bool estacontido(TConjunto a){return a.contem(*this);};
		bool contem(TConjunto a);
		bool pertence(double x){return obterIndice(x)!=-1;};
		void inserir(double x);
		void remover(double x);
};

int TConjunto::obterIndice(double x){
	bool achou=false;	int i=0;
	while (!achou && i<q)a[i]==x?achou = true : i++;
	return achou?i:-1;
}

void TConjunto::inserir(double x){
	if (!pertence(x)){	
		a[q]=x;
		q++;	
	}
}
void TConjunto::remover(double x){
	int pst = obterIndice(x);
	if (pst!=-1){
		a[pst] = a[q-1];
		q--;	
	}
}

void TConjunto::ler(){
	int N;	cin >> N;	q=0;
	for(int i=0; i<N; i++){
		double b;
		cin >> b;
		inserir(b);		
	}
}

void pulaLinha(){cout << endl;}

void TConjunto::mostrar(){
	for(int i=0; i<q; i++)cout << a[i] << " ";
	pulaLinha();
}
void TConjunto::uniao(TConjunto a, TConjunto b){
	q=0;
	for(int i=0;i<a.q;i++)inserir(a.a[i]);
	for(int i=0;i<b.q;i++)inserir(b.a[i]);
}
void TConjunto::intersecao(TConjunto a, TConjunto b){
	q=0;
	for(int i=0;i<a.q;i++)if (b.pertence(a.a[i]))inserir(a.a[i]);
}
void TConjunto::subtracao(TConjunto a, TConjunto b){
	q=0;
	for(int i=0;i<a.q;i++)if (!b.pertence(a.a[i]))inserir(a.a[i]);
}
bool TConjunto::contem(TConjunto a){
	bool C=true;
	for(int i=0;i<a.q && C;i++)if (!pertence(a.a[i]))C = false;
	return C;	
}

int main(){
	TConjunto a,b,c,d,e;
	int x;
	a.ler();
	b.ler();
	c.uniao(a,b);
	cout << "a UNIAO b = ";
	c.mostrar();
	d.intersecao(a,b);
	cout << "a INTERSECAO b = ";
	d.mostrar();
	cout << "d esta contido em a: " << (d.estacontido(a)?"sim":"nao") << endl;
	cout << "a contem d: " << (a.contem(d)?"sim":"nao") << endl;
	cout << "c esta contido em a: " << (c.estacontido(a)?"sim":"nao") << endl;
	cout << "c contem a: " << (c.contem(a)?"sim":"nao") << endl;
	cout << "c contem b: " << (c.contem(b)?"sim":"nao") << endl;
	cout << "a contem b: " << (a.contem(b)?"sim":"nao") << endl;
	cout << "a esta contido em b: " << (a.estacontido(b)?"sim":"nao") << endl;
	cout << "a - b = ";
	e.subtracao(a,b);
	e.mostrar();
	cin >> x;
	while(x>0){
		cout << x << " pertence ao conjunto A: " << (a.pertence(x)?"sim":"nao") << endl;
		cin >> x;
	}
	return 0;
}

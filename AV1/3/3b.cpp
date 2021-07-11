#include<iostream>

using namespace std;

#define max 100

class TConjunto{
    private:
        double a[max],ca[max];
        int q,qtd=0;
		int obterIndice(double x);
    public:
        void ler();
        void mostrar();
        void uniao(TConjunto a, TConjunto b);
		void intersecao(TConjunto a, TConjunto b);
		void subtracao(TConjunto a, TConjunto b);
        int existe(double  x, TConjunto a);
        void remover();
        void ordenar();
		bool estacontido(TConjunto a){return a.contem(a);};
		bool contem(TConjunto a);
		bool pertence(double x);
};

int TConjunto::obterIndice(double x){
	bool achou=false;	int i=0;
	while (!achou && i<q)a[i]==x?achou = true : i++;
	return achou?i:-1;
}

bool TConjunto::pertence(double x){
	TConjunto a;
	return existe(x,a)!=-1;
}

int TConjunto::existe(double x, TConjunto a){
    int s=1;
   	for(int i=0;i<a.qtd;i++){
	   	if(a.ca[i]==x) s= -1;
	   }
	 return s;
}

int comparar(const void * a, const void * b){
    const double* x = (double*) a;
	const double* y = (double*) b;

	if (*x < *y)return 1;
	else if (*x > *y)return -1;

	return 0;
}


void TConjunto::ordenar (){qsort(a, q, sizeof(double), comparar);}

void TConjunto::remover(){
	int j=0;
    ordenar();
	for(int i=0;i<qtd-1;i++){
		if(a[i]!=a[i+1]){
			ca[j]=a[i];
			j++;
		}
	}
	ca[j]=a[qtd-1];
	q=j+1;
}


void TConjunto::ler(){
    cin >> qtd;
    double n;
	for(int i=0;i<qtd; i++){
        cin >> a[i];
    }
    ordenar();
    remover();
}

void TConjunto::uniao(TConjunto a, TConjunto b){
	double aju;
	for(int i=0;i<a.q;i++)ca[i]=a.ca[i];
	q=a.q;
	for(int i=0;i<b.qtd;i++){
		aju=b.ca[i];
		if(existe(aju,a)>-1){
			ca[q]=b.ca[i];
			q++;
		}
	}
}

void TConjunto::intersecao(TConjunto a, TConjunto b){
	double j;
	q=0;
	for(int i=0;i<a.qtd;i++)
        if (existe(a.ca[i],b)==-1){
            ca[q]=a.ca[i];
            q++;
        }
}

void TConjunto::subtracao(TConjunto a, TConjunto b){
	double j;
	q=0;
	for(int i=0;i<a.q;i++){
		j=a.ca[i];
		if(existe(j,b)==1){
			ca[q]=a.ca[i];
			q++;
		}
	}
}

void TConjunto::mostrar(){
	for(int i=0;i<q;i++){
		if(i+1>=q){
            cout << ca[i];
			break;
		}else{cout << ca[i] << " ";}
    }
    cout << endl;
}

bool TConjunto::contem(TConjunto a){
	bool C=true;
	double j;
	j=a.q;
	for(int i=0;i<a.q && C;i++)
		if (!existe(j,a))C = false;
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
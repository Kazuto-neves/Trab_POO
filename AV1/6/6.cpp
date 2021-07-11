#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

#define max 100

class TVet{
    private:
        double num[max],M,m;
        int q=0;
    public:
        void ler();
        double maior();
        double menor();
        void ordernar();
        double mediaEx();
};

void TVet::ler(){
    cin >> q;
    for(int i=0;i<q;i++){cin >> num[i];}
    ordernar();
}

void TVet::ordernar(){
    double auxiliar=0;
	for(int i=0;i<q;i++)
	   for(int j=0;j<q;j++)
	   	 if(num[i]<num[j]){
	   		auxiliar=num[i];
			num[i]=num[j];
			num[j]=auxiliar;
        }
}

double TVet::maior(){
    M=num[q-1];
    return M;}

double TVet::menor(){
    m=num[0];
    return m;}

double TVet::mediaEx(){
    int y=0;
	double soma=0;
	for(int x=0;x<q-1;x++){
		if(num[x]!=M && num[x]!=m){
			    soma+=num[x];
			    y+=1;
        }
    }
    return soma/y;
}

int main(){
    TVet v;
	v.ler();
    cout << fixed << setprecision(2);
	cout << "Maior: "<< v.maior() << endl;
	cout << "Menor: "<< v.menor() << endl;
	cout << "Media sem extremos: "<< v.mediaEx() << endl;
        return 0;
    }
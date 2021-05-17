#include <iostream>
#include <iomanip>
#include <math.h>

using namespace std;

#define max 100

class TVet{
    private:
        float num[max];
        int q;
    public:
        void ler();
        float maior();
        float menor();
        float ordenar();
        float mediaEx();
};

void TVet::ler(){
    float n;
    for(int i;i<=100;i++){
        cin >> num[i];
        if (num[i]==0) break;
        q++;
    }
    //if(num[q]==0)q-=1;
}

float TVet::maior(){
    float m;  m=num[0];
    for (int i=0;i<q;i++){
        if(m<num[i])m=num[i];
        else m;
    }
    return m;
}

float TVet::menor(){
    float m;  m=num[0];
    for (int i=0;i<=q;i++){
        if(m>num[i])m=num[i];
        else m;
    }
    return m;
}

int main(){
    TVet v;
	v.ler();
    cout << fixed << setprecision(2);
	cout << "Maior:"<< v.maior() << endl;
	cout << "Menor:"<< v.menor() << endl;
	//cout << "Media sem extremos:"<< v.mediaEx() << endl;
        return 0;
    }
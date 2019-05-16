#include <iostream>
#include <queue>
using namespace std;

void extender(int n, queue<int> fila);
void imprimir(queue<int> fila);

const int QUANTIDADE_POSSIBILIDADES = 3;
int possibilidades[QUANTIDADE_POSSIBILIDADES] = {1,3,4};

int main(){
	int n;
	while(true){
		cin >> n;
		if(n<1)
			break;

		queue<int> fila;
		extender(n, fila);
	}
}

void extender(int n, queue<int> fila){
	int diferenca;
	for (int i = 0; i < QUANTIDADE_POSSIBILIDADES; i++){
		diferenca = n - possibilidades[i];
		if(diferenca > 0){
			queue<int> copia(fila);
			copia.push(possibilidades[i]);
			extender(diferenca, copia);
		}
		else if(diferenca==0){
			fila.push(possibilidades[i]);
			imprimir(fila);
		}
	}

}

void imprimir(queue<int> fila){
	int total = 0;
	while(!fila.empty()){
		if(total==0)
			cout << fila.front();
		else
			cout << " + " << fila.front();

		total += fila.front();
		fila.pop();
	}
	cout << " = " << total << endl;
}

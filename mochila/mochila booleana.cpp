#include <iostream>
using namespace std;

int *peso;
int *valor;

int mochila(int indice, int capacidade){
	if(indice < 0 || capacidade == 0)
		return 0;

	int ganhoAtual, inclusivo, exclusivo;
	if(peso[indice] > capacidade)
		ganhoAtual = mochila(indice - 1, capacidade);
	else{
		exclusivo = mochila(indice - 1, capacidade);
		inclusivo = mochila(indice - 1, capacidade - peso[indice])
		 + valor[indice];
		ganhoAtual = max(inclusivo, exclusivo);
	}
	return ganhoAtual;
}

int main(){
	int quantidade, capacidade, caso = 1;
	while(true){
		cin >> quantidade;
		cin >> capacidade;
		if(quantidade == 0 && capacidade == 0)
			break;

		peso = new int[quantidade];
		valor = new int[quantidade];

		for(int indice = 0; indice < quantidade; indice++){
			cin >> peso[indice];
			cin >> valor[indice];
		}
		cout << "Caso " << caso++ << ": "; 
		cout << mochila(quantidade-1, capacidade) << endl;		
	}
}
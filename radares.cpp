#include <iostream>
#include <stdlib.h>
using namespace std;

int minDistancia;
int radares;
int *posicoes;
int *lucros;
bool *selecao;

bool temDistanciaSuficiente(int i){
	for(int j = i + 1; j < radares; j++){
		if(selecao[j] && abs(posicoes[i] - posicoes[j]) < minDistancia)
			return false;
	}
	return true;
}

int lucrar(int i){	
	int exclusivo = 0, inclusivo = 0;
	if(i < 0){
		return 0;
	}
	if(i == radares - 1){
		selecao[i] = true;
		inclusivo = lucros[i] + lucrar(i-1);
		selecao[i] = false;
		exclusivo =  lucrar(i-1);
		return max(inclusivo, exclusivo);
	}
	else{
		if(temDistanciaSuficiente(i)){
			selecao[i] = true;
			inclusivo = lucros[i] + lucrar(i-1);
		}
		else
			inclusivo = 0;
		selecao[i] = false;
		exclusivo = lucrar(i-1);
		return max(inclusivo, exclusivo);
	}
}


int main(){
	int casos;
	cin >> casos;
	for(;casos > 0; casos--){
		cin >> radares;
		cin >> minDistancia;
		cout << "radares: " << radares << " distancia mínima: " << minDistancia << endl;

		posicoes = (int*) malloc(sizeof(int) * radares);
		lucros = (int*) malloc(sizeof(int) * radares);
		selecao = (bool*) malloc(sizeof(bool) * radares);

		cout << "posicoes: ";
		for(int i = 0; i < radares; i++){
			cin >> posicoes[i];
			cout << posicoes[i] << " ";
		}
		cout << endl;

		cout << "lucros: ";
		for(int i = 0; i < radares; i++){
			cin >> lucros[i];
			cout << lucros[i] << " ";
		}
		cout << endl;
		int lucro = lucrar(radares-1);
		cout << "lucro: " << lucro << endl << endl;
	}
}

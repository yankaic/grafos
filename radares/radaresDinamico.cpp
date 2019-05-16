#include <iostream>
#include <stdlib.h>
using namespace std;

int minDistancia;
int radares;
int *posicoes;
int *lucros;
bool *selecao;
int** memoria = new int*[2];

bool temDistanciaSuficiente(int i){
	for(int j = i + 1; j < radares; j++)
		if(selecao[j] && abs(posicoes[i] - posicoes[j]) < minDistancia)
			return false;
	return true;
}

int lucrar(int i){	
	int exclusivo = 0, inclusivo = 0;
	if(i < 0)
		return 0;
	else{
		if(temDistanciaSuficiente(i)){
			selecao[i] = true;
			if(memoria[selecao[i]][i]!=-1)
				inclusivo = memoria[selecao[i]][i];
			else{
				inclusivo = lucros[i] + lucrar(i-1);
				memoria[selecao[i]][i] = inclusivo;
			}
		}
		else
			inclusivo = 0;

		selecao[i] = false;
		if(memoria[selecao[i]][i]!=-1)
			exclusivo = memoria[selecao[i]][i];
		else{
			exclusivo = lucrar(i-1);
			memoria[selecao[i]][i] = exclusivo;
		}
		return max(inclusivo, exclusivo);
	}
}

void zerarMemoria(){
	memoria[0] = new int[radares];
	memoria[1] = new int[radares];

	for(int i=0; i < radares; i++){
		memoria[0][i] = -1;
		memoria[1][i] = -1;
	}
}


int main(){
	int casos;
	cin >> casos;
	for(;casos > 0; casos--){
		cin >> radares;
		cin >> minDistancia;
		
		posicoes = new int[radares];
		lucros = new int[radares];
		selecao = new bool[radares];		
		zerarMemoria();

		for(int i = 0; i < radares; i++)
			cin >> posicoes[i];

		for(int i = 0; i < radares; i++)
			cin >> lucros[i];
		
		cout << lucrar(radares-1) << "\n";
	}
}

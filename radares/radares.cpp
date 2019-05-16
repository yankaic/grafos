#include <iostream>
#include <stdlib.h>
using namespace std;

int distanciaMinima;
int quantidadeRadares;
int *posicao;
int *valor;
bool *selecionado;
int interacoes = 0;

bool temDistanciaSuficiente(int indice);
int distancia(int a, int b);

int lucro(int indice){	
	interacoes++;
	int exclusivo = 0, inclusivo = 0;
	if(indice == quantidadeRadares)
		return 0;

	if(temDistanciaSuficiente(indice)){
		selecionado[indice] = true;
		inclusivo = valor[indice] + lucro(indice+1);
	}

	selecionado[indice] = false;
	exclusivo = lucro(indice+1);
	return max(inclusivo, exclusivo);
}

int main(){
	int casos;
	cin >> casos;
	for(;casos > 0; casos--){
		cin >> quantidadeRadares;
		cin >> distanciaMinima;
		
		posicao = new int[quantidadeRadares];
		valor = new int[quantidadeRadares];
		selecionado = new bool[quantidadeRadares];

		for(int indice = 0; indice < quantidadeRadares; indice++)
			cin >> posicao[indice];

		for(int indice = 0; indice < quantidadeRadares; indice++)
			cin >> valor[indice];
		
		cout << lucro(0) << endl;		
		cout << "interacoes: " << interacoes << endl;
	}
}

int distancia(int a, int b){
	return abs(a-b);
}

bool temDistanciaSuficiente(int indice){
	for(int anterior = indice-1; anterior >= 0; anterior--){
		if(selecionado[anterior])
			if (distancia(posicao[indice], posicao[anterior]) < distanciaMinima)
				return false;
	}
	return true;
}


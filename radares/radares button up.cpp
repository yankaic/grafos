#include <iostream>
#include <stdlib.h>
using namespace std;

int distanciaMinima;
int quantidadeRadares;
int *posicao;
int *valor;
int *memoria;
int interacoes = 0;

int anteriorPossivel(int indice);
int distancia(int a, int b);

int lucro(){	
	interacoes = 0;
	for(int indice = 0; indice < quantidadeRadares; indice++, interacoes++){
		int anterior = indice == 0 ? 0 : memoria[indice-1];
		int anterior_sem_conflito = anteriorPossivel(indice);
		anterior_sem_conflito += valor[indice];
		memoria[indice] = max(anterior, anterior_sem_conflito);
	}
	return memoria[quantidadeRadares-1];
}

int main(){
	int casos;
	cin >> casos;
	for(;casos > 0; casos--){
		cin >> quantidadeRadares;
		cin >> distanciaMinima;
		
		posicao = new int[quantidadeRadares];
		valor = new int[quantidadeRadares];
		memoria = new int[quantidadeRadares];
		int *tem_radar = new int[1000 * 1000 + 10];
		int location;

		for(int indice = 0; indice < quantidadeRadares; indice++){
			cin >> location;
			cout << "indice: " << indice << endl;
			cout << "valor: " << location << endl;
			cout << "tem_radar: " << tem_radar[location] -1 << endl << endl;
			
		}

		for(int indice = 0; indice < quantidadeRadares; indice++)
			cin >> valor[indice];
		cout << "--------------------------------------" << endl << endl;
		
		//cout << lucro() << endl;		
		//cout << "interacoes: " << interacoes << endl << endl;
	}
}

int distancia(int a, int b){
	return abs(a-b);
}

int anteriorPossivel(int indice){
	for(int anterior = indice-1; anterior >= 0; anterior--, interacoes++){
			if (distancia(posicao[indice], posicao[anterior]) >= distanciaMinima)
				return memoria[anterior];
	}
	return 0;
}


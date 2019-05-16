#include <iostream>
using namespace std;

int *peso;
int *valor;
int **memoria;

int mochila(int indice, int capacidade){
	if(indice < 0 || capacidade == 0)
		return 0;

	if(memoria[indice][capacidade-1] != -1)
		return memoria[indice][capacidade-1];

	int ganhoAtual, inclusivo, exclusivo;
	if(peso[indice] > capacidade)
		ganhoAtual = mochila(indice - 1, capacidade);
	else{
		exclusivo = mochila(indice - 1, capacidade);
		inclusivo = mochila(indice - 1, capacidade - peso[indice])
		 + valor[indice];
		ganhoAtual = max(inclusivo, exclusivo);
	}
	memoria[indice][capacidade-1] = ganhoAtual;
	return ganhoAtual;
}

void zerarMemoria(int linhas, int colunas){
	memoria = new int*[linhas];
	for(int linha = 0; linha < linhas; linha++){
		memoria[linha] = new int[colunas];

		for(int coluna = 0; coluna < colunas; coluna++)
			memoria[linha][coluna] = -1;
	}
}
void printArray(int **array, int n_rows, int n_cols);

int main(){
	int quantidade, capacidade, caso = 1;
	while(true){
		cin >> quantidade;
		cin >> capacidade;
		if(quantidade == 0 && capacidade == 0)
			break;

		peso = new int[quantidade];
		valor = new int[quantidade];
		zerarMemoria(quantidade, capacidade);

		for(int indice = 0; indice < quantidade; indice++){
			cin >> peso[indice];
			cin >> valor[indice];
		}
		cout << "Caso " << caso++ << ": "; 
		cout << mochila(quantidade-1, capacidade) << endl;	

		//printArray(memoria, quantidade, capacidade);	
	}
}

void printArray(int **array, int n_rows, int n_cols){
	for(int row = 0; row < n_rows; row++){
		for(int col = 0; col < n_cols; col++){
			if(col==0)
				cout << "[";
			else 
				cout << ", ";
			cout << array[row][col];
		}
		cout << "]" << endl;
	}
}
#include <iostream>
using namespace std;

int *conjunto;
int inicio, sub_inicio;

int melhor_sub(int indice){
	if(indice < 0)
		return 0;

	int anteriores = conjunto[indice] + melhor_sub(indice -1);
	if(conjunto[indice] >= anteriores){
		sub_inicio = indice;
		return conjunto[indice];
	}
	return anteriores;
}

int main(){
	//ler o tamanho do conjunto. Caso seja menor ou igual a zero, não leia os itens.
	int tamanho;
	cin >> tamanho;

	//alocando e fazendo a leitura dos itens do conjunto
	conjunto = new int[tamanho];
	for(int i = 0; i < tamanho; i++)
		cin >> conjunto[i];

	 int maior = -9999999, fim, sub_somatorio;
	for(int indice = 0; indice < tamanho; indice++){
		sub_somatorio = melhor_sub(indice);
		if(sub_somatorio >= maior){
			maior = sub_somatorio;
			fim = indice;
			inicio = sub_inicio;
		}
	}

	//imprimindo
	for(int indice = inicio; indice <= fim; indice++)
		cout << '.' << conjunto[indice];
	cout << endl;

}
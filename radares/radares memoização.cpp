#include <iostream>
using namespace std;

int distanciaMinima;
int quantidadeRadares;
int *posicao;
int *valor;
bool *selecionado;
int** memoria = new int*[2];
int lucroAtual;
int interacoes = 0;

const int APTO = 1;
const int INAPTO = 0;
//todas as direitas vem igual, ou não vem

bool temDistanciaSuficiente(int indice);
int distancia(int a, int b);
void zerarMemoria();

int lucro(int indice){	
	interacoes++;
	int exclusivo = 0, inclusivo = 0;
	bool aptidao = false;
	if(indice == quantidadeRadares)
		return 0;

	if(temDistanciaSuficiente(indice)){
		if(memoria[APTO][indice] != -1)
			return memoria[APTO][indice];
		else{			
			selecionado[indice] = true;
			inclusivo = valor[indice] + lucro(indice + 1);
		}		
		aptidao = true;
	}
	else if (memoria[INAPTO][indice] != -1)
		return memoria[INAPTO][indice];

	selecionado[indice] = false;
	exclusivo = lucro(indice + 1);
	lucroAtual = max(inclusivo,exclusivo);	
	memoria[aptidao][indice] = lucroAtual;
	return lucroAtual;
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

int main(){
	int casos;
	cin >> casos;
	for(;casos > 0; casos--){
		cin >> quantidadeRadares;
		cin >> distanciaMinima;
		
		posicao = new int[quantidadeRadares];
		valor = new int[quantidadeRadares];
		selecionado = new bool[quantidadeRadares];
		zerarMemoria();

		for(int indice = 0; indice < quantidadeRadares; indice++)
			cin >> posicao[indice];

		for(int indice = 0; indice < quantidadeRadares; indice++)
			cin >> valor[indice];
		
		cout << lucro(0) << endl;
		cout << "interacoes: " << interacoes << endl;
		//printArray(memoria, 2, quantidadeRadares);
	}
}

int distancia(int a, int b){
	int distancia = a - b;
	if(distancia < 0)
		return - distancia;
	return distancia;
}

bool temDistanciaSuficiente(int indice){
	for(int anterior = indice -1; anterior >= 0; anterior--){
		if(selecionado[anterior])
			return distancia(posicao[indice], posicao[anterior]) >= distanciaMinima;
	}
	return true;
}

void zerarMemoria(){
	memoria[INAPTO] = new int[quantidadeRadares];	// para inaptos
	memoria[APTO] = new int[quantidadeRadares]; 	// para aptos

	for(int indice = 0; indice < quantidadeRadares; indice++){
		memoria[INAPTO][indice] = -1;
		memoria[APTO][indice] = -1;
	}
}


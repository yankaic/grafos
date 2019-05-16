#include<iostream>
#include<vector>
using namespace std;

int **adjacencia; //matriz de adjacencia com peso nas arestas
int *selecionados;
int vertices;

struct edge{
	int origem;
	int destino;
	int valor;
};

edge menorAresta(){
	edge menor = {999999,999999,999999999};
	for(int origem = 0; origem < vertices; origem++){
		if(selecionados[origem]){
			for(int destino = 0; destino < vertices; destino++){
				if(adjacencia[origem][destino] && adjacencia[origem][destino] < menor.valor){
					menor.origem = origem;
					menor.destino = destino;
					menor.valor = adjacencia[origem][destino];
				}
			}
		}
	}
}

int selecionarFilhos(int vertice){
	int filhos = 0;
	for(int filho = 0; filho < vertices; filho++){
		if(adjacencia[vertice][filho]){
			selecionados[filho] = true;
			filhos++;
		}
	}
	return filhos;
}

//rever isso
void removerOrigens(int vertice, int excessao){
	for(int origem = 0; origem < vertices; origem++){
		if(origem != excessao)
			adjacencia[origem][vertice] = 0;
	}
}

int prim(int vertice){
	int filhos = selecionarFilhos(vertice);
	if(!filhos)
		return 0;

	edge aresta = menorAresta();
}

int main(){
	int n, a, b, valor;
	int valor_total = 0, valor_gasto = 0;

	while(true){
		cin >> vertices;
		cin >> n;

		if(vertices == 0 && n == 0)
			break;

		adjacencia = new int*[vertices];
		for(int i = 0; i < vertices; i++)
			adjacencia[i] = new int[vertices];

		while(n--){
			cin >> a;
			cin >> b;
			cin >> valor;

			adjacencia[a][b] = valor;
			adjacencia[b][a] = valor;
		}
	}
}
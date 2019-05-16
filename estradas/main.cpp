#include<iostream>
#include<vector>
#include<algorithm>
#include<string.h>
using namespace std;

struct edge{
	int origem;
	int destino;
	int peso;	

	edge(int origem, int destino, int peso){
		this->origem = origem;
		this->destino = destino;
		this->peso = peso;
	}
	edge(){
		origem = -1;
		destino = -1;
		peso = 0;
	}
};

int valor_total, valor_gasto;
int *conectividade;
vector<edge> arestas;

bool operator<(edge origem, edge destino){
	return origem.peso < destino.peso;
}

int buscar(int vertice){
	if(conectividade[vertice] == -1)
		return vertice;
	return buscar(conectividade[vertice]);
}

void conectar(edge aresta){
	valor_gasto += aresta.peso;
	int cauda_a = buscar(aresta.origem);
	int cauda_b = buscar(aresta.destino);
	conectividade[cauda_a] = cauda_b;	
}

bool conecta_componentes_distintos(edge aresta){
	int cauda_a = buscar(aresta.origem);
	int cauda_b = buscar(aresta.destino);
	return cauda_a != cauda_b;
}


void kruskal(){
	sort(arestas.begin(), arestas.end());

	for(int i = 0; i < arestas.size(); i++){
		if(conecta_componentes_distintos(arestas[i])){
			conectar(arestas[i]);
		}
	}
}

void imprimir(int * vetor, int n){
	for(int i = 0; i < n; i++){
		cout << '.' << vetor[i];
	}
	cout << endl;
}

int main(){
	int vertices, n;

	while(true){
		cin >> vertices;
		cin >> n;

		if(vertices == 0 && n == 0)
			break;

		valor_total = 0;
		valor_gasto = 0;
		conectividade = new int[vertices];
		memset(conectividade, -1, sizeof(int) * vertices);
		arestas.clear();

		while(n--){
			edge aresta;
			cin >> aresta.origem;
			cin >> aresta.destino;
			cin >> aresta.peso;

			arestas.push_back(aresta);
			valor_total += aresta.peso;
		}
		kruskal();

		cout << (valor_total - valor_gasto) << endl;
	}

	edge aresta1, aresta2;
	aresta1 < aresta2;
}
#include <iostream>
#include <vector>
using namespace std;

int gasto;

struct edge{
	int startpoint;
	int endpoint;
	int value;

	edge(int endpoint, int value){
		this->endpoint = endpoint;
		this->value = value;
	}	

	edge(int startpoint, int endpoint, int value){
		this->startpoint = startpoint;
		this->endpoint = endpoint;
		this->value = value;
	}	
};

typedef vector< vector<edge> > graph;
void imprimir(graph adjacencia);

graph grafo, arvore_minima;
bool *selecionados;

edge menorAresta(){
	edge menor(-1, -1, 999999999);
	for(int vertice = 0; vertice < grafo.size(); vertice++){
		if(selecionados[vertice]){
			for(int i = 0; i < grafo[vertice].size(); i++){
				edge aresta = grafo[vertice][i];
				if(!selecionados[aresta.endpoint] && aresta.value < menor.value)
					menor = aresta;				
			}
		}
	}
	return menor;
}

void add(edge aresta){
	edge invertida(aresta.endpoint, aresta.startpoint, aresta.value);
	grafo[aresta.startpoint].push_back(aresta);
	grafo[invertida.startpoint].push_back(invertida);
	gasto += aresta.value;
}

void prim(int vertice){
	selecionados[vertice] = true;
	edge aresta = menorAresta();
	if(aresta.startpoint == -1)
		return;

	add(aresta);
	return prim(aresta.endpoint);
}

void prim(){	
	int n = grafo.size();
	selecionados = new bool[n];
	graph resultante;

	while(n--){
		resultante.push_back(vector<edge>());
		selecionados[n] = false;
	}
	selecionados[0] = false;

	prim(0);
}

int main(){
	int vertices, n, a, b, peso, valor_total = 0;
	while(true){
		cin >> vertices;
		cin >> n;

		if(vertices == 0 && n == 0)
			break;

		valor_total = 0;
		gasto = 0;
		grafo.clear();
		for(int i = 0; i < vertices; i++)
			grafo.push_back(vector<edge>());

		while(n--){
			cin >> a;
			cin >> b;
			cin >> peso;
			grafo[a].push_back(edge(a, b, peso));
			grafo[b].push_back(edge(b, a, peso));
			valor_total += peso;
		}
		prim();
		cout << (valor_total - gasto) << endl;
	}
}

void imprimir(graph adjacencia){
	for(int vertice = 0; vertice < adjacencia.size(); vertice++){
		cout << vertice << " ->";
		for(int i = 0; i < adjacencia[vertice].size(); i++){
			edge aresta = adjacencia[vertice][i];
			//cout << "." << aresta.endpoint << " (" << aresta.value << ") ";
			cout << " ." << aresta.endpoint;
		}
		cout << endl;
	}
}
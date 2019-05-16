#include <iostream>
#include <vector>
#include <stack>
using namespace std;

struct Vertice{
	bool visitado;
	bool visto;
	int distancia;
	int pai;
	Vertice(): 
		visitado(false), 
		visto(false),
		distancia(0),
		pai(-1) {}

};

struct Aresta{
	int origem;
	int destino;
	int peso;
	Aresta(int origem, int destino, int peso):
		origem(origem),
		destino(destino),
		peso(peso) {}
};

typedef vector< vector<Aresta> > Grafo;

Grafo adjacencia;
Grafo arvore;
vector<Vertice> info;
vector<int> proximos;

stack<int> pilha;


int extrairProximo(){
	int menor_distancia = 999999, indice;
	for(int i = 0; i < proximos.size(); i++){
		int vertice = proximos[i];
		
		if(info[vertice].distancia < menor_distancia){
			menor_distancia = info[vertice].distancia;
			indice = i;
		}
	}
	int proximo = proximos[indice];
	proximos.erase(proximos.begin() + indice);
	return proximo;
}

void relaxa(Aresta aresta){
	int distanciaCandidata = info[aresta.origem].distancia + aresta.peso;
	bool tem_rota_mais_curta = distanciaCandidata < info[aresta.destino].distancia;
	if(!info[aresta.destino].visto || tem_rota_mais_curta){
		info[aresta.destino].distancia = distanciaCandidata;
		info[aresta.destino].pai = aresta.origem;
		arvore[aresta.destino].clear();
		arvore[aresta.destino].push_back(Aresta(aresta.destino, aresta.origem, aresta.peso));
	}
}

void dijkstra(int vertice){
	for(int indice = 0; indice < adjacencia[vertice].size(); indice++){
		Aresta aresta = adjacencia[vertice][indice];
		int vizinho = aresta.destino;

		if(!info[vizinho].visitado){
			relaxa(aresta);
			if(!info[vizinho].visto){
				proximos.push_back(vizinho);
				info[vizinho].visto = true;
			}
		}
	}
	if(!proximos.empty()){
		int proximo = extrairProximo();
		dijkstra(proximo);
	}
}

void imprimir(Grafo grafo){
	for(int vertice = 0; vertice < grafo.size(); vertice++){
		cout << (char) (vertice + 'a') << " ->";
		for(int i = 0; i < grafo[vertice].size(); i++){
			Aresta aresta = grafo[vertice][i];
			cout << " ." << (char) (aresta.destino + 'a');
		}
		cout << endl;
	}
}

void backtrack(int vertice){
	pilha.push(vertice);
	if(info[vertice].pai != -1)
		backtrack(info[vertice].pai);
}

void imprimirRotas(){
	for(int vertice = 0; vertice < adjacencia.size(); vertice++){
		backtrack(vertice);
		cout << (char) ('a' + vertice) << ": ";

		while(!pilha.empty()){
			cout << " ." << (char) ('a'+ pilha.top());
			pilha.pop();
		}
		cout << endl;
	}
}

int main(){
	int quantidadeVertices;
  int quantidadeArestas;
   
  cin >> quantidadeVertices >> quantidadeArestas;     
  for (int i = 0; i < quantidadeVertices; i++) {
    adjacencia.push_back(vector<Aresta>());
    arvore.push_back(vector<Aresta>());
    info.push_back(Vertice());
  }
    
  char uChar, vChar;
  int u, v, distancia;  
  while(quantidadeArestas--){
		cin >> uChar >> vChar;
		cin >> distancia;
		u = uChar - 'a';
		v = vChar - 'a';

		adjacencia[u].push_back(Aresta(u, v, distancia));
		adjacencia[v].push_back(Aresta(v, u, distancia));
  }
  char fonteC;
  cin >> fonteC;
  int fonte = fonteC - 'a';

  imprimir(adjacencia);
  info[fonte].visitado = true;
  dijkstra(fonte);
  cout << endl;
  imprimir(arvore);
  cout << endl;
  imprimirRotas();
 }







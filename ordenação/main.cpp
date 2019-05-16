#include <iostream>
#include <vector>
#include <stack>
#include <string.h>
using namespace std;

bool *visitados;
stack<int> concluidos; //pilha de inteiros
vector< vector<int> > adjacencia;


void buscaProfundidade(int vertice){
	vector<int> vizinhos = adjacencia[vertice];
	visitados[vertice] = true;
	for(int i = 0; i < vizinhos.size(); i++){
		int filho = vizinhos[i];
		if(!visitados[filho])
			buscaProfundidade(filho);
	}
	concluidos.push(vertice);
}

void ordenacao_topologica(){
	int quantidade_vertices = adjacencia.size();			//verifica a quantidade de vertices
	visitados = new bool[quantidade_vertices];				//criando o vetor com n posĩções
	//memset(visitados, 0, sizeof(bool) * quantidade_vertices);	//colocando em todas as posições o valor 0
	//adjacencia = vector< vector<int> >(quantidade_vertices);	// criando uma lista (de lista) de n elementos.

	for(int vertice = 0; vertice < quantidade_vertices; vertice++)
		if(!visitados[vertice])
			buscaProfundidade(vertice);
}
int main(){
	int quantidadeVertices;
  int quantidadeArestas;
   
  cin >> quantidadeVertices >> quantidadeArestas;     
  for (int i = 0; i < quantidadeVertices; i++) 
    adjacencia.push_back(vector<int>());
    
  char uChar, vChar;
  int u, v, distancia;  
  while(quantidadeArestas--){
		cin >> uChar >> vChar;
		//cin >> distancia;
		u = uChar - 'a';
		v = vChar - 'a';

		adjacencia[u].push_back(v);
		//adjacencia[v].push_back(u);
  }

  ordenacao_topologica();

  while(!concluidos.empty()){
  	cout << " ." << (char) ('a'+ concluidos.top());
  	//out << concluidos.top() << endl;
  	concluidos.pop();
  }
  cout << endl;
 }



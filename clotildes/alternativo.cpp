#include <iostream>
#include <queue>
#include <vector>
using namespace std;

#define CANAL_MAXIMO 100001

struct vertice{
	int canal;
	int nivel;
};

bool visitados[CANAL_MAXIMO];
queue<vertice> proximos; // fila de próximos

vector<vertice> vizinhos(vertice v){
	vector<vertice> lista_vizinhos; // lista de adjacência

	vertice vizinho;
	vizinho.nivel = v.nivel + 1;

	vizinho.canal = v.canal + 1;
	if(vizinho.canal <= CANAL_MAXIMO /*&& !visitados[vizinho]*/)
		lista_vizinhos.push_back(vizinho); // insere o vizinho no final da lista

	vizinho.canal = v.canal - 1;
	if(vizinho.canal > 0)		
		lista_vizinhos.push_back(vizinho); // insere o vizinho no final da lista

	vizinho.canal = v.canal * 2;
	if(vizinho.canal <= CANAL_MAXIMO)
		lista_vizinhos.push_back(vizinho); // insere o vizinho no final da lista

	vizinho.canal = v.canal * 3;
	if(vizinho.canal <= CANAL_MAXIMO)
		lista_vizinhos.push_back(vizinho); // insere o vizinho no final da lista

	if(numero_par(v.canal)){
		vizinho.canal = v.canal / 2;
		lista_vizinhos.push_back(vizinho); // insere o vizinho no final da lista
	}
	return lista_vizinhos;
}

int busca_largura(vertice atual, int alvo){
	if(atual.canal == alvo)
		return atual.nivel;

	visitados[atual.canal] = true; // marcando o canal do vertice como visitado

	//criando os vizinhos do atual.
	vector<vertice> adjacentes = vizinhos(atual);
	
	for(int i = 0; i < adjacentes.size(); i++){
		vertice vizinho = adjacentes[i];

		if(!visitados[vizinho.canal]){
			proximos.push(vizinho);
		}
	}

	if(!proximos.empty()){
		vertice proximo = proximos.front();
		proximos.pop();
		return busca_largura(proximo, alvo);
	}
	return -1;
}

int busca_largura(int origem, int destino){
	vertice partida;
	partida.canal = origem;
	partida.nivel = 0;
	return busca_largura(partida, destino);
}



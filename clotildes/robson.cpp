#include <iostream>
#include <queue>
#include <vector>
using namespace std;

#define CANAL_MAXIMO 100001

struct vertice{
	int canal;
	int nivel;
};

bool adicionados[CANAL_MAXIMO];
queue<vertice> proximos; // fila de proximos

bool numero_par(int numero){
	return numero % 2 == 0;
}

//adiciona os vizinhos validos de um vertice e que nao foram adicionados anteriormente.
void adicionaVizinhos(vertice v){	
	vertice vizinho;
	vizinho.nivel = v.nivel + 1;

	vizinho.canal = v.canal + 1;
	if(vizinho.canal < CANAL_MAXIMO && !adicionados[vizinho.canal]){
		proximos.push(vizinho); // insere o vizinho no final da lista
		adicionados[vizinho.canal] = true;
	}

	vizinho.canal = v.canal - 1;
	if(vizinho.canal > 0  && !adicionados[vizinho.canal]){	
		proximos.push(vizinho); // insere o vizinho no final da lista
		adicionados[vizinho.canal] = true;
	}

	vizinho.canal = v.canal * 2;
	if(vizinho.canal < CANAL_MAXIMO && !adicionados[vizinho.canal]){
		proximos.push(vizinho); // insere o vizinho no final da lista
		adicionados[vizinho.canal] = true;
	}

	vizinho.canal = v.canal * 3;
	if(vizinho.canal < CANAL_MAXIMO && !adicionados[vizinho.canal]){
		proximos.push(vizinho); // insere o vizinho no final da lista
		adicionados[vizinho.canal] = true;
	}

	if(numero_par(v.canal) && !adicionados[v.canal / 2]){	
		vizinho.canal = v.canal / 2;
		proximos.push(vizinho); // insere o vizinho no final da lista
		adicionados[vizinho.canal] = true;
	}
}

int busca_largura(vertice atual, int alvo){
	//cout << alvo << " " << atual.canal << endl;
	if(atual.canal == alvo)
		return atual.nivel;

	adicionaVizinhos(atual);

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
	adicionados[origem] = true;
	return busca_largura(partida, destino);
}

void zerarVisitados(){
	while(!proximos.empty())
		proximos.pop();
	for(int i = 0; i < CANAL_MAXIMO; i++)
		adicionados[i] = false;
}

int main(){
	int origem, destino, quantidade_bloqueados, bloqueado;
	int contador = 1;
	while(true){
		cin >> origem;
		cin >> destino;
		cin >> quantidade_bloqueados;

		if(origem <= 0 && destino <= 0 && quantidade_bloqueados <= 0)
			break;

		zerarVisitados();
		for(int i = 0; i < quantidade_bloqueados; i++){
			cin >> bloqueado;
			adicionados[bloqueado] = true;
		}
		cout << busca_largura(origem, destino) << endl;
	}
}


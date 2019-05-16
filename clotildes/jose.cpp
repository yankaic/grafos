#include <iostream>
#include <queue>
#include <vector>
using namespace std;

#define LIMITE 100001

//bool visitados[LIMITE];
int cliques[LIMITE];
queue<int> proximos; // fila de próximos

void canaisPossiveis(int canal){
	int proximoCanal = canal + 1;
	if(proximoCanal < LIMITE and !cliques[proximoCanal]){
		proximos.push(proximoCanal); 
		cliques[proximoCanal] = cliques[canal] + 1;
	}

	proximoCanal = canal - 1;
	if(proximoCanal > 0 and !cliques[proximoCanal]){
		proximos.push(proximoCanal); 
		cliques[proximoCanal] = cliques[canal] + 1;
	}

	proximoCanal = canal * 2;
	if(proximoCanal <= LIMITE and !cliques[proximoCanal]){
		proximos.push(proximoCanal); 
		cliques[proximoCanal] = cliques[canal] + 1;
	}

	proximoCanal = canal * 3;
	if(proximoCanal <= LIMITE and !cliques[proximoCanal]){
		proximos.push(proximoCanal); 
		cliques[proximoCanal] = cliques[canal] + 1;
	}

	if(canal % 2 == 0){
		proximoCanal = canal / 2;
		if(!cliques[proximoCanal]){
			proximos.push(proximoCanal); 
			cliques[proximoCanal] = cliques[canal] + 1;
		}
	}
}

int busca_largura(int canal, int destino){
	while(true){
		if(canal == destino)
			return cliques[canal];
		
		//visitados[canal] = true;
		canaisPossiveis(canal);
		

		if(!proximos.empty()){
			canal = proximos.front();
			proximos.pop();
		}
		else
			return -1;
	}
}

void zerar(){
	while(!proximos.empty())
		proximos.pop();
	for(int i = 0; i < LIMITE; i++){
		//visitados[i] = false;
		cliques[i] = 0;
	}
}


int main(){
	int origem, destino, bloqueados, bloqueado;
	int contador = 1;
	while(true){
		cin >> origem;
		cin >> destino;
		cin >> bloqueados;

		if(origem <= 0 and destino <= 0 and bloqueados <= 0)
			break;

		zerar();
		for(int i = 0; i < bloqueados; i++){
			cin >> bloqueado;
			cliques[bloqueado] = 1;
		}
		//cliques[origem] = 1;
		cout << busca_largura(origem, destino)  << endl;
	}
}



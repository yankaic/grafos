#include<iostream>	//comunicacao
#include<queue>			//fila
using namespace std;

#define VALOR_MAXIMO 10000

struct node{
	int valor;
	int nivel;

	node(int valor, int nivel){
		this->valor = valor;
		this->nivel = nivel;
	}

	node(){
		this->valor = -1;
		this->nivel = -1;
	}
};

queue<node> fila;
bool visitados[VALOR_MAXIMO];

void enfilera(node vertice){
	if(!visitados[vertice.valor] && vertice.valor < VALOR_MAXIMO){
		fila.push(vertice);
		visitados[vertice.valor] = true;
	}
}

int inverte(int numero){	
	int invertido = 0;
	while (numero > 0) {
		invertido *= 10;
		invertido += (numero % 10);
		numero /= 10;
	}
	return invertido;
}


int decide(node vertice, int destino){
	if(vertice.valor == destino)
		return vertice.nivel;	

	node invertido;		// nó filho
	invertido.valor = inverte(vertice.valor);
	invertido.nivel = vertice.nivel + 1;
	enfilera(invertido);

	node incrementado;		// nó filho
	incrementado.valor = vertice.valor + 1;
	incrementado.nivel = vertice.nivel + 1;
	enfilera(incrementado);

	node proximo = fila.front(); // item mais antigo da fila
	fila.pop();	// remove item mais antigo
	return decide(proximo, destino);
}


int passos(int valor, int destino){
	for(int i = 0; i < VALOR_MAXIMO; i++)
		visitados[i] = false;

	node vertice(valor, 0);
	fila = queue<node>();
	visitados[valor] = true;
	return decide(vertice, destino);
}

int main(){
	int casos;
	cin >> casos;
	while(casos--){
		int numero, destino;
		cin >> numero >> destino;

		cout << passos(numero, destino) << endl;
	}
}
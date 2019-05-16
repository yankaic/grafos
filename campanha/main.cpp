#include <iostream>
using namespace std;

bool **adjacencia;
bool *visitados;
int n;

void percorrer(int vertice){
	if(vertice <= 0 || visitados[vertice])
		return;

	visitados[vertice] = true;
	for(int vizinho = 1; vizinho <= n; vizinho++)
		if(adjacencia[vertice][vizinho])
			percorrer(vizinho);
}

int desconexos(){
	int contagem = 0;
	for(int vertice = 1; vertice <= n; vertice++){
		if(!visitados[vertice]){
			contagem++;
			percorrer(vertice);
		}
	}
	return contagem;
}

int main(){
	int casos, a, b;
	cin >> casos;

	for(int caso = 1; caso <= casos; caso++){
		int arestas;
		cin >> n;
		cin >> arestas;

		adjacencia = new bool*[n+1];
		visitados = new bool[n+1];
		for (int i = 1; i <= n; i++)
			adjacencia[i] = new bool[n+1];

		while(arestas--){
			cin >> a;
			cin >> b;
			adjacencia[a][b] = true;
			adjacencia[b][a] = true;
		}
		int restantes = desconexos() - 1;
		if(restantes)
			cout << "Caso #" << caso << ": ainda falta(m) " << restantes << " estrada(s)" << endl;
		else
			cout << "Caso #" << caso << ": a promessa foi cumprida" << endl;
	}


}
#include <iostream>
#include <vector>
using namespace std;

vector<vector<int> > adjacencia;
bool *visitados;
int n;

void percorrer(int vertice, vector<int> vizinhos){
	if(visitados[vertice])
		return;

	visitados[vertice] = true;
	for(int i = 1; i < vizinhos.size(); i++){
		int vizinho = vizinhos[i];
		percorrer(vizinho, adjacencia[vizinho]);
	}
}

int desconexos(){
	int contagem = 0;
	for(int vertice = 1; vertice <= n; vertice++){
		if(!visitados[vertice]){
			percorrer(vertice, adjacencia[vertice]);			
			contagem++;
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

		visitados = new bool[n+1];
		adjacencia.clear();
		for (int i = 0; i <= n; i++){
			adjacencia.push_back(vector<int>());
			adjacencia[i].push_back(0);
			visitados[i] = false;
		}

		while(arestas--){
			cin >> a;
			cin >> b;
			adjacencia[a].push_back(b);
			adjacencia[b].push_back(a);
		}
		int restantes = desconexos() - 1;
		if(restantes)
			cout << "Caso #" << caso << ": ainda falta(m) " << restantes << " estrada(s)" << endl;
		else
			cout << "Caso #" << caso << ": a promessa foi cumprida" << endl;
	}


}
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

vector< vector<int> > adjacencia; // lista de adjacencia.
vector<int> trilha; // salva os itens que serao impressos.
bool *visitados;	//marcação dos vertices já visitados.


void imprime(vector<int> lista){
	for(int i = 0; i < lista.size(); i++){
		char letra = 'a' + lista[i];
		cout << letra << ',';
	}
	cout << endl
};

void buscaProfundidade(int vertice){
	visitados[vertice] = true;
	trilha.push_back(vertice);

	for (int i = 0; i < adjacencia[vertice].size(); i++){
		int vizinho = adjacencia[vertice][i];
		if(!visitados[vizinho])
			buscaProfundidade(vizinho);
	}
}

int componentesConexas(){
	int componentes = 0;
	for(int vertice = 0; vertice < adjacencia.size(); vertice++){
		if(!visitados[vertice]){
			trilha.clear();
			buscaProfundidade(vertice);
			sort(trilha.begin(), trilha.end());
			imprime(trilha);
			componentes++;
		}
	}
	return componentes;
}

void adicionarAresta(char origem, char destino){
	int a = (int) (origem - 'a');
	int b = (int) (destino - 'a');
	adjacencia[a].push_back(b);
	adjacencia[b].push_back(a);
}

int main(){
	int casos;
	cin >> casos;

	for(int caso = 1; caso <= casos; caso ++){
		int quantidade_vertices, quantidade_arestas;
		cin >> quantidade_vertices >> quantidade_arestas;

		//INICIALIZAÇÃO
		adjacencia.clear();
		visitados = new bool[quantidade_vertices];
		for(int i = 0; i < quantidade_vertices; i++){
			visitados[i] = false;
			adjacencia.push_back(vector<int>());
		}

		while(quantidade_arestas--){
			char origem, destino;
			cin >> origem >> destino;
			adicionarAresta(origem, destino);
		}
		cout << "Case #" << caso << ':' << endl;
		cout << componentesConexas() << " connected components" << endl << endl;
	}
}


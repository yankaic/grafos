#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

struct aresta{
	int a;
	int b;
	int valor;	

	aresta(int a, int b, int valor){
		this->a = a;
		this->b = b;
		this->valor = valor;
	}
};

bool operator<(aresta a, aresta b){
	return a.valor < b.valor;
}

bool *selecionados;

int main(){
	int vertices, n, a, b, valor;
	int valor_total = 0, valor_gasto = 0;

	while(true){
		cin >> vertices;
		cin >> n;

		if(vertices == 0 && n == 0)
			break;

		selecionados = new bool[vertices];
		vector<aresta> arestas;
		while(n--){
			cin >> a;
			cin >> b;
			cin >> valor;
			arestas.push_back(aresta(a,b,valor));
			valor_total += valor;
		}
		sort(arestas.begin(), arestas.end());

		for(int i = 0; i < arestas.size(); i++){
			if(!selecionados[arestas[i].a] || !selecionados[arestas[i].b]){
				valor_gasto += arestas[i].valor;
				selecionados[arestas[i].a] = true;
				selecionados[arestas[i].b] = true;
			}
		}

		cout << valor_total - valor_gasto << endl;
	}
}
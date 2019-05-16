#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

//troquei a nomeclatura: componente -> Aresta
struct Aresta{
	int u;
	int v;
	int w;	
	Aresta(){
		u = -1;
		v = -1;
		w = 0;
	}
};


// alterado a nomeclaura: agm* -> custo*
int custo_minimo, custo_maximo, num_esquinas, num_ruas;
int *lista;
vector<Aresta> ruas;

bool operator<(Aresta aresta_a, Aresta aresta_b){
	return aresta_a.w < aresta_b.w;
}
int poco(int esquina){
	while(lista[esquina] != -1)
		esquina = lista[esquina];
	return esquina;
}

void limpaLista(){
	for (int i = 0; i <= num_esquinas; i++)
		lista[i] = -1;
}

// se deseja usar a lista de forma crescente, use true. A lista já precisa estar ordenada
int kruskal(bool crescente){
	Aresta rua;
	int custo = 0, valor_inicial, incremento;

	if(crescente){
		valor_inicial = 0;
		incremento = 1;
	}
	else{
		valor_inicial = num_ruas - 1;
		incremento = -1;
	}	
	limpaLista();

	for(int i = valor_inicial, ligacoes_feitas = 0; 
		ligacoes_feitas < num_esquinas and i < num_ruas and i >= 0; i += incremento){
		rua = ruas[i];
		int poco_u = poco(rua.u);
		int poco_v = poco(rua.v);

		if (poco_u != poco_v){
			lista[poco_u] = poco_v;
			custo += rua.w;
			ligacoes_feitas++;
		}
	}
	return custo;
}
int main(){
	while(true){
		cin >> num_esquinas >> num_ruas;
		if(num_esquinas == 0 && num_ruas == 0)
			break;

		lista = new int[num_esquinas + 1];
		ruas.clear();
		int ruas_restantes = num_ruas;

		Aresta rua;
		while(ruas_restantes--){			
			cin >> rua.u >> rua.v >> rua.w;
			ruas.push_back(rua);
		}

		sort(ruas.begin(), ruas.end());
		custo_minimo = kruskal(true);
		custo_maximo = kruskal(false);

		cout << custo_maximo-custo_minimo << endl;
	}
}
#include<iostream>
#include<vector>
#include<algorithm>
#include<string.h>
using namespace std;
struct componente{
	int u;
	int v;
	int w;	
	componente(){
		u = -1;
		v = -1;
		w = 0;
	}
}rua;
int agm_min, agm_max, agm;
int *lista;
vector<componente> ruas;
bool operator<(componente saida, componente chegada){
	return saida.w < chegada.w;
}
int vertice_saida_zero(int esquina){
	if(lista[esquina] == -1)
		return esquina;
	return vertice_saida_zero(lista[esquina]);
}
int kruskal(){
	for(int i = 0; i < ruas.size(); i++){
		rua = ruas[i];
		int cauda_a = vertice_saida_zero(rua.u);
		int cauda_b = vertice_saida_zero(rua.v);
		if (cauda_a != cauda_b){
			lista[cauda_a] = cauda_b;
			agm += rua.w;
		}
	}
	return agm;
}
int main(){
	int num_esquina, num_rua;
	while(true){
		cin >> num_esquina >> num_rua;
		if(num_esquina == 0 && num_rua == 0)
			break;
		lista = new int[num_rua];
		ruas.clear();
		int aux = num_rua;
		
		while(aux--){
			cin >> rua.u >> rua.v >> rua.w;
			ruas.push_back(rua);
		}

		agm_min = agm_max = 0;
		memset(lista, -1, sizeof(int) * num_rua);
		sort(ruas.begin(), ruas.end());
		agm=0;
		agm_min = kruskal();

		memset(lista, -1, sizeof(int) * num_rua);
		reverse(ruas.begin(), ruas.end());
		agm=0;
		agm_max = kruskal();

		cout << agm_max-agm_min << endl;
	}
}
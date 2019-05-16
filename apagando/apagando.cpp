#include<iostream>
#include <vector>
#include <algorithm>
#include <iterator>
using namespace std;

vector<int> transforme_digitos(int x);

int main(){
	int quantidade_digitos, quantidade_apagar, numero;
	vector<int> digitos;
	while(true){		
		cin >> quantidade_digitos;
		cin >> quantidade_apagar;
		if(quantidade_digitos == 0 && quantidade_apagar == 0)
			break;
		char numero[quantidade_digitos];
		cin >> numero;

		vector<char> ordenados(numero, numero+quantidade_digitos); 							//copia
		sort(ordenados.begin(), ordenados.end());															//ordena
		ordenados.erase(ordenados.begin()+quantidade_apagar, ordenados.end());	//poda

		for (int i = 0; i < ordenados.size(); ++i)
		{
			cout << ordenados[i];
		}
		cout << endl << endl;

		bool encontrou;
		for (int i = 0; i < quantidade_digitos; i++){
			encontrou = binary_search(ordenados.begin(),
			 ordenados.end(),numero[i]);
			if(!encontrou){
				cout << numero[i];
			}
		}
		cout << endl; 		
	}
	
}

vector<int> transforme_digitos(int x){
  vector<int> pilha;
  while(x >= 10){
    pilha.push_back(x % 10);
    x= x / 10; 
  }
  pilha.push_back(x);
  return pilha;
}

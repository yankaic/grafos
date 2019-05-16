#include<iostream>
#include <vector> 
using namespace std;

int main(){
	int quantidade_digitos, quantidade_apagar, numero;
	while(true){		
		cin >> quantidade_digitos;
		cin >> quantidade_apagar;
		if(quantidade_digitos == 0 && quantidade_apagar == 0)
			break;

		char numero[quantidade_digitos];
		bool remover[quantidade_digitos];
		cin >> numero;
		vector<int> pilha;

		for (int i = 0; quantidade_apagar > 0 && i < quantidade_digitos; i++){
			while(quantidade_apagar > 0 && !pilha.empty() && i < quantidade_digitos){
				if(numero[i] > numero[pilha.back()]){
					pilha.pop_back();
					quantidade_apagar--;
				}
				else{
					pilha.push_back(i);
					i++;
				}
			}
			if(i<quantidade_digitos)
				pilha.push_back(i);
		}
		int ultimo = pilha.back() + 1;

		while(quantidade_apagar &&!pilha.empty()){
			pilha.pop_back();
			quantidade_apagar--;
		}

		for(int x =0; x< pilha.size(); x++)
			cout << numero[pilha[x]];

		for(int i = ultimo; i < quantidade_digitos; i++){
			cout << numero[i];
		}
		cout << endl;		
	}
	
}

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


		for(int x =0; x< quantidade_digitos; x++)
			cout << "." << numero[x];
		cout << endl;

		for (int i = 0; quantidade_apagar > 0 && i < quantidade_digitos; i++){

				cout << "indice for: " << i << endl;
			while(quantidade_apagar > 0 && !pilha.empty() && i < quantidade_digitos){
				
				for(int x =0; x< pilha.size(); x++)
					cout << "." << pilha[x];
				cout << endl << endl;
				cout << "indice: " << i << endl;






				// if(pilha.size() > quantidade_apagar){
				// 	cout << "c." << numero[pilha.front()];
				// 	pilha.erase(pilha.begin());
				// }
				if(numero[i] > numero[pilha.back()]){
					remover[pilha.back()] = true;
					pilha.pop_back();
					quantidade_apagar--;
				}
				else{
					pilha.push_back(i);
					i++;
				}
			}
			pilha.push_back(i);
		}

		while(quantidade_apagar-- &&!pilha.empty())
			pilha.pop_back();

		int ultimo;
		for(int i = 0; i < pilha.size() && i < quantidade_apagar; i++){
			if(!remover[i])
				cout << " a." << numero[pilha[i]];
			ultimo = i;
		}

		for(int i = ultimo + 1;i <  quantidade_digitos; i++){
			if(!remover[i])
				cout << " b." << numero[i];
		}
		cout << endl;		
	}
	
}

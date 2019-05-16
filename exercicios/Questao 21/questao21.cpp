#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;

int distancia(int a, int b){
	return abs(a-b);
}

int main(){
	int leitura, torre, raio;
	vector<int> casas;
	queue<int> torres;

	cin >> raio;
	while(true){
		cin >> leitura;
		if(leitura < 0)
			break;

		casas.push_back(leitura);
	}
	sort(casas.begin(), casas.end());

	while(!casas.empty()){
		torre = casas.front() + raio;
		torres.push(torre);

		while(!casas.empty() && distancia(casas.front(), torre) <= raio)
			casas.erase(casas.begin());
	}

	while(!torres.empty()){
		cout << "." << torres.front();
		torres.pop();
	}
	cout << endl;
}
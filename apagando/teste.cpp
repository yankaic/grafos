#include<iostream>
#include <vector>
using namespace std;

int main(){
	std::vector<int> lista;
	for(int i = 0; i < 10; i++)
		lista.push_back(i);

	while(!lista.empty())
		lista.erase(lista.begin());
}
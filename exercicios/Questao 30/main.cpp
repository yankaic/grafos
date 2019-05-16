#include <iostream>
using namespace std;
int grade[9][9];

bool seguro(int numero, int linha, int coluna);
void imprimir();

bool preencher(int sequencia){
	if(sequencia == 81)
		return true;

	int linha = sequencia / 9;
	int coluna = sequencia % 9;

	if(grade[linha][coluna]!=0)
		return preencher(sequencia+1);

	for(int numero = 1; numero <= 9; numero++){
		if(seguro(numero, linha, coluna)){
			grade[linha][coluna] = numero;
			if(preencher(sequencia + 1))
				return true;
			grade[linha][coluna] = 0;
		}
		
	}
	return false;
}

int main(){	
	for(int linha = 0; linha < 9; linha ++)
		for(int coluna = 0; coluna < 9; coluna++)
			cin >> grade[linha][coluna];
	preencher(0);

	imprimir();
}

void imprimir(){
	for(int linha = 0; linha < 9; linha ++){
		for(int coluna = 0; coluna < 9; coluna++){
			cout << grade[linha][coluna] << ' ';
			if((coluna+1) % 3==0)
				cout << ' ';
		}
		if((linha+1) % 3 ==0)
			cout << endl;
		cout << endl;
	}
}

bool quadrante_seguro(int numero, int linha, int coluna){
	for(int i = 3*(linha / 3); i < 3*(linha / 3) + 3; i++)
		for(int j = 3*(coluna / 3); j < 3 * (coluna / 3) + 3; j++)
			if(grade[i][j] == numero)
				return false;
	return true;
}

bool linha_segura(int numero, int linha){
	for(int coluna = 0; coluna < 9; coluna++)
		if(grade[linha][coluna] == numero){
			return false;
		}
	return true;
}

bool coluna_segura(int numero, int coluna){
	for(int linha = 0; linha < 9; linha++)
		if(grade[linha][coluna] == numero){
			return false;
		}
	return true;
}

bool seguro(int numero, int linha, int coluna){
	return linha_segura(numero, linha) &&
		coluna_segura(numero, coluna) &&
		quadrante_seguro(numero, linha, coluna);
}
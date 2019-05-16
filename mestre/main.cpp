#include <iostream>
using namespace std;

struct ponto{
	int x;
	int y;
};

ponto operator+(ponto a, ponto b){
	a.x = a.x + b.x;
	a.y = a.y + b.y;
	return a;
}

const ponto DIREITA  = {1, 0};
const ponto ESQUERDA = {-1, 0};
const ponto CIMA = {0, -1};
const ponto BAIXO =  {0, 1};

char **mapa;
int MAX_X, MAX_Y;

void seguir(ponto local, ponto direcao){
	if(local.x < 0 || local.y < 0 ||local.x >= MAX_X || local.y >= MAX_Y) {//fora do mapa
		cout << '!' << endl;
		return;
	}
	switch(mapa[local.y][local.x]){
		case 'x':
			cout << '!' << endl;
			return;
		case '*':
			cout << '*' << endl; // encontrou
			return;
		case '>':
			direcao = DIREITA;
			break;
		case '<':
			direcao = ESQUERDA;
			break;
		case '^':
			direcao = CIMA;
			break;
		case 'v':
			direcao = BAIXO;
			break;
	}
	mapa[local.y][local.x] = 'x';
	seguir(local + direcao, direcao);
}


int main(){
	cin >> MAX_X;
	cin >> MAX_Y;

	//criando a matriz
	mapa = new char*[MAX_Y];
	for(int i = 0; i < MAX_Y; i++)
		mapa[i] = new char[MAX_X];

	//lendo os valores da matriz
	for(int linha = 0; linha < MAX_Y; linha++)
		for(int coluna = 0; coluna < MAX_X; coluna++)
			cin >> mapa[linha][coluna];

	ponto inicial = {0, 0};
	seguir(inicial, inicial);
}
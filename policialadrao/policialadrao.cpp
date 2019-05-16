#include <iostream>
using namespace std;
#define FORA_ESCOPO linha < 0 || coluna < 0 || linha >= TAMANHO || coluna >= TAMANHO
#define DIREITA linha, coluna + 1
#define BAIXO linha + 1, coluna
#define ESQUERDA linha, coluna - 1
#define CIMA linha - 1, coluna

bool **visitados;
const int TAMANHO = 5;
void criarLabirinto();
void lerLabirinto();

bool entrar(int linha, int coluna){
	if(FORA_ESCOPO || visitados[linha][coluna])
		return false;

	if(linha == TAMANHO-1 && coluna == TAMANHO-1)
		return true;

	visitados[linha][coluna] = true;
	if(entrar(DIREITA))
		return true;
	if(entrar(BAIXO))
		return true;
	if(entrar(ESQUERDA))
		return true;
	if(entrar(CIMA))
		return true;

	return false;
}

int main(){
	int casos;
	cin >> casos;
	criarLabirinto();

	while(casos--){		
		lerLabirinto();
		bool tem_saida = entrar(0,0);
		cout << (tem_saida? "COPS": "ROBBERS") << endl;
	}
}

void criarLabirinto(){	
	visitados = new bool*[TAMANHO];
	for(int linha = 0; linha < TAMANHO; linha++)
		visitados[linha] = new bool[TAMANHO];
}

void lerLabirinto(){
	for(int linha = 0; linha < TAMANHO; linha++)
		for(int coluna = 0; coluna < TAMANHO; coluna++)
			cin >> visitados[linha][coluna];
}
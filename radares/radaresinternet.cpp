#include <iostream>
#include <stdlib.h>
using namespace std;

const int MAXIMO_VALOR = 1000 * 1000 + 10;
int *escolhas;
bool *tem_radar;
int *lucros;
int *posicoes;

int main() {
  escolhas = new int[MAXIMO_VALOR];
  int casos; cin >> casos;
  while (casos--) {
    int radares, distancia_minima;
    cin >> radares;
    cin >> distancia_minima;

    escolhas = new int[MAXIMO_VALOR];
    tem_radar = new bool[MAXIMO_VALOR];
    lucros = new int[MAXIMO_VALOR];
    posicoes = new int[radares];

    for (int indice = 0; indice < radares; indice++) {
      cin >> posicoes[indice];
      tem_radar[posicoes[indice]] = true;
    }
    for (int indice = 0, lucro; indice < radares; indice++) {
      cin >> lucro;
      lucros[posicoes[indice]] = max(lucros[posicoes[indice]], lucro);
    }

    for (int indice = MAXIMO_VALOR - 2, inclusivo, exclusivo; indice >= 0; --indice) {
      escolhas[indice] = escolhas[indice + 1];

      if (tem_radar[indice] && indice + distancia_minima < MAXIMO_VALOR){
        inclusivo = lucros[indice] + escolhas[indice + distancia_minima];
        exclusivo = escolhas[indice];
        escolhas[indice] = max(exclusivo, inclusivo);
      }
    }
    cout << (escolhas[0]) << endl;
  }
  return 0;
}
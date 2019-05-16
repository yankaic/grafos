LIMITE = 100001
cliques = []
visitados = []
fila = []

def buscaLargura(canal, destino):
	global visitados, cliques
	while True:
		if canal == destino:
			return cliques[canal]

		visitados[canal] = True

		canaisVizinhos = canaisPossiveis(canal)

		for canalVizinho in canaisVizinhos:
			if not visitados[canalVizinho]:
				fila.append(canalVizinho)

		if fila:
			canal = fila.pop(0)
		else:
			return -1

def zerar():
	global fila, visitados, cliques
	fila = []
	visitados = [False for i in range(LIMITE)]
	cliques = [0 for i in range(LIMITE)]

def canaisPossiveis(canal):
	global cliques
	canais = []

	if canal - 1 > 0 and cliques[canal - 1] == 0:
		canais.append(canal - 1)
		cliques[canal - 1] = cliques[canal] + 1

	if canal + 1 < LIMITE and cliques[canal + 1] == 0:
		canais.append(canal + 1)
		cliques[canal + 1] = cliques[canal] + 1

	if canal * 2 < LIMITE and cliques[canal * 2] == 0:
		canais.append(canal * 2)
		cliques[canal * 2] = cliques[canal] + 1

	if canal * 3 < LIMITE and cliques[canal * 3] == 0:
		canais.append(canal * 3)
		cliques[canal * 3] = cliques[canal] + 1

	if(canal % 2 == 0) and cliques[canal // 2] == 0:
		canais.append(canal // 2)
		cliques[canal // 2] = cliques[canal] + 1

	return canais

while True:
	canalPartida, canalDesejado, proibido = input('').split(" ")
	canalPartida = int(canalPartida)
	canalDesejado = int(canalDesejado)
	proibido = int(proibido)
	
	if canalPartida == 0 and canalDesejado == 0 and proibido == 0:
		break 

	canaisProibidos = input('').split(" ")
	canaisProibidos = list(map(int, canaisProibidos))

	zerar()
	for canalProibido in canaisProibidos:
		visitados[canalProibido] = True

	quantidadeCliques = buscaLargura(canalPartida, canalDesejado)
	print(quantidadeCliques)


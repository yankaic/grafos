peso = []
valor = []
quantidade = 0
capacidade = 0
caso = 1

while True:
	quantidade = input()
	capacidade = input()

	if(quantidade == 0 and capacidade == 0):
		break

	for indice in range(quantidade):
		peso[indice] = input()
		valor[indice] = input()

	for indice in range(quantidade):
		print("peso: " + peso[indice])
		print(" valor: "+ valor[indice])

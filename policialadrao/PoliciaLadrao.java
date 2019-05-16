import java.io.IOException;
import java.util.Scanner;
 
public class PoliciaLadrao {
   
  public static int[][] matriz;
   
  static int Percorrer(int linha, int coluna, int limite)
  {
    if (linha > 4 || linha < 0 || coluna > 4 || coluna < 0)
      return 0;
    if (matriz[linha][coluna] > 0)
      return 0;//já passou por aqui ou está bloqueada
    if (linha == 4 && coluna == 4)//caso base
      return 1;
 
    matriz[linha][coluna] = 2;// marca como posição já visitada
 
    for (int i = 1; i<=4; i++)
    {
      if(i == limite) continue;//verifica restrição de não voltar para a casa anterior
      int resposta=0;
      switch (i) {
        case 1:
          resposta = Percorrer(linha, coluna + 1, 3);
          break;
        case 2:
          resposta = Percorrer(linha + 1, coluna, 4);
          break;
        case 3:
          resposta = Percorrer(linha, coluna - 1, 1);
          break;
        case 4:
          resposta = Percorrer(linha - 1, coluna, 2);
          break;
      }
      if (resposta == 1) return 1;
    }
    return 0;       
  }
   
  public static void main(String[] args) throws IOException {
     
    matriz = new int[5][5];
     
    Scanner ler = new Scanner(System.in);
    int casos = Integer.parseInt(ler.nextLine());//pego a quantidade de casos
     
    for (int i = 0; i < casos; i++)
    {
      for (int j = 0; j <= 4; j++)//alocando linhas
      {
        String[] linha = ler.nextLine().split(" ");
        for(int l = 0; l <=4; l++)//alocando colunas
        {
          try{
            matriz[j][l] = Integer.parseInt(linha[l]);
          }
          catch(NumberFormatException e){
            j--;
            break;
          }
        }
      }//matriz preenchida
      if (Percorrer(0, 0, 3) == 1)
        System.out.println("COPS");
       
      else
        System.out.println("ROBBERS");
    } 
  } 
}
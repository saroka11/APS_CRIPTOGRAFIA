#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define tam 6
#define TAM_LINHA 3
#define TAM_COLUNA 2


// Função para encontrar o índice de uma letra na tabela
int encontrarIndice(char letra, const char tabela[]) 
{
    int i;
  for (i = 0; i <= 26; i++) 
  {
    if (letra == tabela[i]) 
        return i;
  }

    if (-1)
    {
        i = 0;
        return i;
    }
}


// fução para imprimir matriz
void imprimirMatriz(float matriz[][TAM_COLUNA])
{
	for(int i = 0; i < TAM_LINHA; i++)
	{
		for(int j = 0; j < TAM_COLUNA; j++){
		
			if ( j == 0)
			printf("| %.0f ", matriz[i][j]);
			else if (j == 1)
			printf(" %.0f | ", matriz[i][j]);
}			
		printf("\n");
		}
}


// função de multiplicação 
void multiplicarMatrizes(float resultado[][TAM_COLUNA], const float C[][3], float matrizB[][TAM_COLUNA])
{
	for (int i=0; i < 3; i++) 
{
    for (int j=0; j < TAM_COLUNA; j++) 
    {
        for (int k=0; k < 3; k++) 
            resultado[i][j] += C[i][k] * matrizB[k][j];  
    } 
}
}

    
////

int main()
{ 
        
        printf ("------ PROGRAMA DE CRIPTOGRAFIA ------\n\n");
    
  char palavra[tam]; char M[3][2]; 
  float Mcod[3][2]; 
  int num = 0, i=0, j=0;
  char letra;
  float MC[TAM_LINHA][TAM_COLUNA];

  
  // tabela de conversão
  const char tabelaDeConversao[28] = {" abcdefghijklmnopqrstuvwxyz"};
  // matriz que será usada para criar M*C
  const float C[3][3] = {1, 0 ,1 ,1 ,1 ,1 ,0 ,2 ,-1};
  

  
 // Solicitando ao usuário a palavra a ser criptografada
printf("Digite uma palavra (maximo de 6 letras): ");
scanf("%s", palavra);
system("cls");

    strlwr(palavra);



// Organizando as letras na matriz (para ficar da forma que se pede no enunciado)
  for (int c = 0; c < TAM_COLUNA; c++) 
  {
    for (int l = 0; l < TAM_LINHA; l++) 
	{
      M[l][c] = palavra[num];
      num++;
    }
  }     
  
num = 0;

  
  
// FAZER A TROCA de letra por indice
  for (i = 0; i < TAM_LINHA; i++) 
  {
    for (j = 0; j < TAM_COLUNA; j++) 
    {
      letra = M[i][j];
      int indice = encontrarIndice(letra, tabelaDeConversao);
      Mcod[i][j] = indice;
    }
  }
  
    printf ("\nA palavra original lida: %s\n", palavra);
    printf("\nMatriz M codificada:\n");
    imprimirMatriz(Mcod);


multiplicarMatrizes(MC, C, Mcod);

// impressão da MENSAGEM CRIPTOGRAFADA
     printf("\nMatriz da mensagem criptografada (MC):\n");
     imprimirMatriz(MC);
  


    return 0;
}


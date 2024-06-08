#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define tam 27 // Tamanho da tabela hash (26 letras do alfabeto + espaço em branco)
#define ordem 3 // tamanho da matriz C e identidade
#define LINHA_T 3 
#define COLUNA_T 2


int i, j;

typedef struct Hash {
  int chave;
  char valor;
} Hash;

Hash tabelaDeConversao[tam];


// função para impressão das matrizes
void imprimirMatriz(float matriz[][COLUNA_T])
{

	for(i = 0; i < LINHA_T; i++){
		for(j = 0; j < COLUNA_T; j++)
		{
			if (j==0)
			printf("|%.0f ", matriz[i][j]);
			else
			printf(" %.0f|", matriz[i][j]);
		}

		printf("\n");
	}
}


// função para inicializar a tabela hash: 
void inicializarTabelaHash() 
{
  for (i = 0; i < tam; i++) 
  {
    tabelaDeConversao[i].chave = i;
    if (i == 0) 
    {
      tabelaDeConversao[i].valor = ' '; // Espaço em branco
    } else {
      tabelaDeConversao[i].valor = 'a' + i - 1; // as letras de a-z
    }
  }
}


// função hash pra calcular indice
int funcaoHash(char *chave)
{
unsigned int hash = 0; // garantir que vai ser sempre positivo

  for (i = 0; chave[i] != '\0'; i++) 
  {
    hash += (int)chave[i] * (i + 1); // pegando o codigo e multiplicando pela posição
  }
  return hash % tam;
}


// função para multiplicar matriz
void multiplicarMatrizes(float resultado[][COLUNA_T], float matrizA[][ordem], float matrizB[][COLUNA_T])
{
	for (i=0; i < 3; i++) 
{
    for (j=0; j < COLUNA_T; j++) 
    {
        for (int k=0; k < 3; k++) 
            resultado[i][j] += matrizA[i][k] * matrizB[k][j];  
    } 
}
}



// função que recebe uma chave e devolve o valor: 
char buscarLetra(int chave) 
{
  if (chave >= 1 && chave <= 26) 
    return tabelaDeConversao[chave].valor;
   else 
    return ' ';
}



int main()
{
	printf ("------ PROGRAMA DE DESCRIPTOGRAFIA ------\n\n");
	
////// variaveis:
const float C[] = { 1, 0, 1, 1, 1, 1, 0, 2, -1 };

	int num = 0;
	float pivo, m;
	
	float matriz_C[ordem][ordem]; float id[ordem][ordem];

	float MC[3][2];
	float M[3][2];
	char palavra[6];
	
	
//construindo a Matriz Identidade
for(i=0; i < ordem; i++)
{
	for(j=0; j < ordem; j++)
	{
		if(i == j)
			id[i][j] = 1;
		else
			id[i][j] = 0;
	}
}


//recebendo a matriz C

	for(i=0; i < ordem; i++)
	{
		for(j=0; j < ordem; j++)
		{
			matriz_C[i][j] = C[num];
			num++;
		}
	}
num=0;
	
	
// calculando a matriz inversa de C (com eliminação de Gauss-Jordan)
for(j=0; j < ordem; j++)
{	
	// encontra o pivô
	pivo = matriz_C[j][j];
	
	// Divide a linha do pivô por ele
    for (int k = 0; k < ordem; k++) 
	{
		matriz_C[j][k] /= pivo; 
		id[j][k] /= pivo; 
	}
	
	// Elimina os outros elementos da coluna do pivô
		for(i=0; i < ordem; i++)
		{
			if(i != j)
			{
				m = matriz_C[i][j];
				
				for(int k=0; k < ordem; k++)
				{
					matriz_C[i][k] -= (m * matriz_C[j][k]); 
					id[i][k] -= (m * id[j][k]); 
					// no final, a matriz id fica com o resultado da matriz inversa
				}
			}		
		}
}



printf("\nInforme a matriz MC:\n"); // exemplo: MC = { 3, 31, 21, 40, 35, 6 } = brasil
for(i=0; i < 3; i++)
{
	for(j=0; j < 2; j++)
	{
		scanf("%f", &MC[i][j]);	
	}
}
    system("cls");
    printf ("Matriz da mensagem criptografada:\n");
	imprimirMatriz(MC);
	


multiplicarMatrizes(M, id, MC);
// matriz inversa de C (id) * Matriz criptografada (MC)


//imprimindo M
printf("\n\nMatriz M descriptografada com a inversa de C:\n");
imprimirMatriz(M);
	

// Descobrindo a mensagem:
inicializarTabelaHash();

for (int i = 0; i < 2; i++)
{
    for (int j = 0; j < 3; j++)
    {
        int chave = M[j][i];
        char letra = buscarLetra(chave);
        palavra[num] = letra;
        
        if (i == 0 && j == 0)
        	palavra[num] = toupper(palavra[num]);
        
        num++;
    }
}
num = 0;


printf ("\nA mensagem original: %s\n",palavra);


	return 0;
}

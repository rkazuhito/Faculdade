#include <stdio.h>
#include <stdlib.h>

void insertionSort(int v[200], int n) // Declara��o da fun��o de ordena��o por inser��o
{
	int i, j, x; // Declara��o de vari�veis de itera��o e uma vari�vel auxiliar
	for(i = 1; i < n; i++) // Loop para percorrer o vetor a partir do segundo elemento
	{
		x = v[i]; // Armazena o valor do elemento atual em x
		j = i - 1; // Inicializa j como o �ndice anterior ao elemento atual
		while(j >= 0 && v[j] > x) // Loop para deslocar os elementos maiores que x uma posi��o para a direita
		{
			v[j+1] = v[j]; // Desloca o elemento para a direita
			j--; // Decrementa j para verificar o pr�ximo elemento � esquerda
		}
		v[j+1] = x; // Insere x na posi��o correta no vetor ordenado
	}
}

int main()
{	
	int numero;
    char caractere;
	int v[200], n, i; // Declara��o de um vetor, uma vari�vel para o tamanho do vetor e vari�veis de itera��o
	printf("Entre tamanho desejado do vetor: "); // Solicita ao usu�rio o tamanho do vetor
	scanf("%d", &n); // L� o tamanho do vetor fornecido pelo usu�rio
	printf("Entre os %d elementos do vetor:\n", n); // Solicita ao usu�rio que insira os elementos do vetor
	for(i = 0; i < n; i++) // Loop para ler os elementos do vetor fornecidos pelo usu�rio
	{
		
    printf("Digite um n�mero inteiro: ");
    
	    // Loop para garantir que o usu�rio digite um n�mero inteiro
	    while (scanf("%d%c", &numero, &caractere) != 2 || caractere != '\n') {
	        printf("Entrada inv�lida. Por favor, digite novamente um n�mero inteiro: ");
	        while (getchar() != '\n'); // Limpar o buffer do teclado
	    }
	    printf("Voc� digitou o n�mero: %d\n", numero);

		v[i] = numero;
		
	//	scanf("%d", &v[i]); // L� cada elemento do vetor //antigo. foi alterado pro loop acima para n�o receber caracter
	}
	
	insertionSort(v, n); // Chama a fun��o de ordena��o por inser��o para ordenar o vetor
	printf("\n\nVetor ordenado:\n"); // Imprime uma mensagem indicando que o vetor est� ordenado
	for(i = 0; i < n; i++) // Loop para imprimir os elementos do vetor ordenado
	{
		printf("%d\t", v[i]); // Imprime cada elemento do vetor
	}
	printf("\n"); // Imprime uma nova linha
	return 0; // Retorna 0 indicando que o programa foi executado com sucesso
}


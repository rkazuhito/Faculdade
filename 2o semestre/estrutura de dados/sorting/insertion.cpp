#include <stdio.h>
#include <stdlib.h>

void insertionSort(int v[200], int n) // Declaração da função de ordenação por inserção
{
	int i, j, x; // Declaração de variáveis de iteração e uma variável auxiliar
	for(i = 1; i < n; i++) // Loop para percorrer o vetor a partir do segundo elemento
	{
		x = v[i]; // Armazena o valor do elemento atual em x
		j = i - 1; // Inicializa j como o índice anterior ao elemento atual
		while(j >= 0 && v[j] > x) // Loop para deslocar os elementos maiores que x uma posição para a direita
		{
			v[j+1] = v[j]; // Desloca o elemento para a direita
			j--; // Decrementa j para verificar o próximo elemento à esquerda
		}
		v[j+1] = x; // Insere x na posição correta no vetor ordenado
	}
}

int main()
{	
	int numero;
    char caractere;
	int v[200], n, i; // Declaração de um vetor, uma variável para o tamanho do vetor e variáveis de iteração
	printf("Entre tamanho desejado do vetor: "); // Solicita ao usuário o tamanho do vetor
	scanf("%d", &n); // Lê o tamanho do vetor fornecido pelo usuário
	printf("Entre os %d elementos do vetor:\n", n); // Solicita ao usuário que insira os elementos do vetor
	for(i = 0; i < n; i++) // Loop para ler os elementos do vetor fornecidos pelo usuário
	{
		
    printf("Digite um número inteiro: ");
    
	    // Loop para garantir que o usuário digite um número inteiro
	    while (scanf("%d%c", &numero, &caractere) != 2 || caractere != '\n') {
	        printf("Entrada inválida. Por favor, digite novamente um número inteiro: ");
	        while (getchar() != '\n'); // Limpar o buffer do teclado
	    }
	    printf("Você digitou o número: %d\n", numero);

		v[i] = numero;
		
	//	scanf("%d", &v[i]); // Lê cada elemento do vetor //antigo. foi alterado pro loop acima para não receber caracter
	}
	
	insertionSort(v, n); // Chama a função de ordenação por inserção para ordenar o vetor
	printf("\n\nVetor ordenado:\n"); // Imprime uma mensagem indicando que o vetor está ordenado
	for(i = 0; i < n; i++) // Loop para imprimir os elementos do vetor ordenado
	{
		printf("%d\t", v[i]); // Imprime cada elemento do vetor
	}
	printf("\n"); // Imprime uma nova linha
	return 0; // Retorna 0 indicando que o programa foi executado com sucesso
}


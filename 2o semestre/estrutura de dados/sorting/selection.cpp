#include <stdio.h>  
#include <stdlib.h> 

// Função para ordenar um vetor usando o algoritmo de Selection Sort
void selectionSort(int v[200], int n)
{
    int i, j, aux, min; // Declaração de variáveis locais
    
    // Loop para percorrer o vetor
    for(i = 0; i < n-1; i++) {
        min = i; // Define o índice do menor elemento como o índice atual
        
        // Loop para encontrar o índice do menor elemento não ordenado
        for(j = i+1; j < n; j++) {
            if(v[j] < v[min]) { // Se o elemento atual for menor que o menor encontrado até agora
                min = j; // Atualiza o índice do menor elemento
            }
        }
        
        // Troca os elementos para ordená-los
        aux = v[i]; // Armazena temporariamente o elemento atual
        v[i] = v[min]; // Substitui o elemento atual pelo menor encontrado
        v[min] = aux; // Substitui o menor encontrado pelo elemento armazenado temporariamente
    }
}

int main()
{
    int v[200], n, i, numero; // Declaração de variáveis locais
    char caractere;
    // Solicita o tamanho desejado do vetor
    printf("Entre tamanho desejado do vetor: ");
    scanf("%d", &n);
    
    // Solicita os elementos do vetor ao usuário
    printf("Entre os %d elementos do vetor:\n", n);
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
    
    // Chama a função para ordenar o vetor
    selectionSort(v, n);
    
    // Exibe o vetor ordenado
    printf("\n\nVetor ordenado:\n");
    for(i = 0; i < n; i++) {
        printf("%d\t", v[i]);
    }
    printf("\n");
    
    return 0; // Retorna 0 indicando sucesso
}


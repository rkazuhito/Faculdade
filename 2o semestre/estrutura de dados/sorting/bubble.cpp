#include <stdio.h>
#include <stdlib.h>

// Fun��o para ordenar um vetor usando o algoritmo de Bubble Sort
void bubbleSort(int v[200], int n)
{
    int i, j, aux;
    // Loop para percorrer o vetor da direita para a esquerda
    for(i = n-1; i > 0; i--) {
        // Loop para percorrer o vetor da esquerda para a direita
        for(j = 0; j < i; j++) {
            if(v[j] > v[j+1]) {
                // Troca os elementos se estiverem fora de ordem
                aux = v[j]; 
                v[j] = v[j+1]; 
                v[j+1] = aux; //troca
            }
        }
    }
}

int main()
{
    int v[200], n, i, numero;
    char caractere;
    // Solicita o tamanho desejado do vetor
    printf("Entre tamanho desejado do vetor: ");
    scanf("%d", &n);
    
    // Solicita os elementos do vetor ao usu�rio
    printf("Entre os %d elementos do vetor:\n", n);
    
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
    
    // Chama a fun��o para ordenar o vetor
    bubbleSort(v, n);
    
    // Exibe o vetor ordenado
    printf("\n\nVetor ordenado:\n");
    for(i = 0; i < n; i++) {
        printf("%d\t", v[i]);
    }
    printf("\n");
    return 0;
}


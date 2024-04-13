#include <stdio.h>  
#include <stdlib.h> 

// Fun��o para ordenar um vetor usando o algoritmo de Selection Sort
void selectionSort(int v[200], int n)
{
    int i, j, aux, min; // Declara��o de vari�veis locais
    
    // Loop para percorrer o vetor
    for(i = 0; i < n-1; i++) {
        min = i; // Define o �ndice do menor elemento como o �ndice atual
        
        // Loop para encontrar o �ndice do menor elemento n�o ordenado
        for(j = i+1; j < n; j++) {
            if(v[j] < v[min]) { // Se o elemento atual for menor que o menor encontrado at� agora
                min = j; // Atualiza o �ndice do menor elemento
            }
        }
        
        // Troca os elementos para orden�-los
        aux = v[i]; // Armazena temporariamente o elemento atual
        v[i] = v[min]; // Substitui o elemento atual pelo menor encontrado
        v[min] = aux; // Substitui o menor encontrado pelo elemento armazenado temporariamente
    }
}

int main()
{
    int v[200], n, i, numero; // Declara��o de vari�veis locais
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
    selectionSort(v, n);
    
    // Exibe o vetor ordenado
    printf("\n\nVetor ordenado:\n");
    for(i = 0; i < n; i++) {
        printf("%d\t", v[i]);
    }
    printf("\n");
    
    return 0; // Retorna 0 indicando sucesso
}


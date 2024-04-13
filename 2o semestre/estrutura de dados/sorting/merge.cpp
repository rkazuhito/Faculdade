#include <stdio.h>
#include <stdlib.h>

// Função para fundir dois subvetores de arr[]
// O primeiro subvetor é arr[l..m]
// O segundo subvetor é arr[m+1..r]
void merge(int arr[], int l, int m, int r) {
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;

    // Cria vetores temporários
    int L[n1], R[n2];

    // Copia os dados para os vetores temporários L[] e R[]
    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];

    // Combina os vetores temporários de volta em arr[l..r]
    i = 0; // Índice inicial do primeiro subvetor
    j = 0; // Índice inicial do segundo subvetor
    k = l; // Índice inicial do subvetor fundido
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    // Copia os elementos restantes de L[], se houver algum
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    // Copia os elementos restantes de R[], se houver algum
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

// Função principal que implementa o Merge Sort
// l é para o índice esquerdo e r é para o índice direito do subvetor de arr que será classificado
void mergeSort(int arr[], int l, int r) {
    if (l < r) {
        // Calcula o ponto médio
        int m = l + (r - l) / 2;

        // Classifica primeiro e segundo subvetores
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);

        // Funde os subvetores classificados
        merge(arr, l, m, r);
    }
}

int main() {
    int arr[200], n, i;
    // Solicita o tamanho desejado do vetor
    printf("Entre tamanho desejado do vetor: ");
    scanf("%d", &n);
    
    // Solicita os elementos do vetor ao usuário
    printf("Entre os %d elementos do vetor:\n", n);
    for(i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    
    // Chama a função para ordenar o vetor
    mergeSort(arr, 0, n - 1);
    
    // Exibe o vetor ordenado
    printf("\n\nVetor ordenado:\n");
    for(i = 0; i < n; i++) {
        printf("%d\t", arr[i]);
    }
    printf("\n");
    return 0;
}


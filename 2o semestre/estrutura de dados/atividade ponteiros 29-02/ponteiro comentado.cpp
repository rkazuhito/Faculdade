#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Fun��o para calcular o comprimento de uma string
int calcularComprimentoString(const char *str) {
    int comprimento = 0;
    // Itera sobre a string at� encontrar o caractere nulo '\0'
    while (*str != '\0') {
        comprimento++;
        str++;
    }
    return comprimento;
}

// Fun��o para copiar uma string para outra
void copiarString(char *destino, const char *origem) {
    // Itera sobre a string de origem e copia cada caractere para a string de destino
    while (*origem != '\0') {
        *destino = *origem;
        destino++;
        origem++;
    }
    // Adiciona o caractere nulo '\0' ao final da string de destino
    *destino = '\0';
}

// Fun��o para concatenar duas strings
void concatenarString(char *destino, const char *origem) {
    // Move o ponteiro para o final da string de destino
    while (*destino != '\0') {
        destino++;
    }
    // Copia os caracteres da string de origem para o final da string de destino
    while (*origem != '\0') {
        *destino = *origem;
        destino++;
        origem++;
    }
    // Adiciona o caractere nulo '\0' ao final da string de destino
    *destino = '\0';
}

int main() {
    char string1[100]; // Declara um array para armazenar a primeira string
    char string2[100]; // Declara um array para armazenar a segunda string
    char continuar;    // Vari�vel para verificar se o usu�rio deseja continuar

    do {
        printf("Digite a primeira string: ");
        scanf("%s", string1); // L� a primeira string do usu�rio

        printf("Digite a segunda string: ");
        scanf("%s", string2); // L� a segunda string do usu�rio

        // Calcula o comprimento das strings
        int comprimento1 = calcularComprimentoString(string1);
        int comprimento2 = calcularComprimentoString(string2);

        printf("Comprimento da primeira string: %d\n", comprimento1);
        printf("Comprimento da segunda string: %d\n", comprimento2);

        // Alocamos mem�ria suficiente para a string resultante
        char *string_concatenada = (char *)malloc(comprimento1 + comprimento2 + 1);

        // Copia a string1 para a string alocada e imprime
        copiarString(string_concatenada, string1);
        printf("String1 copiada: %s\n", string_concatenada);

        // Concatena a string2 � string alocada e imprime o resultado
        concatenarString(string_concatenada, string2);
        printf("String1 + String2 concatenadas: %s\n", string_concatenada);

        free(string_concatenada); // Liberamos a mem�ria alocada

        printf("Deseja inserir mais strings? (s/n): ");
        scanf(" %c", &continuar); // L� a resposta do usu�rio

    } while (continuar == 's' || continuar == 'S');

    return 0;
}


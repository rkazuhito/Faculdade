/*
Rafael Kazuhito Vidal Beltr�o

	Um exemplo pr�tico de uma pilha pode ser a fun��o de desfazer (undo) em um editor de texto. 
Vamos supor que voc� est� digitando um texto em um editor de texto simples.
Cada vez que voc� digita uma palavra ou uma frase e pressiona "Enter", o texto � adicionado � pilha de a��es. 
Se voc� cometer um erro ou decidir desfazer sua �ltima a��o, o editor de texto simplesmente desempilha a �ltima a��o
(ou seja, a �ltima palavra ou frase digitada) e a remove do texto.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TEXT_LENGTH 100  // Define o comprimento m�ximo do texto

struct Pilha {
    char texto[MAX_TEXT_LENGTH];  // Array para armazenar o texto
    struct Pilha *prox;  // Ponteiro para o pr�ximo item na pilha
};

struct Pilha *topo = NULL;  // Ponteiro para o topo da pilha, inicializado como NULL indicando pilha vazia

void push(char *texto) {
    struct Pilha *novo = (struct Pilha*)malloc(sizeof(struct Pilha));  // Aloca mem�ria para um novo item da pilha
    if (novo == NULL) {  // Verifica se a aloca��o de mem�ria foi bem sucedida
        printf("Erro: n�o foi poss�vel alocar mem�ria.\n");  // Imprime uma mensagem de erro
        exit(1);  // Sai do programa com c�digo de erro
    }
    strcpy(novo->texto, texto);  // Copia o texto fornecido para o novo item da pilha
    novo->prox = topo;  // Define o pr�ximo item da pilha como o antigo topo
    topo = novo;  // Atualiza o topo da pilha para apontar para o novo item
}

void pop() {
    if (topo == NULL) {  // Verifica se a pilha est� vazia
        printf("Erro: pilha vazia, nada para desfazer.\n");  // Imprime uma mensagem de erro
        return;  // Retorna da fun��o
    }
    struct Pilha *temp = topo;  // Cria um ponteiro tempor�rio apontando para o topo da pilha
    topo = topo->prox;  // Atualiza o topo da pilha para apontar para o pr�ximo item
    free(temp);  // Libera a mem�ria do item removido
}

void mostrarTextoAtual() {
    if (topo == NULL) {  // Verifica se a pilha est� vazia
        printf("Texto atual: [vazio]\n");  // Imprime uma mensagem indicando que o texto est� vazio
        return;  // Retorna da fun��o
    }
    printf("Texto atual: %s\n", topo->texto);  // Imprime o texto atual na pilha
}

int main() {
    int opcao;  // Vari�vel para armazenar a op��o do usu�rio
    char textoDigitado[MAX_TEXT_LENGTH];  // Array para armazenar o texto digitado pelo usu�rio

    while (1) {  // Loop infinito para exibir o menu repetidamente
        printf("\n1- Digitar texto\n");  // Op��o para digitar texto
        printf("2- Desfazer (undo)\n");  // Op��o para desfazer a �ltima a��o
        printf("3- Mostrar texto atual\n");  // Op��o para mostrar o texto atual na pilha
        printf("4- Sair\n");  // Op��o para sair do programa
        printf("Opcao? ");  // Solicita ao usu�rio que escolha uma op��o
        scanf("%d", &opcao);  // L� a op��o escolhida pelo usu�rio

        switch (opcao) {  // Inicia o bloco switch para lidar com diferentes op��es
            case 1:
                printf("Digite o texto: ");  // Solicita ao usu�rio que digite o texto
                scanf(" %[^\n]", textoDigitado);  // L� uma linha de texto incluindo espa�os
                push(textoDigitado);  // Adiciona o texto � pilha
                break;
            case 2:
                pop();  // Desfaz a �ltima a��o
                break;
            case 3:
                mostrarTextoAtual();  // Mostra o texto atual na pilha
                break;
            case 4:
                printf("Saindo...\n");  // Mensagem indicando que o programa est� sendo encerrado
                exit(0);  // Sai do programa sem erros
            default:
                printf("Opcao invalida!\n");  // Mensagem indicando que a op��o escolhida � inv�lida
        }
    }

    return 0;  // Retorna 0 para indicar que o programa foi executado com sucesso
}

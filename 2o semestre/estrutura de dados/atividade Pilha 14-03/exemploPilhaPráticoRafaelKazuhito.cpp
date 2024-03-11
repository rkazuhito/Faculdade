/*
Rafael Kazuhito Vidal Beltrão

	Um exemplo prático de uma pilha pode ser a função de desfazer (undo) em um editor de texto. 
Vamos supor que você está digitando um texto em um editor de texto simples.
Cada vez que você digita uma palavra ou uma frase e pressiona "Enter", o texto é adicionado à pilha de ações. 
Se você cometer um erro ou decidir desfazer sua última ação, o editor de texto simplesmente desempilha a última ação
(ou seja, a última palavra ou frase digitada) e a remove do texto.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TEXT_LENGTH 100  // Define o comprimento máximo do texto

struct Pilha {
    char texto[MAX_TEXT_LENGTH];  // Array para armazenar o texto
    struct Pilha *prox;  // Ponteiro para o próximo item na pilha
};

struct Pilha *topo = NULL;  // Ponteiro para o topo da pilha, inicializado como NULL indicando pilha vazia

void push(char *texto) {
    struct Pilha *novo = (struct Pilha*)malloc(sizeof(struct Pilha));  // Aloca memória para um novo item da pilha
    if (novo == NULL) {  // Verifica se a alocação de memória foi bem sucedida
        printf("Erro: não foi possível alocar memória.\n");  // Imprime uma mensagem de erro
        exit(1);  // Sai do programa com código de erro
    }
    strcpy(novo->texto, texto);  // Copia o texto fornecido para o novo item da pilha
    novo->prox = topo;  // Define o próximo item da pilha como o antigo topo
    topo = novo;  // Atualiza o topo da pilha para apontar para o novo item
}

void pop() {
    if (topo == NULL) {  // Verifica se a pilha está vazia
        printf("Erro: pilha vazia, nada para desfazer.\n");  // Imprime uma mensagem de erro
        return;  // Retorna da função
    }
    struct Pilha *temp = topo;  // Cria um ponteiro temporário apontando para o topo da pilha
    topo = topo->prox;  // Atualiza o topo da pilha para apontar para o próximo item
    free(temp);  // Libera a memória do item removido
}

void mostrarTextoAtual() {
    if (topo == NULL) {  // Verifica se a pilha está vazia
        printf("Texto atual: [vazio]\n");  // Imprime uma mensagem indicando que o texto está vazio
        return;  // Retorna da função
    }
    printf("Texto atual: %s\n", topo->texto);  // Imprime o texto atual na pilha
}

int main() {
    int opcao;  // Variável para armazenar a opção do usuário
    char textoDigitado[MAX_TEXT_LENGTH];  // Array para armazenar o texto digitado pelo usuário

    while (1) {  // Loop infinito para exibir o menu repetidamente
        printf("\n1- Digitar texto\n");  // Opção para digitar texto
        printf("2- Desfazer (undo)\n");  // Opção para desfazer a última ação
        printf("3- Mostrar texto atual\n");  // Opção para mostrar o texto atual na pilha
        printf("4- Sair\n");  // Opção para sair do programa
        printf("Opcao? ");  // Solicita ao usuário que escolha uma opção
        scanf("%d", &opcao);  // Lê a opção escolhida pelo usuário

        switch (opcao) {  // Inicia o bloco switch para lidar com diferentes opções
            case 1:
                printf("Digite o texto: ");  // Solicita ao usuário que digite o texto
                scanf(" %[^\n]", textoDigitado);  // Lê uma linha de texto incluindo espaços
                push(textoDigitado);  // Adiciona o texto à pilha
                break;
            case 2:
                pop();  // Desfaz a última ação
                break;
            case 3:
                mostrarTextoAtual();  // Mostra o texto atual na pilha
                break;
            case 4:
                printf("Saindo...\n");  // Mensagem indicando que o programa está sendo encerrado
                exit(0);  // Sai do programa sem erros
            default:
                printf("Opcao invalida!\n");  // Mensagem indicando que a opção escolhida é inválida
        }
    }

    return 0;  // Retorna 0 para indicar que o programa foi executado com sucesso
}

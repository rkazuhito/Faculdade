#include <stdio.h> //biblioteca para entrada e sa�da
#include <stdlib.h> //biblioteca para aloca��o

struct Node{ //estrutura de n�
 int num; //cada n� contem um num
 struct Node *prox; //ponteiro para o proximo n�
}; 
typedef struct Node node; //defini��o do n� - node

int tam; //var global para o tamanho da lista

void inicia(node *LISTA);  //Esses s�o os prot�tipos das fun��es que ser�o definidas posteriormente no c�digo. Eles fornecem uma descri��o dos tipos de argumentos e valores de retorno de cada fun��o.
int menu(void);
void opcao(node *LISTA, int op);
node *criaNo();
void insereFim(node *LISTA);
void insereInicio(node *LISTA);
void exibe(node *LISTA);
void libera(node *LISTA);
void insere (node *LISTA);
node *retiraInicio(node *LISTA);
node *retiraFim(node *LISTA);
node *retira(node *LISTA);


int main(void) //fun��o principal de execu��o do programa
{
 node *LISTA = (node *) malloc(sizeof(node));  //alocacao do n� inicial
 if(!LISTA){ //verifica se a alocacao foi possivel, caso n seja, entra no if
  printf("Sem memoria disponivel!\n");
  exit(1);
 }else{ //se for alocado, inicia a lista
 inicia(LISTA); //funcao para comecar a lista
 int opt; //variavel de opcao
 
 do{ //loop de giro principal do programa
  opt=menu();
  opcao(LISTA,opt);
 }while(opt);

 free(LISTA); //libera a mem�ria alocada
 return 0;
 }
}

void inicia(node *LISTA) //inicia a lista
{
 LISTA->prox = NULL; //indica o proximo n� como vazio, lista esta vazia
 tam=0; //tamanho zeo = lista vazia
}

int menu(void) //funcao para fazer o menu
{
 int opt;
 
 printf("Escolha a opcao\n"); //menu sendo exibido na tela
 printf("0. Sair\n");
 printf("1. Zerar lista\n");
 printf("2. Exibir lista\n");
 printf("3. Adicionar node no inicio\n");
 printf("4. Adicionar node no final\n");
 printf("5. Escolher onde inserir\n");
 printf("6. Retirar do inicio\n");
 printf("7. Retirar do fim\n");
 printf("8. Escolher de onde tirar\n");
 printf("Opcao: "); 
 scanf("%d", &opt); //le a opcao escolhida pelo usuario
 
 return opt; // Retorna a op��o escolhida pelo usu�rio
}

void opcao(node *LISTA, int op) { // Fun��o para executar a opera��o escolhida pelo usu�rio
    node *tmp;
    switch(op) { // Realiza uma opera��o dependendo da op��o escolhida pelo usu�rio
        case 0: // Caso a op��o seja 0 (Sair), libera a mem�ria e encerra o programa            
            libera(LISTA);
            break;
        case 1: // Caso a op��o seja 1 (Zerar lista), libera a mem�ria e reinicia a lista
            libera(LISTA);
            inicia(LISTA);
            break;
        case 2:// Caso a op��o seja 2 (Exibir lista), exibe os elementos da lista
            exibe(LISTA);
            break;
        case 3: // Caso a op��o seja 3 (Adicionar n� no in�cio), insere um n� no in�cio da lista
            insereInicio(LISTA);
            break;
        case 4: // Caso a op��o seja 4 (Adicionar n� no final), insere um n� no final da lista
            insereFim(LISTA);
            break;
        case 5: // Caso a op��o seja 5 (Escolher onde inserir), insere um n� em uma posi��o espec�fica
            insere(LISTA);
            break;
        case 6: // Caso a op��o seja 6 (Retirar do in�cio), retira um n� do in�cio da lista
            tmp = retiraInicio(LISTA);
            printf("Retirado: %3d\n\n", tmp->num);
            break;
        case 7:  // Caso a op��o seja 7 (Retirar do fim), retira um n� do fim da lista
            tmp = retiraFim(LISTA);
            printf("Retirado: %3d\n\n", tmp->num);
            break;
        case 8: // Caso a op��o seja 8 (Escolher de onde tirar), retira um n� de uma posi��o espec�fica
            tmp = retira(LISTA);
            printf("Retirado: %3d\n\n", tmp->num);
            break;
        default: // Se a op��o for inv�lida, exibe uma mensagem de erro
            printf("Comando invalido\n\n");
    }
}

// Fun��o para verificar se a lista est� vazia
int vazia(node *LISTA) {
    // Verifica se o pr�ximo n� do n� inicial � NULL
    if (LISTA->prox == NULL)
        return 1; // Retorna 1 se a lista estiver vazia
    else
        return 0; // Retorna 0 se a lista n�o estiver vazia
}
// Fun��o para alocar dinamicamente um novo n�
node *aloca() {
    // Declara��o de um ponteiro para um novo n�
    node *novo = (node *) malloc(sizeof(node));
    // Verifica se a aloca��o de mem�ria foi bem-sucedida
    if (!novo) {
        // Se n�o houver mem�ria dispon�vel, exibe uma mensagem de erro e encerra o programa
        printf("Sem memoria disponivel!\n");
        exit(1);
    } else {
        // Se a aloca��o for bem-sucedida, solicita ao usu�rio um n�mero para armazenar no novo n�
        printf("Novo elemento: ");
        scanf("%d", &novo->num);
        // Retorna o ponteiro para o novo n� alocado
        return novo;
    }
}

// Fun��o para inserir um n� no final da lista
void insereFim(node *LISTA) {
    // Aloca um novo n�
    node *novo = aloca();
    // Define o pr�ximo do novo n� como NULL, j� que ele ser� o �ltimo na lista
    novo->prox = NULL;

    // Verifica se a lista est� vazia
    if (vazia(LISTA))
        // Se a lista estiver vazia, o novo n� se torna o primeiro da lista
        LISTA->prox = novo;
    else {
        // Caso contr�rio, percorre a lista at� encontrar o �ltimo n�
        node *tmp = LISTA->prox;
        while (tmp->prox != NULL)
            tmp = tmp->prox;

        // Insere o novo n� ap�s o �ltimo n� encontrado
        tmp->prox = novo;
    }
    // Incrementa o tamanho da lista
    tam++;
}

// Fun��o para inserir um n� no in�cio da lista
void insereInicio(node *LISTA) {
    // Aloca um novo n�
    node *novo = aloca(); 
    // Guarda o endere�o do primeiro n� atual
    node *oldHead = LISTA->prox;

    // Faz o pr�ximo do novo n� apontar para o antigo primeiro n�
    LISTA->prox = novo;
    // Faz o pr�ximo do novo primeiro n� apontar para o antigo primeiro n�
    novo->prox = oldHead;

    // Incrementa o tamanho da lista
    tam++;
}


// Fun��o para exibir os elementos da lista
void exibe(node *LISTA) {
    // Limpa a tela do console
    system("clear");
    // Verifica se a lista est� vazia
    if (vazia(LISTA)) {
        // Se estiver vazia, exibe uma mensagem indicando que a lista est� vazia
        printf("Lista vazia!\n\n");
        return;
    }

    // Declara um ponteiro tempor�rio para percorrer a lista
    node *tmp;
    // Inicializa o ponteiro tempor�rio com o primeiro n� da lista
    tmp = LISTA->prox;
    // Exibe os elementos da lista e suas posi��es
    printf("Lista:");
    while (tmp != NULL) {
        printf("%5d", tmp->num);
        tmp = tmp->prox;
    }
    printf("\n        ");

    // Exibe setas indicando a ordem dos elementos
    int count;
    for (count = 0; count < tam; count++)
        printf("  ^  ");
    printf("\nOrdem:");
    for (count = 0; count < tam; count++)
        printf("%5d", count + 1);

    printf("\n\n");
}


// Fun��o para liberar a mem�ria alocada para os n�s da lista
void libera(node *LISTA) {
    // Verifica se a lista n�o est� vazia
    if (!vazia(LISTA)) {
        node *proxNode, *atual;
        // Inicializa o ponteiro atual com o primeiro n� da lista
        atual = LISTA->prox;
        // Enquanto houver n�s na lista
        while (atual != NULL) {
            // Guarda o pr�ximo n� da lista
            proxNode = atual->prox;
            // Libera a mem�ria alocada para o n� atual
            free(atual);
            // Atualiza o ponteiro atual para apontar para o pr�ximo n�
            atual = proxNode;
        }
    }
}


// Fun��o para inserir um n� em uma posi��o espec�fica da lista
void insere(node *LISTA) {
    int pos, count;
    // Solicita ao usu�rio a posi��o onde deseja inserir o n�
    printf("Em que posicao, [de 1 ate %d] voce deseja inserir: ", tam);
    scanf("%d", &pos);

    // Verifica se a posi��o fornecida � v�lida
    if (pos > 0 && pos <= tam) {
        // Se a posi��o for o in�cio da lista, insere no in�cio
        if (pos == 1)
            insereInicio(LISTA);
        else {
            node *atual = LISTA->prox, *anterior = LISTA;
            // Aloca um novo n�
            node *novo = aloca();

            // Percorre a lista at� encontrar a posi��o desejada
            for (count = 1; count < pos; count++) {
                anterior = atual;
                atual = atual->prox;
            }

            // Insere o novo n� na posi��o desejada
            anterior->prox = novo;
            novo->prox = atual;
            // Incrementa o tamanho da lista
            tam++;
        }
    } else {
        // Se a posi��o fornecida for inv�lida, exibe uma mensagem de erro
        printf("Elemento invalido\n\n");
    }
}
// Fun��o para retirar o primeiro n� da lista
node *retiraInicio(node *LISTA) {
    // Verifica se a lista est� vazia
    if (LISTA->prox == NULL) {
        // Se estiver vazia, exibe uma mensagem informando que a lista j� est� vazia
        printf("Lista ja esta vazia\n");
        return NULL;
    } else {
        // Se n�o estiver vazia, guarda o endere�o do primeiro n�
        node *tmp = LISTA->prox;
        // Atualiza o ponteiro do n� inicial para apontar para o pr�ximo n�
        LISTA->prox = tmp->prox;
        // Decrementa o tamanho da lista
        tam--;
        // Retorna o n� removido
        return tmp;
    }
}
// Fun��o para retirar o �ltimo n� da lista
node *retiraFim(node *LISTA) {
    // Verifica se a lista est� vazia
    if (LISTA->prox == NULL) {
        // Se estiver vazia, exibe uma mensagem informando que a lista j� est� vazia
        printf("Lista ja vazia\n\n");
        return NULL;
    } else {
        // Declara dois ponteiros para percorrer a lista
        node *ultimo = LISTA->prox, *penultimo = LISTA;

        // Percorre a lista at� encontrar o �ltimo n�
        while (ultimo->prox != NULL) {
            penultimo = ultimo;
            ultimo = ultimo->prox;
        }

        // Atualiza o ponteiro do n� anterior ao �ltimo para apontar para NULL
        penultimo->prox = NULL;
        // Decrementa o tamanho da lista
        tam--;
        // Retorna o �ltimo n� removido
        return ultimo;
    }
}

// Fun��o para retirar um n� de uma posi��o espec�fica da lista
node *retira(node *LISTA) {
    int opt, count;
    // Solicita ao usu�rio a posi��o do n� que deseja retirar
    printf("Que posicao, [de 1 ate %d] voce deseja retirar: ", tam);
    scanf("%d", &opt);

    // Verifica se a posi��o fornecida � v�lida
    if (opt > 0 && opt <= tam) {
        // Se a posi��o for o in�cio da lista, remove o primeiro n�
        if (opt == 1)
            return retiraInicio(LISTA);
        else {
            node *atual = LISTA->prox, *anterior = LISTA;
            
            // Percorre a lista at� encontrar a posi��o desejada
            for (count = 1; count < opt; count++) {
                anterior = atual;
                atual = atual->prox;
            }

            // Atualiza o ponteiro do n� anterior ao n� a ser retirado para apontar para o pr�ximo n� ap�s o n� a ser retirado
            anterior->prox = atual->prox;
            // Decrementa o tamanho da lista
            tam--;
            // Retorna o n� retirado
            return atual;
        }
    } else {
        // Se a posi��o fornecida for inv�lida, exibe uma mensagem de erro e retorna NULL
        printf("Elemento invalido\n\n");
        return NULL;
    }
}

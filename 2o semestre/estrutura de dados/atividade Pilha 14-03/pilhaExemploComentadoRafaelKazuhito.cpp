//Rafael Kazuhito Vidal Beltrão

#include <stdio.h> // funções de entrada e saída padrão, como printf() e scanf()
#include <conio.h> // fornece funções para controle de console
#include <stdlib.h> // fornece acesso a funções como malloc() e exit()

struct Pilha { //estrutura da pilha. os elementos serão float
	int topo; // Índice do topo da pilha
	int capa; // Capacidade máxima da pilha
	float *pElem; // Ponteiro para o primeiro elemento da pilha
};

void criarpilha( struct Pilha *p, int c ){ // inicializa a pilha
   p->topo = -1; // Inicializa o topo como -1, indicando que a pilha está vazia
   p->capa = c; // Define a capacidade da pilha
   p->pElem = (float*) malloc (c * sizeof(float)); // Aloca memória para a pilha
}
////   função  -  testa se a pilha está vazia
int estavazia ( struct Pilha *p ){ //verifica se a pilha está vazia. Retorna 1 se estiver vazia e 0 caso contrário.
   if( p-> topo == -1 )
      return 1;   // true - vazio
   else
      return 0;   // false - não vazia
}

///   função   testa se a pilha está  cheia
int estacheia ( struct Pilha *p ){ //verifica se a pilha está cheia. Retorna 1 se estiver cheia e 0 caso contrário
	if (p->topo == p->capa - 1)
		return 1; // true - cheia
	else
		return 0; // false - não cheia
}
////   função   emp
void empilhar ( struct Pilha *p, float v){ //adiciona um elemento à pilha. Recebe um ponteiro para a pilha e um valor v a ser adicionado
	p->topo++; // Incrementa o topo da pilha (muda a posição)
	p->pElem [p->topo] = v; // Armazena o valor na nova posição do topo
}

float desempilhar ( struct Pilha *p ){ // remove e retorna o elemento no topo da pilha.
   float aux = p->pElem [p->topo]; // Salva o valor do topo
   p->topo--; // Decrementa o topo, aponta para o penúltimo
   return aux; // Retorna o valor removido para exibi-lo na tela
}

float retornatopo ( struct Pilha *p ){ //mostra o que tem no topo da pilha
   return p->pElem [p->topo]; // Retorna o valor do topo da pilha
}

int main(){
	struct Pilha minhapilha; // variável para armazenar a pilha
	int capacidade, op; // Declara variáveis para armazenar a capacidade da pilha e a opção do usuário
	float valor; // Declara uma variável para armazenar valores a serem empilhados
	printf( "\nCapacidade da pilha? " );
	scanf( "%d", &capacidade ); // Obtém a capacidade da pilha a partir do usuário
	criarpilha (&minhapilha, capacidade); // Inicializa a pilha com a capacidade especificada
	while( 1 ){ /* loop infinito */
		// Menu de opções
		printf("\n1- empilhar (push)\n");
		printf("2- desempilhar (POP)\n");
		printf("3- Mostrar o topo \n");
		printf("4- sair\n");
		printf("\nopcao? ");
		scanf("%d", &op); // Obtém a opção do usuário
		switch (op){
			case 1: // Opção para empilhar um valor
				if( estacheia( &minhapilha ) == 1 ) // Verifica se a pilha está cheia
					printf("\nPILHA CHEIA! \n"); // Exibe mensagem de pilha cheia
				else {
					printf("\nVALOR? "); //caso não esteja cheia poderá adicionar um valor
					scanf("%f", &valor); // Obtém o valor a ser empilhado
					empilhar (&minhapilha, valor); // Empilha o valor
				}
				break;
			case 2: // Opção para desempilhar um valor
				if ( estavazia(&minhapilha) == 1 ) // Verifica se a pilha está vazia
					printf( "\nPILHA VAZIA! \n" ); // Exibe mensagem de pilha vazia
				else{								//caso não esteja vazia será possível desempilha um valor
					valor = desempilhar (&minhapilha); // Desempilha um valor
					printf ( "\n%.1f DESEMPILHADO!\n", valor ); // Exibe o valor desempilhado
				}
				break;
			case 3: // Opção para mostrar o topo da pilha
				if ( estavazia (&minhapilha) == 1 ) // Verifica se a pilha está vazia
					printf( "\nPILHA VAZIA!\n" ); // Exibe mensagem de pilha vazia
				else {  							//caso não esteja vazia
					valor = retornatopo (&minhapilha); // Obtém o valor do topo
					printf ( "\nTOPO: %.1f\n", valor ); // Exibe o valor do topo
				}
				break;
			case 4: // Opção para sair do programa
				exit(0); // Encerra o programa
			default: // Opção inválida
				printf( "\nOPCAO INVALIDA! \n" ); // Exibe mensagem de opção inválida
		}
	}
}

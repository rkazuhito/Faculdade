//Rafael Kazuhito Vidal Beltr�o

#include <stdio.h> // fun��es de entrada e sa�da padr�o, como printf() e scanf()
#include <conio.h> // fornece fun��es para controle de console
#include <stdlib.h> // fornece acesso a fun��es como malloc() e exit()

struct Pilha { //estrutura da pilha. os elementos ser�o float
	int topo; // �ndice do topo da pilha
	int capa; // Capacidade m�xima da pilha
	float *pElem; // Ponteiro para o primeiro elemento da pilha
};

void criarpilha( struct Pilha *p, int c ){ // inicializa a pilha
   p->topo = -1; // Inicializa o topo como -1, indicando que a pilha est� vazia
   p->capa = c; // Define a capacidade da pilha
   p->pElem = (float*) malloc (c * sizeof(float)); // Aloca mem�ria para a pilha
}
////   fun��o  -  testa se a pilha est� vazia
int estavazia ( struct Pilha *p ){ //verifica se a pilha est� vazia. Retorna 1 se estiver vazia e 0 caso contr�rio.
   if( p-> topo == -1 )
      return 1;   // true - vazio
   else
      return 0;   // false - n�o vazia
}

///   fun��o   testa se a pilha est�  cheia
int estacheia ( struct Pilha *p ){ //verifica se a pilha est� cheia. Retorna 1 se estiver cheia e 0 caso contr�rio
	if (p->topo == p->capa - 1)
		return 1; // true - cheia
	else
		return 0; // false - n�o cheia
}
////   fun��o   emp
void empilhar ( struct Pilha *p, float v){ //adiciona um elemento � pilha. Recebe um ponteiro para a pilha e um valor v a ser adicionado
	p->topo++; // Incrementa o topo da pilha (muda a posi��o)
	p->pElem [p->topo] = v; // Armazena o valor na nova posi��o do topo
}

float desempilhar ( struct Pilha *p ){ // remove e retorna o elemento no topo da pilha.
   float aux = p->pElem [p->topo]; // Salva o valor do topo
   p->topo--; // Decrementa o topo, aponta para o pen�ltimo
   return aux; // Retorna o valor removido para exibi-lo na tela
}

float retornatopo ( struct Pilha *p ){ //mostra o que tem no topo da pilha
   return p->pElem [p->topo]; // Retorna o valor do topo da pilha
}

int main(){
	struct Pilha minhapilha; // vari�vel para armazenar a pilha
	int capacidade, op; // Declara vari�veis para armazenar a capacidade da pilha e a op��o do usu�rio
	float valor; // Declara uma vari�vel para armazenar valores a serem empilhados
	printf( "\nCapacidade da pilha? " );
	scanf( "%d", &capacidade ); // Obt�m a capacidade da pilha a partir do usu�rio
	criarpilha (&minhapilha, capacidade); // Inicializa a pilha com a capacidade especificada
	while( 1 ){ /* loop infinito */
		// Menu de op��es
		printf("\n1- empilhar (push)\n");
		printf("2- desempilhar (POP)\n");
		printf("3- Mostrar o topo \n");
		printf("4- sair\n");
		printf("\nopcao? ");
		scanf("%d", &op); // Obt�m a op��o do usu�rio
		switch (op){
			case 1: // Op��o para empilhar um valor
				if( estacheia( &minhapilha ) == 1 ) // Verifica se a pilha est� cheia
					printf("\nPILHA CHEIA! \n"); // Exibe mensagem de pilha cheia
				else {
					printf("\nVALOR? "); //caso n�o esteja cheia poder� adicionar um valor
					scanf("%f", &valor); // Obt�m o valor a ser empilhado
					empilhar (&minhapilha, valor); // Empilha o valor
				}
				break;
			case 2: // Op��o para desempilhar um valor
				if ( estavazia(&minhapilha) == 1 ) // Verifica se a pilha est� vazia
					printf( "\nPILHA VAZIA! \n" ); // Exibe mensagem de pilha vazia
				else{								//caso n�o esteja vazia ser� poss�vel desempilha um valor
					valor = desempilhar (&minhapilha); // Desempilha um valor
					printf ( "\n%.1f DESEMPILHADO!\n", valor ); // Exibe o valor desempilhado
				}
				break;
			case 3: // Op��o para mostrar o topo da pilha
				if ( estavazia (&minhapilha) == 1 ) // Verifica se a pilha est� vazia
					printf( "\nPILHA VAZIA!\n" ); // Exibe mensagem de pilha vazia
				else {  							//caso n�o esteja vazia
					valor = retornatopo (&minhapilha); // Obt�m o valor do topo
					printf ( "\nTOPO: %.1f\n", valor ); // Exibe o valor do topo
				}
				break;
			case 4: // Op��o para sair do programa
				exit(0); // Encerra o programa
			default: // Op��o inv�lida
				printf( "\nOPCAO INVALIDA! \n" ); // Exibe mensagem de op��o inv�lida
		}
	}
}

/*
Implementa��o de fila simples
*/

#include <iostream>
#define tamanho 5
using namespace std;

// Define a estrutura que ser� a fila
// A estrutura armazena a indica��o do in�cio e final da fila e um vetor com os itens (valores) da fila
typedef struct {
    int ini = 0; // Indica o �ndice do primeiro elemento na fila
    int fim = 0; // Indica o pr�ximo �ndice dispon�vel para adicionar um elemento
    int item[tamanho]; // Array que armazena os elementos da fila
} FILA;

// Retorna verdadeiro se a fila estiver vazia, falso caso contr�rio
bool filaVazia(FILA p) {
    if (p.ini == p.fim) { // Se o �ndice de in�cio � igual ao �ndice de fim, a fila est� vazia
        return true;
    } else {
        return false;
    }
}

// Retorna verdadeiro se a fila estiver cheia, falso caso contr�rio
bool filaCheia(FILA p) {
    int tam = sizeof(p.item) / sizeof(int); // Determina o tamanho do vetor de itens da fila

    if (p.fim < tam) { // Se o �ndice de fim for menor que o tamanho m�ximo, a fila n�o est� cheia
        return false;
    } else {
        return true;
    }
}

// Adiciona um valor na fila
void enfilera(FILA &p, int x) {
    p.item[p.fim++] = x; // Adiciona o valor na posi��o do �ndice de fim e incrementa o �ndice de fim
}

// Remove e retorna o valor da fila
int desenfilera(FILA &p) {
    return (p.item[p.ini++]); // Retorna o valor na posi��o do �ndice de in�cio e incrementa o �ndice de in�cio
}

// Mostra os valores armazenados na fila
void mostraFila(FILA p) {
    cout << "Valores da fila: ";
    for (int i = p.ini; i < p.fim; i++) { // Itera sobre os elementos da fila do in�cio at� o fim
        cout << p.item[i] << " "; // Imprime cada elemento da fila
    }
    cout << "\n";
}

// Fun��o principal para testar a implementa��o
int main() {
    FILA s; // Criar a fila

    // Verificar se a fila est� vazia
    if (filaVazia(s)) {
        cout << "A fila est� vazia." << endl;
    } else {
        cout << "A fila n�o est� vazia." << endl;
    }

    // Enfileira um valor e verifica se a fila est� vazia
    enfilera(s, 10);
    if (filaVazia(s)) {
        cout << "A fila est� vazia." << endl;
    } else {
        cout << "A fila n�o est� vazia." << endl;
    }

    // Insere 3 elementos na fila
    enfilera(s, 20);
    enfilera(s, 30);
    enfilera(s, 40);

    // Mostra os valores da fila
    mostraFila(s);

    // Verifica se a fila est� cheia
    if (filaCheia(s)) {
        cout << "A fila est� cheia." << endl;
    } else {
        cout << "A fila n�o est� cheia." << endl;
    }

    // Enfileira um valor e verifica se a fila est� cheia
    enfilera(s, 50);
    mostraFila(s);
    if (filaCheia(s)) {
        cout << "A fila est� cheia." << endl;
    } else {
        cout << "A fila n�o est� cheia." << endl;
    }

    // Desenfileira e mostra o valor desenfileirado
    cout << "Valor removido da fila: " << desenfilera(s) << endl;

    mostraFila(s);

    // Verifica se a fila est� cheia
    if (filaCheia(s)) {
        cout << "A fila est� cheia." << endl;
    } else {
        cout << "A fila n�o est� cheia." << endl;
    }

    return 0;
}


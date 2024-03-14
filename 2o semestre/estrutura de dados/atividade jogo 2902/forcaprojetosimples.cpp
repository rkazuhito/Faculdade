#include <iostream>
#include <stdlib.h> //pro system cls

using namespace std;

int main(){
	char palavra[30],letra[1],secreta[30];
	int tam,i,chances,acertos;
	bool acerto=false; //verifica se a letra digitada esta certa ou errada
	
	chances=6;
	tam=0;
	i=0;
	acertos=0; //conta a qtd de acertos
	
	cout << "Digite a palavra da forca: ";
	cin >> palavra;
	system("cls"); //comando para limpar a tela
	
	while(palavra[i]!= '\0'){ //\0 é a posição do enter, ou seja, vai percorrer a string até chegar no fim da palavra
		i++;
		tam++;
	}
	
	return 0;
}

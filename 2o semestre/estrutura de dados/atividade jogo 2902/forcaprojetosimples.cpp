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
	
	while(palavra[i] != '\0'){ //\0 é a posição do enter, ou seja, vai percorrer a string até chegar no fim da palavra
		i++;
		tam++;
	}
	
	for(i=0;i<30;i++){
		secreta[i] = '_';
	}
	
	while((chances>0)&&(acertos<tam)){ //rotina do jogo será toda nesse loop
		cout << "Canches restantes: "<< chances << "\n";
		cout << "Palavra secreta: ";
		for(i=0; i<tam; i++){
			cout <<secreta[i];
		}
		cout << "\n\n Digite uma letra: ";
		cin >> letra[0];
		for (i=0;i<tam;i++){
			if(palavra[i]==letra[0]){
				acerto=true;
				secreta[i]=palavra[i];
				acertos++;
			}
		}
		if(!acerto){
			chances--;
		}
		acerto=false; //refaz a verificação do acerto
		system ("cls");
	}
	
	if(acertos==tam){
		cout << "Você venceu, parabens!";
	}else{
		cout <<"que pena, perdeu";
	}
	system("pause");
	return 0;
}

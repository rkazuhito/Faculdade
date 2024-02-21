//Exercício feito por Rafael Kazuhito /

#include <stdio.h> //biblioteca para entrada e saída de dados 
#include <math.h> //biblioteca de funções matemáticas
#include <iostream> //biblioteca para entrada e saída de dados c++
#include <locale.h> //biblioteca para acentuação

using namespace std; //standard

int main(){ //função main
    setlocale(LC_ALL,"Portuguese"); // habilita acentuação 
    int idade,c;
    for (c=1;c<5;c++){
        cout << "informe a idade: ";
        scanf("%d",&idade);
        if(idade>17){
            cout<<"Maior de idade\n";
        }else{
            cout<<"Menor de idade\n";
        }
    }
	  system("PAUSE > null");  //para a execução do programa
	  return 0;
}
//Exercício feito por Rafael Kazuhito /

#include <stdio.h> //biblioteca para entrada e saída de dados 
#include <math.h> //biblioteca de funções matemáticas
#include <iostream> //biblioteca para entrada e saída de dados c++
#include <locale.h> //biblioteca para acentuação

using namespace std; //standard

int main(){ //função main
    setlocale(LC_ALL,"Portuguese"); // habilita acentuação 
    int c,contm,contf;
    char sexo;
    char nome[50];
    contm=0;
    contf=0;
    for(c=1;c<6;c++){
        cout <<"Informe o nome ";
        cin >> nome;
        cout <<"O sexo: (m/f)";
        cin >> sexo;
        if(sexo=='m'){
            contm++;
        }else if(sexo=='f'){
            contf++;
        }
    }
    cout <<"masc = " << contm << " fem = " <<contf;
	system("PAUSE > null");  //para a execução do programa
	return 0;
}
//Exercício feito por Rafael Kazuhito /

#include <stdio.h> //biblioteca para entrada e saída de dados 
#include <math.h> //biblioteca de funções matemáticas
#include <iostream> //biblioteca para entrada e saída de dados c++
#include <locale.h> //biblioteca para acentuação

using namespace std; //standard

int main(){ //função main
    setlocale(LC_ALL,"Portuguese"); // habilita acentuação 
    int ano;
    float valorI,valorF,valorTot=0,carros=0;
    char verifica;
    cout << "Compra múltipla de carros\n";
    do {
        cout << "Qual o ano do carro?";
        cin >> ano;
        cout << "Informe o valor: ";
        cin >> valorI;
        if(ano<=2000){
            valorF= valorI*0.85;
        } else{
            valorF= valorI*0.93;
        }
        valorTot=valorTot+valorF;
        carros++;
        cout <<"Deseja cadastrar mais uma compra? (s/n)";
        cin >> verifica;
    } while (verifica!='n');
    cout<<"Você comprou "<< carros <<" carros e gastou um total de, "<< valorTot <<"reais";
	system("PAUSE > null");  //para a execução do programa
	return 0;
}
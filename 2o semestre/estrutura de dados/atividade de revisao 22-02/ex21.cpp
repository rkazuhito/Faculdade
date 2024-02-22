//Exercício feito por Rafael Kazuhito /

#include <stdio.h> //biblioteca para entrada e saída de dados 
#include <math.h> //biblioteca de funções matemáticas
#include <iostream> //biblioteca para entrada e saída de dados c++
#include <locale.h> //biblioteca para acentuação

using namespace std; //standard

int main(){ //função main
    setlocale(LC_ALL,"Portuguese"); // habilita acentuação 
    int idade,aptos=0,naptos=0;
    char nome[20],sexo,saude,verifica;
    do{
        cout << "Infomer o nome: ";
        cin >> nome;
        cout << "Infomer o sexo: (f/m)";
        cin >> sexo;
        cout << "Qual estado de saúde? (b = bom/r = ruim)";
        cin >> saude;
        cout << "Infomer a idade: ";
        cin >> idade;
        if(sexo=='m' && saude=='b' && idade>17){
            cout <<"apto\n";
            aptos++;
        }else{
            cout<<"inapto\n";
            naptos++;
        }
        cout <<"Deseja cadastrar mais alguém?";
        cin >> verifica;
    }while(verifica!='n');
    cout << "Você cadastrou "<< aptos<<" aptos e "<<naptos<<" inaptos";
	system("PAUSE > null");  //para a execução do programa
	return 0;
}
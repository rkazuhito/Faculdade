//Exercício feito por Geovana Piccioli  / Nathalie Tellechea  /  Rafael Kazuhito /

#include <stdio.h> //biblioteca para entrada e saída de dados 
#include <math.h> //biblioteca de funções matemáticas
#include <iostream> //biblioteca para entrada e saída de dados c++
#include <locale.h> //biblioteca para acentuação

main(){ //função main
    setlocale(LC_ALL,"Portuguese"); // habilita acentuação 
    float val,valTot; //declaração de variáveis float
    printf("Infome o valor depositado: "); //saída de dados
    scanf("%f",&val); //entrada de dados
    valTot=val+val*0.007; //calcula o rendimento de 0,7% em um mês
    printf("Após 1 mês o valor será de R$%10.2f",valTot); //mprime na tela
    system("PAUSE>null"); //para a execução do programa
}
//Exercício feito por Geovana Piccioli  / Nathalie Tellechea  /  Rafael Kazuhito /

#include <stdio.h> //biblioteca para entrada e saída de dados 
#include <math.h> //biblioteca de funções matemáticas
#include <iostream> //biblioteca para entrada e saída de dados c++
#include <locale.h> //biblioteca para acentuação

main(){ //função main
    setlocale(LC_ALL,"Portuguese"); // habilita acentuação 
    float cotacao,dolar; //declaração de variáveis float
    printf("Qual a cotação do Dolar? "); //saída de dados
    scanf("%f",&cotacao); //entrada de dados
    printf("Quantos dolares gostaria de converter?");
    scanf("%f",&dolar);
    printf("Conversao para R$:%10.2f",dolar/cotacao); //converte e imprime na tela 
    system("PAUSE>null"); //para a execução do programa
}
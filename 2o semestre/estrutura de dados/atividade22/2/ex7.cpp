//Exercício feito por Geovana Piccioli  / Nathalie Tellechea  /  Rafael Kazuhito /

#include <stdio.h> //biblioteca para entrada e saída de dados 
#include <math.h> //biblioteca de funções matemáticas
#include <iostream> //biblioteca para entrada e saída de dados c++
#include <locale.h> //biblioteca para acentuação

main(){ //função main
    setlocale(LC_ALL,"Portuguese"); // habilita acentuação 
    float tc,tf; //declaração de variáveis float
    printf("Informe a temperatura em Celsius"); //saída de dados
    scanf("%f",&tc); //entrada de dados
    tf=(9*tc+160)/5; //transforma a temperatura de celsius para fahrenheit
    printf("A temperatura em Fahrenheit será de %3.2f",tf); //imprime o resultado
    system("PAUSE>null"); //para a execução do programa
}
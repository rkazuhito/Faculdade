//Exercício feito por Geovana Piccioli  / Nathalie Tellechea  /  Rafael Kazuhito /

#include <stdio.h> //biblioteca para entrada e saída de dados 
#include <math.h> //biblioteca de funções matemáticas
#include <iostream> //biblioteca para entrada e saída de dados c++
#include <locale.h> //biblioteca para acentuação

main(){ //função main
    setlocale(LC_ALL,"Portuguese"); // habilita acentuação 
    float valor; //declaração de variáveis float
    printf("Informe o valor da compra: "); //saída de dados
    scanf("%f",&valor); //entrada de dados
    printf("a prestação será de 5x de %5.2f reais",valor/5); //calcula a prestação e imprime na tela
    system("PAUSE>null"); //para a execução do programa
}
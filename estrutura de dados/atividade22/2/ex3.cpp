//Exercício feito por Geovana Piccioli  / Nathalie Tellechea  /  Rafael Kazuhito /

#include <stdio.h> //biblioteca para entrada e saída de dados 
#include <math.h> //biblioteca de funções matemáticas
#include <iostream> //biblioteca para entrada e saída de dados c++
#include <locale.h> //biblioteca para acentuação

main(){ //função main
    setlocale(LC_ALL,"Portuguese"); // habilita acentuação 
    float x,vol; //declaração de variáveis float
    printf("Informe a distância percorrida (km): "); //saída de dados
    scanf("%f",&x); //entrada de dados
    printf("Informe a quantidade de combustível consumida: ");
    scanf("%f",&vol);
    printf("O consumo médio do carro será de %4.2f",x/vol); //calcula o consumo e imprime o resultado
    system("PAUSE>null"); //para a execução do programa
}

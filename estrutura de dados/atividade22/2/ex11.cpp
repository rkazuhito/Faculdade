//Exercício feito por Geovana Piccioli  / Nathalie Tellechea  /  Rafael Kazuhito /

#include <stdio.h> //biblioteca para entrada e saída de dados 
#include <math.h> //biblioteca de funções matemáticas
#include <iostream> //biblioteca para entrada e saída de dados c++
#include <locale.h> //biblioteca para acentuação

main(){ //função main
    setlocale(LC_ALL,"Portuguese"); // habilita acentuação 
    float custo, percentual, custoFinal; //declaração de variáveis float
    printf("Informe o preço de custo da mercadoria: (R$)"); //saída de dados
    scanf("%f",&custo); //entrada de dados
    printf("Informe o percentual de acréscimo para a venda: (%)");
    scanf("%f",&percentual);
    custoFinal = custo + (custo*percentual/100); //calcula o custo final
    printf("O valor final de venda será de %5.2f reais",custoFinal); //imprime na tela
    system("PAUSE>null"); //para a execução do programa
}
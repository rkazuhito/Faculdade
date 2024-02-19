//Exercício feito por Geovana Piccioli  / Nathalie Tellechea  /  Rafael Kazuhito /

#include <stdio.h> //biblioteca para entrada e saída de dados 
#include <math.h> //biblioteca de funções matemáticas
#include <iostream> //biblioteca para entrada e saída de dados c++
#include <locale.h> //biblioteca para acentuação

main(){ //função main
    setlocale(LC_ALL,"Portuguese"); // habilita acentuação 
    float n1,n2; //declaração de variáveis float
    printf("Informe o primeiro número: "); //saída de dados
    scanf("%f",&n1); //entrada de dados
    printf("Informe o segundo número: ");
    scanf("%f",&n2);
    printf("Soma= %10.2f",n1+n2); //executa a soma e imprime na tela
    system("PAUSE>null"); //para a execução do programa
}
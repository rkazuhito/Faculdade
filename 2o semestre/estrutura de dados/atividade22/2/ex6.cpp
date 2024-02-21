//Exercício feito por Geovana Piccioli  / Nathalie Tellechea  /  Rafael Kazuhito /

#include <stdio.h> //biblioteca para entrada e saída de dados 
#include <math.h> //biblioteca de funções matemáticas
#include <iostream> //biblioteca para entrada e saída de dados c++
#include <locale.h> //biblioteca para acentuação

main(){ //função main
    setlocale(LC_ALL,"Portuguese"); // habilita acentuação 
    int a,b,c; //declaração de variáveis float
    printf("Informe o valor de A: "); //saída de dados
    scanf("%d",&a); //entrada de dados
    printf("Informe o valor de B: ");
    scanf("%d",&b);
    c=a;//execução das trocas com uma terceira variável
    a=b;
    b=c;
    printf("a= %d \nb= %d",a,b); //imprime na tela
    system("PAUSE>null"); //para a execução do programa
}
//Exercício feito por Geovana Piccioli  / Nathalie Tellechea  /  Rafael Kazuhito /

#include <stdio.h> //biblioteca para entrada e saída de dados 
#include <math.h> //biblioteca de funções matemáticas
#include <iostream> //biblioteca para entrada e saída de dados c++
#include <locale.h> //biblioteca para acentuação

main(){ //função main
      setlocale(LC_ALL,"Portuguese"); // habilita acentuação 
      float cf,ccon,per,impst; //declaração de variáveis float
      printf("Digite o custo de fábrica: "); //saída de dados
      scanf("%f",&cf);  //entrada de dados 
      impst=(0.45*(cf)); //variavel recebe um valor
      per=((cf)+(impst))*0.28; //variavel recebe um valor
      ccon=((cf)+(impst)+(per)); //variavel recebe um valor
      printf("Custo do Consumidor:%1.2f",ccon); //imprime na tela o resultado
      system("PAUSE > null");  //para a execu��o do programa
      
}

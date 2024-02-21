//Exercício feito por Geovana Piccioli  / Nathalie Tellechea  /  Rafael Kazuhito /

#include <stdio.h> //biblioteca para entrada e saída de dados 
#include <math.h> //biblioteca de funções matemáticas
#include <iostream> //biblioteca para entrada e saída de dados c++
#include <locale.h> //biblioteca para acentuação

main(){ //função main
   setlocale(LC_ALL,"Portuguese"); // habilita acentuação 
   float n; //declaração de variáveis float
   printf("Informe um valor: ");
   scanf("%f",&n);
   if(n>=100 && n<=200)
      printf("o valor está no intervalo de 100 a 200");
   else
      printf("o valor está fora do intervalo de 100 a 200");
	system("PAUSE > null");  //para a execução do programa
}
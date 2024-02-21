//Exercício feito por Geovana Piccioli  / Nathalie Tellechea  /  Rafael Kazuhito /

#include <stdio.h> //biblioteca para entrada e saída de dados 
#include <math.h> //biblioteca de funções matemáticas
#include <iostream> //biblioteca para entrada e saída de dados c++
#include <locale.h> //biblioteca para acentuação

main(){ //função main
    setlocale(LC_ALL,"Portuguese"); // habilita acentuação 
    float n; //declaração de variáveis float
    int i,cont;
    cont=0;
    for (i=1;i<80;i++){
      printf("informe um valor: ");
      scanf("%f",&n);
      if(n>=10 && n<=150){
        cont++;
      }
    }
    printf("foram encontrados %d números dentro do intervalo",cont);
	  system("PAUSE > null");  //para a execução do programa
}


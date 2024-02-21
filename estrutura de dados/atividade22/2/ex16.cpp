//Exercício feito por Geovana Piccioli  / Nathalie Tellechea  /  Rafael Kazuhito /

#include <stdio.h> //biblioteca para entrada e saída de dados 
#include <math.h> //biblioteca de funções matemáticas
#include <iostream> //biblioteca para entrada e saída de dados c++
#include <locale.h> //biblioteca para acentuação

main(){ //função main
    setlocale(LC_ALL,"Portuguese"); // habilita acentuação 
    float i,nota,media; //declaração de variáveis float
    char nome[50];
    printf("Informe o nome do aluno: ");
    scanf("%s",&nome);
    media=0;
    for (i=1;i<4;i++){
      printf("informe a nota: ");
      scanf("%f",&nota);
      media=media+nota;
    }
    media=media/3;
    if(media>=7){
      printf("o aluno %s recebeu nota média de %2.2f e está aprovado",nome,media);
    } else if (media>5 && media<7){
      printf("o aluno %s recebeu nota média de %2.2f e está de recuperação",nome,media);
    } else{
      printf("o aluno %s recebeu nota média de %2.2f e está reprovado",nome,media);
    }
	system("PAUSE > null");  //para a execução do programa
}








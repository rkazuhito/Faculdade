//Exercício feito por Geovana Piccioli  / Nathalie Tellechea  /  Rafael Kazuhito /

#include <stdio.h> //biblioteca para entrada e saída de dados 
#include <math.h> //biblioteca de funções matemáticas
#include <iostream> //biblioteca para entrada e saída de dados c++
#include <locale.h> //biblioteca para acentuação

main(){ //função main
    setlocale(LC_ALL,"Portuguese"); // habilita acentuação 
    int n,c,maior; //declaração de variáveis int
    maior=0;
    for(c=1;c<3;c++){ //loop para receber infos e verificar qual o maior
        printf("Informe um número: ");
        scanf("%d",&n);
        if(n>maior) //verfica o maior
        maior=n; //armazena o maior
    }
    printf("o maior número digitado foi %d",maior); //imprime o maior
	system("PAUSE > null");  //para a execução do programa
}
//Exercício feito por Geovana Piccioli  / Nathalie Tellechea  /  Rafael Kazuhito /

#include <stdio.h> //biblioteca para entrada e saída de dados 
#include <math.h> //biblioteca de funções matemáticas
#include <iostream> //biblioteca para entrada e saída de dados c++
#include <locale.h> //biblioteca para acentuação

main(){ //função main
    setlocale(LC_ALL,"Portuguese"); // habilita acentuação 
    float n; //declaração de variáveis float
    printf("informe um valor: "); //saída de dados
    scanf("%f",&n); //entrada de dados
    if(n>10) //verifica se o valor é maior que 10
        printf("o valor é maior que 10"); //imprime resultado
    else
        return 0; //retorna 0
	 system("PAUSE > null");  //para a execução do programa
}

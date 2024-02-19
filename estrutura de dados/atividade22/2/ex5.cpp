//Exercício feito por Geovana Piccioli  / Nathalie Tellechea  /  Rafael Kazuhito /

#include <stdio.h> //biblioteca para entrada e saída de dados 
#include <math.h> //biblioteca de funções matemáticas
#include <iostream> //biblioteca para entrada e saída de dados c++
#include <locale.h> //biblioteca para acentuação

main(){ //função main
    setlocale(LC_ALL,"Portuguese"); // habilita acentuação 
    float n,media,c; //declaração de variáveis float
    char nomeAluno[50]; //declaração char (string)
    printf("Informe o nome do aluno"); //saída de dados
    scanf("%s",&nomeAluno);//entrada de dados
    media=0;
    for (c = 1; c < 4; c++) { //loop de 3 eventos com for para receber 3 notas
        printf("Informe a nota: ");
        scanf("%f",&n);
        media=media+n; //soma as notas na var media
    }
    printf("O aluno %s obteve média = %3.2f",nomeAluno,media/3); //calcula a média e exibe a resposta
    system("PAUSE>null"); //para a execução do programa
}
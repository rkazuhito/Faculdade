//Exercício feito por Geovana Piccioli  / Nathalie Tellechea  /  Rafael Kazuhito /

#include <stdio.h> //biblioteca para entrada e saída de dados 
#include <math.h> //biblioteca de funções matemáticas
#include <iostream> //biblioteca para entrada e saída de dados c++
#include <locale.h> //biblioteca para acentuação

main(){ //função main
    setlocale(LC_ALL,"Portuguese"); // habilita acentuação 
    float sal,vendas,salFinal; //declaração de variáveis float
    char nome[50]; //declaração da variável char(string)
    printf("Informe o nome do vendedor: "); //saída de dados
    scanf("%s",&nome); //entrada de dados
    printf("Informe o seu salário fixo (salário base) (R$): ");
    scanf("%f",&sal);
    printf("Informe o total de vendas (R$): ");
    scanf("%f",&vendas);
    salFinal=sal+(0.15*vendas); //calcula o salário final
    printf("O vendedor %s com salário fixo de R$%5.2f. Terá com comissões um salário final de R$%5.2f",nome,sal,salFinal); //exibe resultados
    system("PAUSE>null"); //para a execução do programa
}

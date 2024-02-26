//Exercício feito por Rafael Kazuhito /

#include <stdio.h> //biblioteca para entrada e saída de dados 
#include <math.h> //biblioteca de funções matemáticas
#include <iostream> //biblioteca para entrada e saída de dados c++
#include <locale.h> //biblioteca para acentuação

using namespace std; //standard

int main(){ //função main
    setlocale(LC_ALL,"Portuguese"); // habilita acentuação 
    float precoCusto, precoVenda, totCusto=0, totVenda=0;
	int nProd,c;
    cout <<"Informe a quantidade de produtos que ser� cadastrado";
    cin >> nProd;
    for (c=0 ; c<nProd ;  c++){
    	cout <<"Prod "<< c+1 <<"\n";
		cout <<"Pre�o de custo:";
		cin >>precoCusto;
		cout<<"Pre�o de venda:";
		cin >>precoVenda;
		totCusto+=precoCusto;
		totVenda+=precoVenda;
	}
	if(totCusto < totVenda){
		cout <<"Obteve lucro \n";
	}else if(totVenda < totCusto){
		cout <<"Obteve preju�zo \n";
	}
	else{
		cout <<"Obteve empate \n";
	}
	cout <<"A m�dia de custo foi "<< totCusto/nProd<< "\n";
	cout <<"A m�dia de venda foi "<< totVenda/nProd<< "\n";
	return 0;
}

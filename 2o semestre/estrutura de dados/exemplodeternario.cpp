// testando if ternario

#include <iostream>
#include <iostream>
#include <locale.h>

using namespace std;

int main(){
	setlocale(LC_ALL,"Portuguese");
	//(expressão) ? retorno caso expressão Verdadeira : retorno caso falsa;
	int n1, n2, nota;
	string res;
	
	cout <<"Digite a primeira nota: ";
	cin >>n1;
	cout <<"Digite a segunda nota: ";
	cin >>n2;
	nota=n1+n2;
	(nota>=60) ? res="Aprovado":res="Reprovado";
	cout << "Situação do aluno: " << res;
	
		
	return 0;
}

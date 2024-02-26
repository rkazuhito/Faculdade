// testando switch

#include <iostream>
#include <iostream>
#include <locale.h>

using namespace std;

int main(){
	setlocale(LC_ALL,"Portuguese");
	int valor;
	cout <<"Selecione uma cor\n";
	cout <<"[1]-verde [2]-vermelho [3]-azul";
	cin >> valor;
	switch(valor){
		case 1:
			cout << "Verde";
			break;
		case 2:
			cout << "Vermelho";
			break;
		case 3:
			cout << "Azul";
			break;
		default:
			cout <<"Inválido";
	}	
	return 0;
}

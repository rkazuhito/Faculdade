#include <iostream>

using namespace std;

int main(){
	int matriz[3][4],l,c;
	
	for (l=0;l<3;l++){
		for (c=0;c<4;c++){
			cout << "informe o valor da matriz na posição matriz["<< l <<"]"<< "["<< c <<"]";
			cin >> matriz[l][c];
		}
	}
	cout << "A matriz digitada será: \n";
	for (l=0;l<3;l++){
		for (c=0;c<4;c++){
		cout <<"["<< matriz[l][c] <<"]";
		}
		cout << "\n";
	}
	
	return 0;
}

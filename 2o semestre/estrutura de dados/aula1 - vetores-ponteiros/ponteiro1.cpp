#include <stdio.h>
#include <stdlib.h> 
#include <math.h> 
#include <iostream> 
#include <locale.h> 

using namespace std; //standard

int main(){
    int num;
    int *p; //* indica o ponteiro
    num=5;
    p=&num; //& fornece endereço fisico da variável
    cout << num<<"\n";
    cout << *p<<"\n";
    cout << p<<"\n";
    cout << &num<<"\n";
    return 0;
}

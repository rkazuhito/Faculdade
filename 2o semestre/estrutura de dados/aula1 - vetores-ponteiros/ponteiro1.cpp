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
    p=&num; //& fornece endere�o fisico da vari�vel
    cout << num<<"\n";
    cout << *p<<"\n";
    cout << p<<"\n";
    cout << &num<<"\n";
    return 0;
}

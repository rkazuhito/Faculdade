#include <iostream>

using namespace std;
int fat(int n);
int fib(int n);

int main(){
    int val, res;
    cout <<"informe o valor";
    cin >> val;
    res=fat(val);
    cout << val <<"!= " << res <<"\n";
    cout<< "fibonacci = ";
    for(int i=1;i<=val;i++){
        cout <<fib(i)<<" ";
    }
    return 0;
}

int fat(int n){
    if (n==0){
        return 1;
    }
    return n*fat(n-1);
}
int fib(int n){
    if (n==1||n==2){
        return 1;
    }
    else{
        return fib(n-1)+fib(n-2);
    }
}

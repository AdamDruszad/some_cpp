#include <iostream>

using namespace std;

void print(int a, int b){
	cout << a << " " << b << endl;
}

int osszeg(int a, int b){
	return a+b;
}

//érték szerinti paraméterátadás
void csere(int a, int b){
	int temp = a;
	a = b;
	b = temp;
}

//referencia szerinti paraméterátadás
void csere2(int& a, int& b){
	int temp = a;
	a = b;
	b = temp;
}

//pointer
void csere3(int* a, int* b){
	int temp = *a;
	*a = *b;
	*b = temp;
}

void szoroz(int& a, int b){
	a = a * b++;
}

void tombkiir(int t[5]){
	for(int i = 0; i<5; i++){
		cout << t[i]++ << " ";
	}
	cout << endl;
}

int factorial(int n){
	if(n > 1){
		cout << n << endl;
		return n*factorial(n-1);
	} else {
		cout << n << endl;
		return 1;
		//return n*factorial(n-1);
	}
}

int fibo(int x){
	if( (x==1) || (x==0)){
		return x;
	} else {
		return fibo(x-1) + fibo(x-2);
	}
}

int min(int *t, int meret){
	int m = t[0];
	for(int i = 1; i<meret; i++){
		if(t[i] < m){
			m = t[i];
		}
	}
	return m;
}

int main(){

	//Stack memória
	int a;
	int t[5];
	
	//Heap memória
	//pointer-változó = new típus
	//C malloc és free
	//C++ new és delete
	int* x = new int;
	int* tp = new int[5];
	
	int* p2 = new(nothrow) int;
	
	if(!p2){
		cout << " Nem sikerült az allokáció" << endl;
	} else {
		*p2 = 32;
	}
	
	float* f = new float(26.11);
	*x = 11;
	
	for(int i = 0; i< 5; i++){
		tp[i] = i+1;
		cout << tp[i] << " ";
	}
	cout << endl;
	
	delete x;
	delete[] tp;
	delete p2;
	delete f;
	
	int y = 2, z = 4;
	
	//cout << y << " " << z << endl;
	print(y,z);
	
	int o = osszeg(y,z);
	cout << o << endl;
	
	csere(y,z);
	print(y,z);
	
	csere2(y,z);
	print(y,z);
	
	csere3(&y, &z);
	print(y,z);
	
	szoroz(y,z);
	print(y,z);
	
	int tomb[5] ={1,2,3,4,5};
	
	tombkiir(tomb);
	//{2,3,4,5,6}
	
	tombkiir(tomb);
	//{3,4,5,6,7}
	
	cout << factorial(5) << endl;
	
	int fibonacci = fibo(8);
	cout << fibonacci << endl;
	
	cout << min(tomb, 5) << endl;
	
	










}

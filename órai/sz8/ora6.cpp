#include <iostream>

using namespace std;

int fibo(int x){
	if( (x==1) || (x==0)){
		return x;
	} else {
		return fibo(x-1) + fibo(x-2);
	}
}

//eljárás
void print(int a, int b){
	cout << a << " " << b << endl;
}

int multiply(int a, int b){
	return a*b;
}

//Érték szerinti paraméterátadás
void csere(int a, int b){
	int tmp = a;
	a = b;
	b = tmp;
	print(a,b);
}

//Referencia szerinti paraméterátadás
void csere2(int& a, int& b){
	int tmp = a;
	a = b;
	b = tmp;
	print(a,b);
}

//Pointer
void csere3(int* a, int* b){
	int tmp = *a;
	*a = *b;
	*b = tmp;
	print(*a, *b);
}

void szoroz(int& a, int b){
	a = a*b++;
}

void tombkiir(int t[5]){
	for(int i = 0; i<5; i++){
		cout << t[i]++ << " " ;
	}
	cout << endl;
}

int min(int* t, int meret){
	int m = t[0];
	for(int i = 0; i<meret; i++){
		if(t[i] < m){
			m = t[i];
		}
	}
	
	return m;
}

int factorial(int n){
	if(n>1){
		cout << n << endl;
		return n*factorial(n-1);
	} else {
		cout << n << endl;
		return 1;
	}
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
	int * tp = new int[5];
	
	int * p2 = new(nothrow) int;
	
	if( !p2 ){
		cout << "Nem sikerült az allokáció" << endl;
	} else {
		*p2 = 37;
	}
	
	float* f = new float(26.11);
	
	*x = 11;
	
	for(int i = 0; i<5; i++){
		tp[i] = i+1;
		cout << tp[i] << " ";
	}
	cout << endl;
	
	delete x;
	delete[] tp;
	delete f;
	delete p2;
	
	int y = 2, z = 4;
	
//	cout << y <<  " " << z << endl;
	print(y,z);
	
	int mul = multiply(y,z);
	cout << mul << endl;
	
	if( multiply(y,z) > 5 ){
		cout << "nagyobb" << endl;
	}
	
	cout << " Érték szerinti: " << endl;
	csere(y,z);
	print(y,z);
	
	
	cout << " Referencia szerinti: " << endl;//cím szerinti	
	csere2(y,z);
	print(y,z);
	
	cout << " Pointer" << endl;
	csere3(&y,&z);
	print(y,z);
	
	szoroz(y,z);
	print(y,z);
	
	int tomb[5] = {1,2,3,4,5};
	
	tombkiir(tomb);
	//{2,3,4,5,6}
	tombkiir(tomb);
	//{3,4,5,6,7}
	
	cout << min(tomb, 5) << endl;
	
	cout << factorial(5) << endl;
	
	
	
	
	
	
	
	
	
	
	
	
	cout << fibo(5) << endl;










}

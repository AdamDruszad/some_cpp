#include <iostream>

using namespace std;

//eljárás
void print(int a, int b){
	cout << a << " " << b << endl;
}

//függvény
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
		cout << t[i]++ << " " ;
	}
	cout << endl;
}

int min(int* tomb, int meret){
	int m = tomb[0];
	for(int i = 1; i<meret; i++){
		if(tomb[i] < m){
			m = tomb[i];
		}
	}
	return m;
}

int factorial(int n){
	cout << n << endl;
	if(n>1){
		return n*factorial(n-1);
	} else {
		//return n*factorial(n-1);
		return 1;
	}
}

int fibo(int x){
	if( (x == 0) || (x == 1)){
		return x;
	} else {
		return fibo(x-1) + fibo(x-2);
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
	
	int* p = new int;
	int* tp = new int[5];
	
	int* p2 = new(nothrow) int;
	
	if(!p2){
		cout << "Memória allokáció sikertelen" << endl;
	} else {
		*p2 = 32;
	}
	
	float* f = new float(3.58);
	
	for(int i = 0; i<5; i++){
		tp[i] = i+1;
		cout << tp[i] << " " ;
	}
	cout << endl;
	
	delete p;
	delete[] tp;
	delete p2;
	delete f;
	
	int x = 2, y = 4;
	
	print(x,y);
	
	osszeg(x,y);
	
	int o = osszeg(x,y); //==> o = x+y;
	
	cout << o << endl;
	
	csere(x,y);
	
	print(x,y);
	
	csere2(x,y);
	print(x,y);
	
	csere3(&x,&y);
	print(x,y);
	
//	csere2(x,2);
//	csere3(&x, 3);

	szoroz(x,y);
	print(x,y);
	
	int tomb[5]= {1,2,3,4,5};
	
	tombkiir(tomb);
	//{2,3,4,5,6}
	
	tombkiir(tomb);
	//{3,4,5,6,7}
	
	int m = min(tomb, 5);
	cout << m << endl;
	
	cout << factorial(5) << endl;
	cout << fibo(5) << endl;
	
	
	
	
	
	
	
	
	
	
	
	


}

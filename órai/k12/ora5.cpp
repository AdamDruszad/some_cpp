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

//referencia szerinti paraméterátardás
void csere2(int& a, int& b){
	int temp = a;
	a = b;
	b = temp;
}

//pointer
void csere3(int* a, int* b){
	int tmp = *a;
	*a = *b;
	*b = tmp;
}
//hibrid
void szoroz(int& a, int b){
	a = a * b++;
}

void tombkiir(int tomb[5]){
	for(int i = 0; i<5; i++){
		cout << tomb[i]++ <<  " " ;
	}
	cout << endl;
}


int fibonacci(int n){
	if((n ==1)  || (n == 0)){
		return n;
	} else {
		return fibonacci(n-1) + fibonacci(n-2);
	}
}


int main(){

	//Stack memória
	int a;
	int b[10];
	
	//Heap memória
	//pointer-változó = new típus;
	//C malloc és free
	//C++ new és a delete
	
	int* p = new int;
	int* tp = new int[10];
	
	int* p2 = new(nothrow) int;
	
	if(!p2){
		cout << "memória allokáció sikertelen" << endl;
	} else {
		*p2 = 29;
	}
	
	float* f = new float(72.24);
	
	for(int i = 0; i< 10; i++){
		tp[i] = i+1;
		cout << tp[i] << " " ;
	}
	cout << endl;
	
	delete p;
	//delete tp;
	delete[] tp; 
	delete p2;
	delete f;
	
	int x = 2, y = 4;
	
	//cout << x << " " << y << endl;
	print(x,y);
	
	osszeg(x,y);
	
	int o = osszeg(x,y);
	
	cout <<"Összeg: "<< o << endl;
	
	csere(x, y);
	
	print(x,y);
	
	csere2(x, y);
	
	print(x,y);
	
	csere3(&x, &y);
	
	print(x,y);
	
	szoroz(x,y);
	
	print(x,y);
	
	int tomb[5] = {1,2,3,4,5};
	
	tombkiir(tomb);
	//{2,3,4,5,6}
	tombkiir(tomb);
	
	cout << fibonacci(2) << " " << fibonacci(5) << " " << fibonacci ( 7) << endl;
	
	//rekurzió vs ciklusok












}

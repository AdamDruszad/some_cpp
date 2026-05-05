#include <iostream>
#include <algorithm>

using namespace std;

int main(){

	struct{	//anonim struktúra
		int szulEv;
		string nev;
	} szemely1, szemely2;
	//int x, y;
	
	szemely1.szulEv = 2004;
	szemely1.nev = "Béla";
	
	szemely2 = {2005, "Lili"};
	
	cout << szemely1.nev << " " << szemely1.szulEv << endl;
	
	szemely2 = szemely1;
	
	szemely1.nev = "Károly";
	
	cout << szemely1.nev << " " << szemely2.nev << endl;
	
	struct jarmu{ //jármű típus létrehozása
		string marka;
		string tipus;
		short int evjarat;
	};
	
	jarmu j1 = {"Suzuki","Swift",2004};
	jarmu j2 = {"Kia", "Ceed", 2020};
	
	if( j1.evjarat > j2.evjarat ){
		cout << j1.marka << " " <<j1.tipus << " fiatalabb"<<endl;
	} else {
		cout << j2.marka << " " <<j2.tipus << " fiatalabb"<<endl;	
	}
	
	
	string st = "narancs";
	string& gyumolcs = st;
	//string& gyumolcs    	string & gyumolcs	string &gyumolcs
	
	cout << st << " " << gyumolcs << endl;
	
	st = "alma";

	cout << st << " " << gyumolcs << endl;
	
	//int& i = 1;
	
	cout << &st << " " << &gyumolcs << endl;
	
	cout << &j1 << " " << &j1.marka << " " << &j1.tipus << endl;
	
	int a = 12;
	int* b = &a; //pointer (int*) -pointer étréke mindig memóriacím
	//int* b 	int * b		int *b
	
	cout << a << " " << &a << " " << b << " " << &b << endl;
	
	cout << sizeof(b) << endl;
	
	cout << *b << endl;
	
	*b = 10;
	
	cout << a << endl;
	
	int z = 1;
	int* zptr = &z;
	int ** zpptr = &zptr;
	int ***zppptr = &zpptr;
	//zppptr = &z;
	
	cout << z << " " << *zptr << " " << **zpptr << " " << (*(*(*(zppptr)))) << endl;
	
	int t[5] = {1,2,3,4,5};
	
	cout << t << endl;
	
	int* tptr = t;
	
	cout << t << " " << &t[0] << " " << tptr  << endl;
	
	cout << (&t[0])[1] << " " << tptr[1] << endl;
	
	for(int* ptr = t ;  ptr <= &t[4] ; ptr++){
		cout << *ptr << " " << ptr << endl;
	}
	
	tptr = &t[4];
	
	while(tptr >= t){
		cout << *tptr << " " << tptr-- << endl;
	}
	
	
	*(t+4) = 500;  	//	*(&tomb[0+4]) ==> tomb[4] = 500;
	
	for(int i = 0; i<5; i++){
		*(t+i) = 5-i;
		cout << *(t+i) << " " ;
	}
	cout << endl;
	
	int temp = *t;
	*t = *(t+4);
	*(t+4) = temp;
	
	for(int i = 0; i<5; i++){
		cout << *(t+i) << " " ;
	}
	cout << endl;
	
	std::swap(*t, *(t+4));
	
	for(int i = 0; i<5; i++){
		cout << *(t+i) << " " ;
	}
	cout << endl;
	
	int tomb2[5] = {1,3,5,7,9};
	int mtomb[5];
	
	int * kezdo_ptr = tomb2;
	int * veg_ptr = &tomb2[4];
	int * cel_ptr = mtomb;
	
	while(kezdo_ptr <= veg_ptr){
		*(cel_ptr++) = *(kezdo_ptr++);
		/*
			*cel_ptr = *kezdo_ptr;
			cel_ptr++;
			kezdo_ptr++;
		*/
	}
	
	for(int i =0; i<5; i++){
		cout << mtomb[i] << " ";
	}
	cout << endl;
	
	
	//POINTER TÖMB
	/**
		*p++ vagy *(p++) dereference, majd pointer inkrementálása
		*++p vagy *(++p) pointer inkrementálása, majd dereference
		(*p)++ dereference, majd érték növelése
	
	*/











}

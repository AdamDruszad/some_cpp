#include <iostream>
#include <algorithm>

using namespace std;

int main(){

	//anonim struktúra
	struct{
		int szulEv;
		string nev;
	} szemely1, szemely2;
	//int x, y;
	
	szemely1.szulEv = 2006;
	szemely1.nev ="Béla";
	
	szemely2 = {2004, "Luca"};
	
	cout << szemely1.szulEv << " " << szemely1.nev << endl;
	
	szemely2 = szemely1;
	szemely1.nev = "Éva";
	
	cout << szemely1.nev << " " << szemely2.nev << endl;
	
	
	struct jarmu{
		string marka;
		string tipus;
		int evjarat;
	}; //jármű típus létrehozása
	
	jarmu j1 = {"Suzuki","Swift",2004};
	jarmu j2 = {"Kia","Ceed", 2020};
	
	if( j1.evjarat > j2.evjarat){
		cout << j1.marka << " " << j1.tipus << " fiatalabb." << endl;
	} else {
		cout << j2.marka << " " << j2.tipus << " fiatalabb." << endl;
	}
	
	
	string st = "narancs";
	string& gyumolcs = st;
	
	cout << st  << " " << gyumolcs << endl;
	st = "banán";
	cout << st  << " " << gyumolcs << endl;	
	
	cout << &st << " " << &gyumolcs << endl;
	
	
	
	cout << &szemely1 << " " << &j1.marka << " " << &j1.evjarat << " " << &szemely2<< endl;
	
	
	int a = 12;
	int* b = &a; //Pointer értéke memóriacím!
	//int* b     int * b      int *b   megegyezik
	
	cout << a << " " << &a << " " << b << " " << &b << endl;
	cout << sizeof(b) << endl;
	
	cout << *b << endl;
	
	*b = 15;
	
	cout << a << " " << *b << endl;
	
	int z = 1;
	int * zptr = &z;
	int ** zpptr = &zptr;
	int *** zppptr = &zpptr;
	
	cout << z << " " << *zptr << " " << **zpptr << " " << ***zppptr << endl;
	
	int t[5] = {1,2,3,4,5};
	
	cout << t << endl;
	
	int* tptr = t;
	
	cout << t << " " << &t[0] << " " << tptr << endl;
	
	cout << tptr[2] << " " << (&t[0])[2] << endl;
	
	for(int * ptr = t; ptr <= &t[4] ; ptr++){
		cout << *ptr << " " << ptr << endl;
	}
	
	tptr = &t[4];
	
	while(tptr >= t){
		cout << *tptr << " " << tptr-- << endl;
	}
	
	
	
	*(t+4) = 500; // t[0+4] = 500       &t[0]+ 4*4byte  => 500
	
	cout << t[4] << endl;
	
	for(int i = 0; i<5; i++){
		*(t+i) = 5-i;  //t[i] = 5-i
		cout << *(t+i) << endl;
	}
	
	
	int cseretomb[5] = {1,2,3,4,5};
	int temp = *cseretomb;
	*cseretomb = *(cseretomb+4);
	*(cseretomb+4) = temp;
	
	for(int i = 0; i<5; i++){
		cout << cseretomb[i] << " ";
	}
	cout << endl;
	
	
	std::swap(*cseretomb, *(cseretomb+4));
	
	for(int i = 0; i<5; i++){
		cout << cseretomb[i] << " ";
	}
	cout << endl;
	
	int tomb2[5] = {1,3,5,7,9};
	int mtomb[5];
	
	int * kezdo_ptr = tomb2;
	int * veg_ptr = &tomb2[4];
	int* cel_ptr = mtomb;
	
	while(kezdo_ptr <= veg_ptr){
		*(cel_ptr++) = *(kezdo_ptr++);
		
		/*
			*cel_ptr = *kezdo_ptr;
			cel_ptr++;
			kezdo_ptr++;
		*/
	}
	
	for(int i = 0; i<5; i++){
		cout << mtomb[i] << " ";
	}
	cout << endl;
	
	//POINTER TÖMB
	
	/** 
		*p++ vagy *(p++) dereference, majd pointer inkrementálása
		*++p vagy *(++p) pointer inkremenálása, majd dereference
		(*p)++ dereference, majd érték növelése
	
	*/
	
	
	
	







}

#include <iostream>
#include <algorithm>

using namespace std;

int main(){

	//struktúra v. rekord
	
	struct{ //anonim struktúra
		int szulEv;
		string nev;
	} szemely1, szemely2;
	//int s1, s2;
	
	szemely1.szulEv = 2000;
	szemely1.nev = "Béla";
	
	szemely2 = {2010, "Luca"};
	
	szemely2 = szemely1;
	
	szemely1.szulEv = 2002;
	
	cout << szemely2.szulEv << " " << szemely2.nev << endl;
	
	
	struct jarmu{
		string marka;
		string tipus;
		short int evjarat;
	}; //jármű típus létrehozása
	
	jarmu j1 = {"Suzuki","Swift",2003};
	jarmu j2 = {"Nissan","Tiida", 2009};
	
	if(j1.evjarat > j2.evjarat){
		cout << j1.marka << " " << j1.tipus << " fiatalabb." << endl;
	} else {
		cout << j2.marka << " " << j2.tipus << " fiatalabb." << endl;
	}
	
	
	string st = "narancs";
	string& gyumolcs = st; //típus&  -> referencia
	
	cout << st << " " << gyumolcs << endl;
	
	gyumolcs = "mandarin";
	
	cout << st << " " << gyumolcs << endl;
	
	cout << &st << " " << &gyumolcs << endl;
	
	
	cout << &j1 << " " << &j1.marka << " " << &j1.tipus << endl;
	
	int a = 12;
	int* b = &a; //pointer értéke mindig memóriacím
	
	
	cout << a << " " << &a << " " << b << " " << &b << endl;
	
	cout << sizeof(b) << endl;
	
	cout << *b << endl;
	
	*b = 15;
	
	cout << a << endl;
	
	int z = 1;
	int *zptr = &z;// int* zptr,   int * zptr,   int *zptr;
	int ** zpptr = &zptr;
	
	cout << z << " " << *zptr << " " << **zpptr << endl;
	
	int t[5] = {1,2,3,4,5};
	
	
	
	int* tptr = t;
	
	cout << t  <<" "<< &t[0] << " " <<tptr << endl;
	
	//bejárás pointerrel
	for(int* tptr = t; tptr<=&t[4] ; tptr++){
		cout << *tptr << " " << tptr << endl;
	}
	
	tptr = t+4; //&tomb[0+4]
	while(tptr >= t){
		cout << *tptr << " " << tptr-- << endl;
	}
	
	//tomb[4] = 500;
	*(t+4) = 500;
	
	cout << t[4] << endl;
	//bejárás címmel
	for(int i = 0; i<5; i++){
		*(t+i) = 5-i;
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
	
	/** 
		*p++ vagy *(p++) dereference, majd pointer inkrementálása
		*++p vagy *(++p) pointer inkremenálása, majd dereference
		(*p)++ dereference, majd érték növelése
	
	*/
	
	int * ptrtomb[5];
	
	for(int i=0; i<5; i++){
		ptrtomb[i] = &t[i];
		cout << *ptrtomb[i] << " ";
	}
	cout << endl;
	
	
	int tomb2[5] = {1,3,5,7,9};
	int mtomb[5];
	
	int * kezdo_ptr = tomb2;
	int* veg_ptr = &tomb2[4];
	int * cel_ptr = mtomb;
	
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
	
	
	
	
	
}

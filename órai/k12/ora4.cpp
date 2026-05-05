#include <iostream>
#include <algorithm>

using namespace std;

int main(){

	struct{
		int szul_ev;
		string nev;
	} szemely1, szemely2;
	
	szemely1.szul_ev = 2000;
	szemely1.nev = "Béla";
	
	szemely2 = szemely1;
	
	cout << szemely1.szul_ev << " " << szemely1.nev << endl;
	
	szemely1.szul_ev = 2010;
	
	cout << szemely2.szul_ev << " " << szemely2.nev << endl;
	
	struct jarmu{
		string marka;
		string tipus;
		short int evjarat;
	};
	
	jarmu swift;
	swift.marka = "Suzuki";
	swift.tipus = "Swift";
	swift.evjarat = 2003;
	
	jarmu astra;
	astra.marka = "Opel";
	astra.tipus = "Astra";
	astra.evjarat = 2014;
	
	if(swift.evjarat > astra.evjarat){
		cout << "A(z) " << swift.tipus << " fiatalabb" << endl;
	} else {
		cout << "A(z) " << astra.tipus << " fiatalabb" << endl;
	}
	
	string st = "narancs";
	string& gyumolcs = st; //string referencia
	//string& gyumolcs,    string & gyumolcs,   string &gyumolcs;
	
	cout << st << " " << gyumolcs << endl;
	
	st = "alma";
	
	cout << st << " " << gyumolcs << endl;	
	
	cout << & st << " " << &gyumolcs << endl;
	
	
	cout << &astra << " " << &astra.marka << " " << &swift << " " << &swift.marka << endl;
	
	int a = 10;
	int* b = &a; //pointer értéke memóriacím
	//int* b,   int * b,    int *b
	
	cout << a << " " << &a << " " << b << " " << &b << endl;
	//a értéke, a memóriacíme, b értéke, b memóriacíme 
	
	cout << *b << endl;
	cout << sizeof(b) << endl;
	
	*b = 15;
	
	cout << a << " " <<*b << endl;
	
	int* ptr = NULL;
	
	if(ptr){ //null-e?
		cout << "Nem null" << endl;
	} else {
		cout << "Null" << endl;
	}
	
	int z = 1;
	int *zptr = &z;
	int **zpptr = &zptr;
	
	cout << z << " " << *zptr << " " << **zpptr << endl;
	
	
	int tomb[5] = {1,2,3,4,5};
	int* tptr;
	
	tptr = tomb;// tomb === &tomb[0]
	
	cout << tomb << " " << &tomb[0]	 << " " << tptr << endl;
	
	for(int i = 0; i<5; i++){
		cout << tptr << " " << *tptr << endl;
		tptr++;
	}
	
	
	
	tptr = &tomb[4];
	
	while(tptr >= &tomb[0]){
		cout << tptr << " " << *tptr << endl;
		tptr--;
	}
	
	*(tomb+4) = 500;  // *(&tomb[0] + 4*4byte)   ==> tomb[4] = 500;
	cout << tomb[4] << endl;
	
	int* ptrtomb[5]; //tömb, aminek elemei pointerek
	for(int i =0; i<5; i++){
		ptrtomb[i] = &tomb[i]; // =tomb+i
		cout << *ptrtomb[i] << endl;
	}
	
	/**
		 *p++ vagy *(p++) pointer inkrementálása, majd a növelési előtti címen található pointer dereferencelése
		 *++p vagy *(++p) pointer inkrementálása, majd dereference
		 
		 (*p)++ dereference, majd érték növelése
	
	*/
	
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
	
	
	//FELADATTAL KEZDJÜNK!
	
	
	

}

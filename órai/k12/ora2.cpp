#include <iostream>

using namespace std;

int main(){
	//logikai operátorok
	//&& || ! - és, vagy , negáció
	
	bool b = 60 > 5;
	
	cout << !b << " "<< (b && true) << " "<< ((60 < 5) || false) << endl;
	
	//bitműveletek
	// & | ^ << >>
	//bitenkénti és, vagy , XOR, eltolás (balra), eltolás (jobbra);
	
	int A  = 60;
	int B = 13;
	
	cout << (A & B) << " " << (A | B ) << endl;
	
	cout << (A >> 2) << endl;
	
	
	//értékadó operátorok
	// = += -= *= /= %= <<= >>= &= |= ^=
	// a += 2    ==> 	a = a + 2
	// a >>=2    ==>	a = a >> 2
	
	A += 10;
	cout << A << endl;
	
	int tomb[5] = {1, 2, 3, 4, 5};
	cout << tomb[0] << endl;
	cout << tomb[120] << endl;
	
	char sztring[] = "Hello, world!";
	sztring[0] = 'h';
	
	cout << sztring << endl;
	
	string cppstring = "Hello, world!";
	cppstring[0] = 'h';
	cout << cppstring << endl;
	
	//implicit típuskonverzió (bővítés)
	
	int num = 92;
	double d = num;
	
	//(szűkítés)
	d = 11.1123;
	num = d;
	
	//explicit típuskonverzió
	
	num = int(d);
	
	//elágazás
	if( 21 > 10 ){
		cout << "nagyobb" << endl;
	}
	
	if( 10 > 21 ){
		cout << "nagyobb" << endl;
	} else { //10 <= 21
		cout << "kisebb vagy egyenlő" << endl;
	}
	
	
	if( 10 > 21 ){
		cout << "nagyobb" << endl;
	} else if( 10 == 21 ){
		cout << "egyenlő" << endl;
	} else {
		cout << "kisebb" << endl;
	}
	
	if( 10 > 9 ){
		if( 2 < 3){
			cout << "belső if" << endl;
		}
	}
	
	int tern = 10 > 9 ? 1 : 0;
	cout << tern << endl;
	
	int x1 = 1;
	int y1 = 10;
	string eredmeny;
	
	eredmeny = (x1 == y1) ? "egyenlő" : "nem egyenlő";
	cout << eredmeny << endl;
	
	if ( x1 == y1 ) {
		eredmeny = "egyenlő";
	} else if ( x1 < y1 ) {
		eredmeny = "kisebb";
	} else{
		eredmeny = "nagyobb";
	}
	
	cout << eredmeny << endl;
	
	eredmeny = (x1 == y1) ? "egyenlő" : (x1 < y1) ? "kisebb" : "nagyobb";
	cout << eredmeny << endl;
	
	if( x1 = 2) {
		cout << "belép" << endl;
	}
	
	int nap = 7;
	
	switch (nap){
		case 6:
			cout << "szombat" << endl;
			break;
		case 7: 
			cout << "vasárnap" << endl;
			break;
		default:
			cout << "mindjárt hétvége" << endl;
			break;
	}
	
	//ciklusok
	
	
	//előltesztelő ciklus
	
	int i = 0;
	
	while ( i < 10 ){ //0 vagy több alkalommal fut le
		cout << i << " ";
		i++;
	}
	cout << endl;
	
	float f = 10.0f;
	
	while ( f > 4.9){
		cout << f << endl;
		f-=0.1f;
	}
	cout << endl;
	
	char c = 'a';
	
	while ( c <= 'z' ){
		cout << c << " " << int(c) << endl;
		c++;
	}
	
	
	
	
	

	
	
	
	
	
}









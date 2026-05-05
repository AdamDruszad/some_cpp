#include <iostream>

using namespace std;

int main(){

	//összehasonlító operátorok
	//== <= >= < > !=
	
	//logikai operátorok
	//&& || ! -- és, vagy, negáció
	
	bool b = 60 < 5;
	
	cout << !b << " " << (b && true) << " " << ((60 < 5) || true) << endl;
	
	//bitműveletek
	//operátorai: & | ^ << >>  bitenkénti és, vagy, XOR, eltolás balra, eltolás jobbra
	int A = 60;
	int B = 13;
	
	cout << (A & B) << " " <<(A | B) << " "<< (A << 2) << endl;
	
	//értékadó operátorok
	// = += -= *= %= &= |= ^= 
	// A += 10		A = A + 10
	// B *= 2		B = B * 2
	
	A += 10;
	cout << A << endl;
	
	int tomb[5] = {1, 2, 3, 4, 5};
	tomb[0] = 15;
	cout << tomb[0] << " " << tomb[4] << endl;
	cout << tomb[150] << endl;
	
	char sztring[] = "Hello, world!";
	sztring[0] = 'h';
	cout << sztring << endl;
	//sztring = "hello,hello,hello,hello,hello,hello";
	
	//std::string
	string s = "Hello, world!";
	s[0] = 'h';
	cout << s << endl;
	s = "hello,hello,hello,hello,hello,hello";
	
	//típuskonverzió
	//implicit
	
	int n = 75;
	double d = n;
	
	d = 75.123;
	n = d;
	
	//explicit
	
	d = 75.123;
	n = int(d);
	
	cout << char(n) << " " << int('X') << endl;
	
	//feltételes, elágaztató utasítás
	
	if( 10 < 11) {
		cout << "igaz" << endl;
	}
	
	if( 21 < 10){
		cout << "kisebb"<< endl;
	} else {
		cout << "nagyobb, vagy egyenlő" << endl;
	}
	
	if (21 < 10){
		cout<< "kisebb" << endl;
	} else if( 21 == 10){
		cout << "egyenlő" << endl;
	} else {
		cout << "nagyobb" << endl;
	}
	
	if(0) {
		cout << "hamis" << endl;
	}
	
	if(false) {
		cout << "hamis" << endl;
	}
	
	if(1) {
		cout << "igaz" << endl;
	}
	
	if(1000) {
		cout << "igaz" << endl;
	}
	
	if( A == 2 ) {
		cout << "igaz" << endl;
	}
	
	//ternáris operátor
	//?:
	//feltétel? ha igaz: ha hamis
	
	bool b1 = A==B ? true: false;

	int x1 = 24;
	int x2 = 25;
	string eredmeny = x1 > x2 ? "nagyobb": "nem nagyobb";
	
	cout << eredmeny << endl;
	
	eredmeny = x1 > x2 ? "nagyobb" : (x1 == x2 ? "egyenlő" : "kisebb");
	
	cout << eredmeny << endl;
	
	int nap = 7;
	
	switch(nap){
		case 6:
			cout << "szombat" << endl;
			break;
		case 7:
			cout << "vasárnap" << endl;
			break;
		default:
			cout << "hétköznap" << endl;
	}
	
	//ciklusszervező utasítás
	//előltesztelő ciklus
	
	int i = 0;
	
	while(i < 10){
		cout << i*2+1 << endl ;
		i++;	
	}
	
	float f = 10.0;
	
	while(f > 4.9){
		cout << f <<endl;
		f-=0.1f;
	}
	cout << endl;
	
	int k = int('A');
	
	while(k <= int('Z')){
		cout << char(k) << " " ;
		k+=2;	
	}
	cout << endl;
	
	
	
	
	
	
	
	
	

}

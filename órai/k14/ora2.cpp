#include <iostream>

using namespace std;

int main(){

	// == <= >= != < > !
	// && || ! -- és, vagy, negáció
	
	bool b = 60 < 5;
	
	cout << (b && true) << " " << !b <<" " << ((60 < 5) || false) << endl;
	
	//bitműveletek
	//& | ^ << >>    -- bitenkénti és, vagy , XOR, balra eltolás, jobbra eltolás
	
	int A = 60;
	int B = 13;
	
	cout << (A & B) << " " << (A | B) << " " << (A << 2) << endl;
	
	//értékadó operátorok
	// = += -= *= /= %= <<= >>= &= |= ^= 
	// A += 1   ==      A = A + 1
	// A *= 3   ==      A = A * 3
	
	int tomb[5] = {1, 2, 3, 4, 5};
	cout << tomb[0] << endl;
	tomb[1] = 150;
	cout << tomb[1] << endl;
	
	cout << tomb[150] << endl;
	
	char sztring[] = "Hello, world!";
	sztring[0] = 'h' ;
	cout << sztring[0] << endl;
	//sztring = "Hello, world!Hello, world!Hello, world!Hello, world!";
	cout << sztring << endl;
	
	string s = "Hello, world!";
	s[0] = 'h';
	cout << s[0] << " " << s << endl;
	s = "Hello, world!Hello, world!Hello, world!Hello, world!";
	cout << s << endl;
	
	
	//típuskonverzió
	//implicit típuskonverzió
	
	int n = 92;
	double d = n;
	
	d = 92.116;
	n = d;
	
	//explicit típuskonverzió
	n = int(d);
	char c = char(d);
	
	cout << c << endl;
	
	//elágazás
	if( 21 > 10 ){
		//csak akkor lép be ide, ha a feltétel igaz
		cout << "igaz" << endl;
	}
	
	if( 21 > 10 ){
		cout << "nagyobb" << endl;
	} else {
		cout << "21 nem nagyobb, mint 10" << endl;
	}
	
	
	if( 21 > 10 ){
		cout << "nagyobb" << endl; 
	} else if( 21 ==  10) {
		cout << "egyenlő" << endl;
	} else {
		cout << "kisebb" << endl;
	}
	
	int tern = 10 > 9 ? 1 : 0;
	
	int x1 = 1;
	int y1 = 10;
	string eredmeny;
	
	eredmeny = (x1 == y1) ? "egyenlő" : "nem egyenlő";
	cout << eredmeny << endl;
	
	eredmeny = (x1 == y1) ? "egyenlő" : (x1 < y1) ? "kisebb" : "nagyobb";
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
	
	
	//ciklusok
	//előltesztelő ciklussal
	
	int i  = 0;
	while( i < 10 ){ //0 vagy több alkalommal fut le
		cout << i << endl;
		i++;
	}
	
	float f = 10.0;
	while( f >= 5.0f){
		cout << f << " " ;
		f -= 0.1f;
	}
	cout << endl;
	
	c = 'A';
	while( c <= 'Z'){
		cout << c << " " << int(c) << endl;
		c++;
	}
	
	c = 'z';
	while (c >= 'a'){
		cout << c << " " << int(c) << endl;
		c-=2;
	}
	
	//hátultesztelő ciklus
	//legalább 1x lefut. 1..n
	
	i = 0;
	do{
		cout << i<< endl;
	}while(i<0);
	
	do{
		cout << i << endl;
		i+=2;
	}while(i<10);

	
	
	
	
	
	
	
	
	
	
	

}

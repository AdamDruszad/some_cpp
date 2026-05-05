#include <iostream>

using namespace std;

int main(){

	//logikai operátorok
	//összehasonlítás: == != <= >= < > 
	//&& || !   -- és, vagy, negáció
	
	bool b = 60 < 5;
	
	cout << !b << " " << (b && true) <<" " <<((60 < 5) || false)<< endl;
	
	//bitműveletek
	//& | ^ << >> 
	//bitenkénti és, vagy, XOR, eltolás balra, eltolás jobbra
	
	int A = 60;
	int B = 13;
	
	cout << (A << 2) << endl;
	cout << (A & B) << " " << (A | B) << endl;
	
	//értékadó operátorok
	// = += -= *= /= %= &= |= <<= >>= ^=
	// A += 10         A = A + 10
	// B <<= 3	   B = B << 3
	
	A += 10;
	cout << A << endl;
	
	int tomb[5] = {1, 2, 3, 4, 5};
	tomb[0] = 15;
	cout << tomb[0] << endl;
	cout << tomb[150] << endl;
	
	char sztring[] = "Hello, world!";
	sztring[0] = 'h';
	cout << sztring << endl;
	//sztring = "Hello, world!Hello, world!Hello, world!Hello, world!"
	
	//std::string
	
	string s = "Hello, world!";
	s[0] = 'h';
	cout << s << endl;
	s = "Hello, world!Hello, world!Hello, world!Hello, world!";
	
	//típuskonverzió
	//implicit típuskonverzió
	
	int n = 92;
	double d = n;
	
	d = 92.123;
	n = d;
	
	//explicit típuskonverzió
	n = int(d);
	
	cout << char(n) << " " << int('Z') << endl;
	
	
	if( 21 < 10 ){
		cout << "Igaz" << endl;
	}
	
	if( 21 < 10){
		cout << "Igaz: kisebb" << endl;
	} else {
		cout << "Hamis: nagyobb vagy egyenlő" << endl;
	}
	
	if( 21 < 10){
		cout << "Igaz: kisebb" << endl;
	} else if( 21 == 10 ){
		cout << "Hamis: egyenlő" << endl;
	} else {
		cout << "Hamis: nagyobb" << endl;
	}
	
	if( A > B){
		if(A > 30){
			cout << "Belső if" << endl;
		}
	}
	
	//ternáris op feltétel? ha igaz: ha hamis;
	int tern = A > B ? 1 : 0;
	
	int x1 = 1;
	int y1 = 10;
	string eredmeny;
	
	eredmeny = (x1 == y1) ? "egyenlő" : "nem egyenlő";
	
	eredmeny = (x1 == y1) ? "egyenlő" : ((x1 < y1) ? "kisebb" : "nagyobb");
	
	cout << eredmeny << endl;
	
	if(0){
		cout << "0" << endl;
	}
	
	if(A){
		cout << "A" << endl;
	}
	
	if(100){
		cout << "100" << endl;
	}
	
	if(tomb){
		cout << "tomb" << endl;
	}
	
	if( A = 0 ){
		cout << "A = 13" << endl;
	}
	
	int nap = 6;
	
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
	
	//Ciklusok
	
	//előltesztelő ciklus
	
	int i = 0;
	while(i < 10){
		cout << i << endl;
		i++;
	}
	
	float f = 10.0f;
	while(f > 4.9){
		cout << f << " " ;
		f-= 0.1;
	}
	cout << endl;
	
	char c ='a';
	
	while(c <= 'z'){
		cout << c++;
	}
	cout << endl;
	
	c = 'Z';
	while(c >= 'A'){
		cout << c << " ";
		c -= 3;
	}
	cout << endl;

	
	
}








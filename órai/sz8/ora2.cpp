#include <iostream>

using namespace std;

int main(){

	//össszehasonlító operátorok
	//== != <= >= < >
	//logikai operátorok
	//&& || ! --és, vagy, negáció
	
	bool b =  60 < 5;
	
	cout << !b << " " << (b && true) << " " << ((60 < 5) || true) << endl;
	
	//bitműveletek
	//& | ^ << >>     bitenkénti és, vagy, XOR, eltolás balra, eltolás jobbra
	
	int A = 60;
	int B = 13;
	
	cout << (A&B) << " " << (A | B) << " " << (A << 2) << endl;
	
	//értékadó operátorok
	// = += -= *= /= %= &= |= ^= <<= >>=
	//A += 10         A = A + 10
	//A <<= 5	  A = A << 5
	
	A += 10;
	
	cout << A << endl;
	
	int tomb[5] = {1, 2, 3, 4, 5};
	
	tomb[0] = 15;
	
	cout << tomb[0] << " " << tomb[4] << endl;
	
	cout << tomb[150] << endl;
	
	
	
	char sztring[] = "Hello, world!";
	
	sztring[0] = 'h';
	
	cout << sztring << endl;
	
	//sztring = "hello, Hello, world! Hello, world! Hello, world!";
	
	//std::string
	string s = "Hello, world!";
	s[0] = 'h';
	cout <<s << endl;
	s = "hello, Hello, world! Hello, world! Hello, world!";
	
	
	//típuskonverzió
	//implicit
	
	int n = 92;
	double d = n;
	
	d = 92.123;
	n = d;
	
	//explicit
	n = int(d);
	
	cout << char(n) << " " << int('A') << endl;
	
	//elágazás
	//feltételes utasítás
	
	if( 21 < 10 ){
		cout << " kisebb "<<endl;
	}
	
	if( 0 ){
		cout << " hamis " << endl;
	}
	
	if( false ){
		cout << " hamis " << endl;
	}
	
	if( 123 ){
		cout << " igaz " << endl;
	}
	
	if( A ){
		cout << " igaz " << endl;
	}
	
	if( 'c' ){
		cout << " igaz " << endl;
	}
	
	if( A == 15 ){// A = 15 és A ==15 különbözik.
		cout << " igaz " << endl;
	}
	
	if(21 < 10){
		cout << "kisebb" << endl;
	} else {
		cout << "nagyobb, vagy egyenlő" << endl;
	}
	
	if(21 < 10){
		cout << "kisebb" << endl;
	} else if(21 == 10){
		cout << "egyenlő" << endl;
	} else {
		cout << "nagyobb" << endl;
	}
	
	int nap = 2;
	
	if(nap == 1){
		cout << "hétfő" << endl;
	} else if (nap == 2){
		cout << "kedd" << endl;
	} else if (nap == 3) {
		cout << "szerda" << endl;
	}
	
	switch(nap){
		case 1:
			cout<< "hétfő" << endl;
			break;
		case 2:
			cout << "kedd" << endl;
			break;
		case 3:
			cout << "szerda" << endl;
			break;
		default:
			cout << "hétvége" << endl;
	}
	
	
	//ternáris op
	// feltétel ? ha igaz : ha hamis;
	
	int x1 = 1;
	int y1 = 10;
	string eredmeny = x1 > y1 ? "nagyobb" : "nem nagyobb";
	
	eredmeny = x1 > y1 ? "nagyobb" : x1 == y1 ? "egyenlő" : "kisebb";
	
	cout << eredmeny << endl;
	
	//előltesztelő ciklus -- 0..n alkalommal fut le
	//while
	
	int i = 0;
	
	while(i < 10){
		cout << i << " " ;
		i++;
	}
	cout << endl;
	
	float f = 10.0;
	
	while(f > 4.9){
		cout << f << " ";
		f-=0.1;
	}
	cout << endl;
	
	char c = 'A';
	
	while(c <= 'Z'){
		cout << c << " " << int(c) << endl;
		c++;
	}
	
	c = 'Z';
	
	while(c >= 'A'){
		cout << c << " " ;
		c-=2;
	}
	cout << endl;
	
	//hátultesztelő ciklus -- 1..n alkalommal fut
	//do-while
	i = 11;
	
	do{
		cout << i << endl;
		i++;
	}while(i < 10);
	
	//előírt / meghatározott lépésszámú ciklus
	//for
	//for(ciklusváltozó inicializálása; leállási feltétel; ciklusváltozó értékváltozása)
	
	for(int i = 0; i < 10; i++){
		cout << i << " " ;
	}
	cout << endl;
	
	for(char c = 'z'; c >= 'a' ; c--){
		cout << c << " " ;
	}
	cout << endl;
	
	cout << int('a' - 'A') << endl;
	
	for(char c = 'A'; c <= 'Z'; c++){
	
		cout << c << char(c+'a'-'A');
	}
	cout << endl;
	
	for(char c = 'A', x = 'a'; c<= 'Z'; c++, x++){
		cout<< c<< x;
	}
	cout << endl;
	
	
	/*while(true){
		cout << "végtelen ciklus" << endl;
	}*/
	
	/*for(;;){
		cout << "végtelen ciklus" << endl;
	}*/
	
	for(int i = 0;;){
		cout << i++ << endl;
		if(i == 10){
			break; //vezérlésátadó utasítás
		}
	}
	
	for(int i = 0; i<10; i++){
		if( (i%2 == 0) || (i%3 ==0)){
			continue;//vezérlésátadó
		}
		cout << i << " ";
	}
	cout << endl;
	
	//foreach
	//for(konténer_1_elemének_típusa változónév: konténer)
	int meret = 5;
	int szamok[meret] = {1,2,3,4,5};
	
	for(int szam: szamok){
		cout << szam << " ";
	}
	cout << endl;
	
	for(int i = 0; i<meret; i++){
		cout << szamok[i] << " " ;
	}
	cout << endl;
	
	//sizeof(szamok)  ==>  (int) 4byte * 5(elemek száma) ==> 20byte
	//sizeof(int) ==> 4byte
	
	for(int i = 0; i< sizeof(szamok)/sizeof(int); i++){
		cout << szamok[i] << " ";
	}
	cout << endl;
	
	int szam2d[3][3] = {
		{1,2,4},
		{4,5,7},
		{7,8,10}
	};
	
	//sorátlag
	int osszeg;
	for(int i = 0; i<3; i++){
		osszeg = 0;
		for(int j = 0; j< 3; j++){
			osszeg += szam2d[i][j];
		}
		cout << osszeg/3.0f << endl;
	}
	
	
	
	
	
	
	





}






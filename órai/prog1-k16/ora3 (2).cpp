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
	
	
	
	
	
	
	
	//előltesztelő ciklus -- 0..n alkalommal fut le
	//while
	//while(feltétel){ciklusmag}
	
	int j = 0;
	while(j < 10){
		cout << j << " ";
		j++;
	}
	
	cout << endl;
	
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
	
	c = 'Z';
	while(c >= 'A'){
		cout << c << " ";
		c -= 3;
	}
	cout << endl;
	
	//hátultesztelő ciklus
	//do-while 1..n alkalommal fut le
	
	i = 10;
	do{
		cout << "hátultesztelő ciklus" << endl;
	}while(i < 10);
	
	//előírt/meghatározott lépésszámú ciklus
	//for
	//for(ciklusváltozó inicializálása; leállási feltétel; ciklusváltozó értékváltozása)
	
	for(int i = 0; i<10 ; i++){
		cout << i << " ";
	}
	cout << endl;
	
	for(char c = 'a'; c <= 'z' ; c++){
		cout << c;
	}
	cout << endl;

	cout << int('A'-'a') << endl;
	
	for (char c='A'; c<='Z';c++){
		cout<<c<<char(c+'a'-'A');
	}
	cout << endl;
	
	for(char c='A', x='a'; c<='Z' ; c++, x++){
		cout << c << " " << x << endl;
	}
	
	//while(a = 1)
	/*while(true){
		cout << "Végtelen ciklus" << endl;
	}*/
	
	/*for(;;){
		cout << "végtelen ciklus" << endl;
	}*/
	
	for(int i = 0;;){
		cout << i++<< " ";
		if(i == 10){
			break; //vezérlésátadó utasítás
		}
	}
	cout << endl;
	
	for(int i = 0; i< 10; i++){
		if((i % 2 == 0) || (i % 3) == 0){
			continue;//vezérlésátadó utasítás
		}
		cout << i << " ";
	}
	cout << endl;
	
	//foreach
	//for(konténer_1_elemének_típusa változónév : konténer)
	
	int meret = 5;
	int szamok[meret] = {1,2,3,4,5};
	
	for(int szam : szamok){
		cout << szam << " " ;
	}
	cout << endl;
	
	for(int i = 0; i<meret; i++){
		cout << szamok[i] << " " ;
	}
	cout << endl;
	
	//sizeof(szamok) ==> (int) 4byte * 5(elemek száma)
	//sizeof(int)	 ==> 4byte
	
	for(int i = 0; i < sizeof(szamok)/sizeof(int) ; i++){
		cout << szamok[i] << "  ";
	}
	cout << endl;
	
	
	int szamok2d[3][3] = {
		{1,2,4},
		{4,5,7},
		{7,8,10}
	};
	
	for(int i = 0; i<3; i++){
		for(int j = 0; j<3; j++){
			cout << szamok2d[i][j] << " " ;
		}
		cout << endl;
	}
	
	int osszeg;
	for(int i = 0; i<3; i++){
		osszeg = 0;
		for(int j = 0; j<3; j++){
			osszeg += szamok2d[i][j];
		}
		cout << "Átlag " << osszeg/3.0f << endl;
	}
	
	int o1=0;
	int o2=0;
	for(int i = 0; i< 3; i++){
		o1+= szamok2d[i][i];
		o2+= szamok2d[i][2-i];
	}
	cout << o1/3.0f << " " << o2/3.0f << endl;
	
}








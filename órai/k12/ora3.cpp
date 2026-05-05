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
	
	//hátultesztelő ciklus
	//do - while
	//legalább 1 alkalommal lefut
	
	i = 10;
	do{
		cout << "hátultesztelő ciklus" << endl;
	} while(i < 10);
	
	//meghatározott/előírt lépésszámú ciklus
	//for
	//for (ciklusváltozó inicializálása; leállási feltétel; cilusváltozó értékváltozása)
	
	for(int i = 0; i<10; i++){
		cout << i<< " ";
	}
	cout << endl;
	
	for(char c = 'a'; c <= 'z' ; c++){
		cout << c;
	}
	cout << endl;
	
	for (char c='A'; c<='Z';c++){
		cout<<c<<char(c+32);
	}
	cout << endl;
	
	/*while(true){
		cout << "végtelen ciklus" << endl;
	}*/
	
	/*for(;;){
		cout << "végtelen ciklus" << endl;
	}*/
	
	for(int i = 0;;){
		cout << ++i;
		if( i== 10){
			break; //vezérlésátadó utasítás
		}
	}
	cout << endl;
	
	
	
	//foreach
	//for(konténer_1_elemének_típusa változónév: konténer_neve)
	int tombmeret = 5;
	int szam[tombmeret] = {1,2,3,4,5};
	
	for(int sz: szam){
		cout << sz << " " ;
	}
	cout << endl;
	
	for(int i = 0; i<tombmeret; i++){
		cout << szam[i] << " ";
	}
	cout << endl;
	
	//sizeof(szam)    === 20   (tömb méret)5 * 4 (integer)
	//sizeof(int)     === 4
	
	for(int i = 0; i< sizeof(szam)/sizeof(int); i++){
		cout << szam[i] << " " ;
	}
	cout << endl;
	
	for(int i = 0; i<10; i++){
		if((i % 2 == 0) || (i % 3 == 0)){
			continue;
		}
		cout << i << " ";
	}
	cout << endl;
	
	char betuk[2][4]{
		{'a','b','c','d'},
		{'e','f','g','h'}
	};
	
	for(int i = 0; i<2; i++){
	
		for(int j = 0; j < 4; j++){
			cout << betuk[i][j] << " " ;
		
		}
		cout << endl;
	}
	
	int szam2d[3][4] = {
		{1,2,3,4},
		{5,6,7,8},
		{9,10,11,12}
	};
	
	int osszeg;
	for(int i = 0; i< 3; i++){
		osszeg = 0;
		for(int j = 0; j< 4; j++){
			osszeg+= szam2d[i][j];
		}
		cout << osszeg/4.0f << endl;
	}
	
	for(int i = 0; i< 4; i++){
		osszeg = 0;
		for(int j = 0; j< 3; j++){
			osszeg += szam2d[j][i];
		}
		cout << osszeg/3.0f << endl;
	}
	
	//maximum kiválasztás
	
	int max;
	for(int i = 0; i< 4; i++){
		max = szam2d[0][i];
		for(int j = 0; j< 3; j++){
			if(szam2d[j][i] > max){
				max = szam2d[j][i];
			}
		}
		cout << max<< endl;
	}
	
	
	
	

	
	
	
	
	
}









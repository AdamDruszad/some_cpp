#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <string>
#include <array>
#include <sstream>

using namespace std;

/**
1. feladat Írjon függvényt, amelynek két integer paramétere van, a visszatérési értéke pedig a két szám közötti legnagyobb fibonacci szám.
*/

int legnagyobbFibonacci(int a, int b){
	int also, felso;
	if(a < b){
		also = a;
		felso = b;
	} else {
		also = b;
		felso = a;
	}
	
	int legnagyobb = -1;
	int x = 0;
	int y = 1;
	while( x <= felso){
		if( x >= also ){
			legnagyobb = x;
		}
		
		int kov = x + y;
		x = y;
		y = kov;
	}
	return legnagyobb;
	
}

/**
2. feladat Írjon függvényt, amelynek egy 4x4-es kétdimenziós tömb a paramétere és visszaadja a soronkénti átlagokat egy egydimenziós 4 méretű tömbben.
*/

int* soratlag(int t[4][4]){
	int* tomb = new int[4];
	return tomb;
}

array<double, 4> soratlag2(int t[4][4]){
	array<double, 4> atlagok;
	for(int i = 0; i<4; i++){
		int osszeg = 0;
		for(int j = 0; j<4; j++){
			osszeg += t[i][j];
		}
		atlagok[i] = osszeg /= 4.0;
	}
	return atlagok;
}

/**
3. feladat Írjon függvényt, amelynek van egy karakter (a), egy 10 méretű karakter tömb és  egy integer (b) paramétere, visszatérési értéke void. A függvény másolja be a tömb b-edik elemének értékét az a karakterbe.

*/

void fv3(char& a, char t[10], int b){
	a = t[b];
}

struct Doboz{
	int szelesseg;
	int magassag;
	int melyseg;
};

int main(){
	cout << legnagyobbFibonacci(1,10) << endl ;
	int tomb1[4][4] = {{1, 2, 3, 4},
			   {5, 6, 7, 8},
			   {9, 10, 11, 12},
			   {13, 14, 15, 16}};
	int* t = soratlag(tomb1);
	
	for(double d : soratlag2(tomb1)){
		cout << d << " " ;
	}
	cout << endl;
	
	/**
	Kérjen be a felhasználótól egy egész számot, majd a megadott számosságú szóköz nélküli stringet. Írja ki a képernyőre a legrövidebbet és leghosszabbat.

	*/
	
	int n;
	cout << "Adjon meg egy egész számot!" << endl;
	cin >> n;
	
	string st[n];
	//string* st = new string[n];
	//vector<string> st;
	for(int i = 0; i<n; i++){
		cout << "Adjon meg egy szóköz nélküli stringet" << endl;
		cin >> st[i];
	}
	
	string rovid = st[0];
	string hosszu = st[0];
	
	for(int i = 0; i<n ; i++){
		if(st[i].length() > hosszu.length()){
			hosszu = st[i];
		}
		if(st[i].length() < rovid.length()){
			rovid = st[i];
		}
	}
	
	cout << hosszu << " " << rovid << endl;
	
	/**
	5. feladat Hozzon létre egy osztályt vagy struktúrát Doboz néven, amelynek van szélessége, magassága, mélysége. Töltsön fel egy 5 méretű tömböt dobozokkal. Írja ki, hogy ha ezeket a dobozokat egymás tetejére tesszük, milyen magas lesz a torony.

	*/
	
	Doboz dt[5] = {{1,1,1},{2,2,2},{3,3,3,},{4,4,4},{5,5,5}};
	
	int toronymagassag=0;
	
	for(int i = 0; i<5; i++){
		toronymagassag += dt[i].magassag;
	}
	
	cout << "A torony teljes magassága: " << toronymagassag << endl;
	
	/**
	6. feladat Olvassa be a randomok.txt állományt egy tetszőleges adatszerkezetbe. Soronként döntse el, hogy az adott sor átlaga kisebb-e mint 37. Az eldöntés eredményét (Igen/Nem) írja be soronként a kisebb.txt-be.
	*/
	
	ifstream be("randomok.txt");
	ofstream ki("kisebb.txt");
	
	vector<vector<int>> adatok;
	string sor;
	
	while(getline(be, sor)){
		stringstream ss(sor);
		vector<int> egysor;
		int szam;
		
		while(ss >> szam){
			egysor.push_back(szam);
		}
		
		adatok.push_back(egysor);
	}
	
	for(int i=0; i<adatok.size(); i++){
		int osszeg = 0;
		for(int j = 0; j< adatok[i].size(); j++){
			osszeg += adatok[i][j];
		}
		double atlag = (double)osszeg / adatok[i].size();
		
		if(atlag < 37){
			ki << "Igen" << endl;
		} else {
			ki << "Nem" << endl;
		}
	}
	
	be.close();
	ki.close();
	
	
	
	
	
	
	


}

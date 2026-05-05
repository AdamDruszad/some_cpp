#include <iostream>
#include <vector>
#include <fstream>
#include <string>

using namespace std;

struct Allat{
	string fajta;
	int magassag;
};
//cin >> a
istream& operator>>(istream& is, Allat& a){
	is >> a.fajta >> a.magassag;
	return is;
}
//cout << a
ostream& operator<<(ostream& os, Allat a){
	os << a.fajta << "\t" << a.magassag;
	return os; 
}




int main(){

	/*int x, y;
	cout << "Kérem adjon meg egy egész számot!" << endl;
	cin >> x;
	cout << "Kérem adjon meg egy egész számot!" << endl;
	cin >> y;
	
	cout << "A két szám összege: " << x+y << endl;
	
	cout << "Kérem adjon meg két egész számot!" << endl;
	cin >> x >> y;
	cout << "A két szám összege: " << x+y << endl;
	
	string s;
	cout << "sztring?" << endl;
	cin >> s;
	cout << s << endl;
	
	Allat a;
	cout << "Állat?" << endl;
	//cin >> a;
	//cin >> a.fajta >> a.magassag;
	//cout << a.fajta << " " << a.magassag << endl;
	cin >> a;
	cout << a << endl;*/
	
	int n;
	cout << "Hány állatot szeretne felvenni?" << endl;
	cin >> n;
	
	vector<Allat> allatok;
	
	for(int i = 0; i<n ;i++){
		Allat a;
		cin >> a;
		
		allatok.push_back(a);
	}
	
	for(Allat a : allatok){
		cout << a << endl;
	}
	
	/**
		Fájlkezelés
		ofstream - létrehoz, ír --output filestream
		ifstream - olvas -- input filestream
		fstream - létrehoz, ír, olvas
	*/
	
	/**
		1. létrehozás (logikai áll.)
		2. összerendelés (logikai - fizikai);
		3. megnyitás 
	*/
	ofstream outfile("file1.txt");
	
	/**
		4. feldolgozás
	*/
	
	outfile  << "Megnyitottam a fájlt írásra" << endl;
	outfile  << "Második sor" << endl;
	outfile  << "Harmadik sor" << endl;
	
	/**
		5. bezárás
	*/
	outfile.close();
	
	
	ifstream infile("file1.txt");
	
	string text;
	
	//getline - stringbe olvas. Ha a string tartalmaz szóközöket
	while( getline(infile, text) ){
		cout << text << endl;
	}
	
	infile.close();
	
	ofstream oa("allatok.txt");
	
	for(Allat a : allatok){
		//oa << a << endl;
		oa << a.fajta << "\t" << a.magassag << endl;
	}
	
	oa.close();
	
	ifstream ia("allatok.txt");
	
	vector<Allat> beolvasott;
	Allat inputa;
	
//	while(ia >> inputa){
	while(ia >> inputa.fajta >> inputa.magassag){
		beolvasott.push_back(inputa);
	}
	
	ia.close();
	
	Allat legalacsonyabb = beolvasott.at(0);
	
	for(int i = 0; i< beolvasott.size(); i++){
		if(beolvasott[i].magassag < legalacsonyabb.magassag){
			legalacsonyabb = beolvasott[i];
		}
	}
	
	cout << "A legalacsonyabb állat adatai: " << legalacsonyabb << endl;
	
	//Írjuk ki egy állományba az átlagosnál magasabb állatok
	
	float atlag = 0.0f;
	for(Allat a : beolvasott){
		atlag += a.magassag;
	}
	atlag/=float(beolvasott.size());
	cout << atlag << endl;
	
	ofstream atlagnalmagasabb("magasabb.txt");
	
	for(Allat a : beolvasott){
		if(a.magassag > atlag){
			atlagnalmagasabb << a << endl;
		}
	}
	












}

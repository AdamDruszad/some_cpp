#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

struct Allat{
	string nev;
	int kor;
};


istream& operator>>( istream& is, Allat& a){
	is >> a.nev >> a.kor;
	return is;
}

ostream& operator<<( ostream& os, Allat& a){
	os << a.nev << "\t" << a.kor << endl;
	return os;
}

int main(){

	vector<Allat> allatok;
	int n = 0;
	
	cout << "Hány állatot szeretnél felvenni?" << endl;
	cin >> n;
	
	for(int i = 0; i<n; i++){
		Allat a;
		cin >> a;
		
		allatok.push_back(a);
	}
	
	
	for(Allat a : allatok){
		cout << a;
	}
	
	/**
		Fájlkezelés
		ofstream - létrehoz és ír -- output file stream
		ifstream - olvas -- input filestream
		fstream - létrehoz, ír, olvas -- file stream
	*/
	
	//1. létrehozás (logikai áll), 2 Összerendelés, 3. megnyitás
	ofstream outfile("filename.txt");
	
	//feldolgozás
	outfile << "Megnyitottam a fájlt írásra "<< endl;
	
	//bezárás
	outfile.close();
	
	
	ifstream infile("filename.txt");
	string text;
	
	//getline - stringbe olvas, ha a string  tartalmaz szóközöket
	while( getline(infile, text )){
		cout << text;

}
	infile.close();
	
	outfile.open("filename.txt");
	
	outfile <<"alma körte" << endl;
	outfile << "banán, mandarin" << endl;
	
	outfile.close();
	
	//get stringbe olvas, ha a string  tartalmaz szóközöket
	
	infile.open("filename.txt");
	
	/*while( getline(readFile, text) ){
		cout << text << endl;
	}
	
	readFile.close();*/
	
	char str[5];
    	infile.get(str, 5);    
    	std::cout << "after reading " << str << ", gcount() == " <<  infile.gcount() << endl;
    	
    	//szóközöket tartalmazó stringre
    	infile.get(str, 5);    
    	std::cout << "after reading " << str << ", gcount() == " <<  infile.gcount() << endl;
    	
    	infile.close();
    	
    	infile.open("filename.txt");
    	
    	//szóközöket nem tartalmazó stringek
    	infile >> text;
    	cout << text << endl;
    	
    	ofstream allatfile("allatok.txt");
    	for(Allat a : allatok){
    		allatfile << a;
    	}
    	
    	allatfile.close();
    	
    	
    	ifstream inallat("allatok.txt");
    	Allat allatolvas;
    	vector<Allat> allatv;
    	
    	while(inallat >> allatolvas){
    	//while(inallat >> allatolvas.nev >> allatolvas.kor){
    		allatv.push_back(allatolvas);
    	}
    	
    	//int min = allatv[0].kor;
    	//int minind =0;
    	
    	Allat legfiatalabb = allatv[0];
    	
    	for(int i = 0; i< allatv.size(); i++){
    	
    		if(allatv[i].kor <= legfiatalabb.kor){
    			legfiatalabb = allatv[i];
    		}
    	
    		/*if(allatv[i].kor < min){
    			min = allatv[i].kor;
    			minind = i;
    		}*/
    	}
    	
    	cout << "A legfiatalabb állat " << legfiatalabb.nev << " " << legfiatalabb.kor << " éves." << endl;













}

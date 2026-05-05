#include <iostream>
#include <vector>
#include <fstream>
#include <string>

using namespace std;


struct Allat{
	string nev;
	int kor;
};

istream& operator>>(istream& is, Allat& a){
	is >> a.nev >> a.kor;
	return is;
}

ostream& operator<<(ostream& os, Allat a){
	os << a.nev << "\t" << a.kor << endl;
	return os;
}

int main(){

	/*int x, y;
	cout << "Adjon meg egy egész számot!" << endl;
	cin >> x;	
	cout << "Adjon meg egy másik számot!" << endl;
	cin >> y;
	
	cout << "A két szám összege: "<< x+y << endl; 
	
	cin >> x >> y;
	cout << "A két szám összege: "<< x+y << endl; 
	
	string s;
	cout << "Adjon meg egy stringet!" << endl;
	cin >> s;
	cout << s << endl;
	
	Allat a;
	//cin >> a.nev >> a.kor;
	//cout << a.nev << " " << a.kor << endl;
	cin >> a;
	cout << a;*/
	
	vector<Allat> allatok;
	int n;
	
	cout << "Hány állatot szeretne felvenni?" << endl;
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
		ofstream - output filestream - létrehoz és ír
		ifstream - input filestream - olvas
		fstream - filestream - ír, olvas
	*/
	
	//1. létrehozás (logikai áll), 2. összerendelés, 3. megnyitás
	ofstream myfile("f1.txt"); //"f1.txt" relatív elérési 
	
	//4. feldolgozás
	myfile << "Megnyitottam az állományt írásra." << endl;
	myfile << "Második sor" << endl;
	
	//5. bezárás
	myfile.close();
	
	string text;
	
	ifstream inputfile("f1.txt");
	
	while( getline(inputfile, text)){
		cout << text << endl;
	}
	
	inputfile.close();
	
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
    	
    	/**
    		Állományok megnyitásának módjai:
    		
    		ios::in Olvasás
    		ios::out Írás
    		ios::trunc Ha létezik, a tartalmát töröljük
    		ios::app Append, hozzáfűzés, minden kimenet az állomány végére kerül
    		ios::ate megnyitja a fájlt írásra, és read/write vezérlés az állomány végére kerül
    	*/
    	
    	fstream outfile;
    	outfile.open("allatok.txt", ios::out | ios::trunc);
    	outfile.close();
	
	
	
	
	
	
}

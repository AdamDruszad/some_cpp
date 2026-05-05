#include <iostream>
#include <vector>
#include <fstream>
#include <string>

using namespace std;

struct Allat{
	string nev;
	int kor;
};

istream& operator>>( istream& i, Allat& a){
	i >> a.nev >> a.kor;
	return i;
}

ostream& operator<<( ostream& o, Allat& a){
	o << a.nev << "\t" << a.kor << endl;
	return o;
}

int main(){

	vector<Allat> allatok;
	int n = 0;
	
	cout << "Hány állatot szeretne felvenni?" << endl;
	cin >> n;
	
	for(int i = 0; i< n ; i++){
		Allat a;
		cin >> a;
		
		allatok.push_back(a);
	}
	
	for(Allat a : allatok){
		cout << a;
	}
	
	/**
		ofstream - létrehoz és ír -- output file stream
		ifstream - olvas -- input file stream
		fstream - létrehoz, ír, olvas -- filestream
	*/
	
	//létrehozás(logikai állomány), összerendelés, megnyitás
	ofstream Myfile("filename.txt");
	
	Myfile << "Megnyitottam a fájlt írásra" << endl; //feldolgozás
	
	Myfile.close(); //bezárás
	
	string text;
	
	ifstream readFile("filename.txt");
	
	while( getline(readFile, text) ){
		cout << text << endl;
	}
	
	readFile.close();
	
	Myfile.open("filename.txt");
	
	Myfile << "alma körte" << endl;
	Myfile << "barack narancs" << endl;
	
	Myfile.close();
	
	readFile.open("filename.txt");
	
	/*while( getline(readFile, text) ){
		cout << text << endl;
	}
	
	readFile.close();*/
	
	char str[5];
    	readFile.get(str, 5);    
    	std::cout << "after reading " << str << ", gcount() == " <<  readFile.gcount() << endl;
    	
    	//szóközöket tartalmazó stringre
    	readFile.get(str, 5);    
    	std::cout << "after reading " << str << ", gcount() == " <<  readFile.gcount() << endl;
    	
    	readFile.close();
    	
    	
    	readFile.open("filename.txt");
    	
    	//szóközöket nem tartalmazó stringre
    	readFile >> text;
    	cout << text << endl;
    	
    	ofstream allatfile("allatok.txt");
    	for(Allat a : allatok){
    		allatfile << a;
    	}
    	
    	allatfile.close();
    	
    	ifstream inallat("allatok.txt");
    	Allat allatolvas;
    	vector<Allat> allatv;
    	
    	//while(inallat >> allatolvas){
    	while(inallat >> allatolvas.nev >> allatolvas.kor){
    		allatv.push_back(allatolvas);
    	}
    	
    	//int max = 0;
    	//int maxind =0;
    	
    	Allat legidosebb = allatv[0];
    	
    	for(int i = 0; i< allatv.size(); i++){
    	
    		if(allatv[i].kor > legidosebb.kor){
    			legidosebb = allatv[i];
    		}
    	
    		/*if(allatv[i].kor > max){
    			max = allatv[i].kor;
    			maxind = i;
    		}*/
    	}
    	
    	cout << "A legidősebb állat " << allatv[maxind].nev << " " << allatv[maxind].kor << " éves." << endl;
    	
    	/**
    		Állományok megnyitásának módjai:
    		
    		ios::in Olvasás
    		ios::out Írás
    		ios::trunc Ha a fájl létezik, a tartalmát töröljük megnyitás után
    		ios::app Append - hozzáfűzés, minden kimenet az állomány végére kerül
    		ios::ate Megnyitja az állományt írásra, a read/write vezérlés az állomány végére kerül
 
    	*/
    	
    	fstream ffile;
    	ffile.open("allatok.txt", ios::out | ios:: trunc);
    	ffile.close();
    	
    	
    	
	
	
	



}

#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
#include <string>

using namespace std;

int fibonacci(int x){
	if ((x ==1)  || (x ==0)){
		return x;
	} else {
		return fibonacci(x-1)+fibonacci(x-2);
	}
}

int feladat1(int a, int b){

	for(int i = b; i>0; i--){
		if((fibonacci(i) >= a) && (fibonacci(i) <=b)){
			return fibonacci(i);
		}
	} 
	
	return 0;	
}

int* feladat2(int t[4][4]){
	int* tomb = new int[4];
	
	float atlag;
	for(int i = 0; i< 4; i++){
		atlag = 0.0f;
		for(int j =0 ; j<4; j++){
			atlag += t[i][j];
		}
		atlag /= 4.0f;
		
		tomb[i] = atlag;
	}
	
	return tomb;
}

void feladat3(char& c, char ct[10], int b){
	c = ct[b];
}

struct Doboz{
	int szelesseg;
	int magassag;
	int melyseg;
};

int main(){
	//feladat1
	cout << feladat1(1,10) << endl;
	
	//feladat2
	int tin[4][4] = {{1, 2, 3, 4},
			 {5, 6, 7, 8},
			 {9, 10, 11, 12},
			 {13, 14, 15, 16}};
	
	int* tomb = feladat2(tin);
	
	for(int i = 0; i<4; i++){
		cout << tomb[i] << endl;
	}
	
	char a = 'c';
	char ct[10] = {'a','b','c','d','e','f', 'g', 'h', 'i', 'j'};
	int b = 3;
	
	feladat3(a, ct, b);
	
	cout << a << endl;
	
	int n;
	cout << "Adjon meg egy egész számot!" << endl;
	cin >> n;
	
	string st[n];
	for(int i = 0; i<n; i++){
		cout<< "Adjon meg egy szóköz nélküli stringet" << endl;
		cin >> st[i];
	}
	
	string rovid = st[0];
	string hosszu = st[0];
	
	for(string s : st){
		if(s.length() > hosszu.length()){
			hosszu = s;
		}
		if(s.length() < rovid.length()){
			rovid = s;
		}
	}
	
	cout << rovid << " " << hosszu << endl;
	//5. feladat
	Doboz dt[5] = {
			{1,1,1,},
			{2,2,2},
			{3,3,3},
			{4,4,4},
			{5,5,5}};
			
	int osszeg = 0;
	
	for(int i = 0; i <5; i++){
		osszeg += dt[i].magassag;
	}
	
	cout << "A dobozok összmagassága " << osszeg << "." << endl;
	
	vector<int> randomok;
	
	ifstream ifile("randomok.txt");
	
	
	int q;
	
	while(ifile >> q){
		randomok.push_back(q);
	}
	
	ifile.close();
	
	ofstream ofile("kisebb.txt");
	
	int beatlag=0;
	int count = 0;
	for(int i = 0; i< randomok.size(); i++){
		beatlag += randomok.at(i);
		
		if(count % 5 ==0){
			if((beatlag/5) < 37){
				ofile << "Igen" << endl;
			} else {
				ofile << "Nem" << endl;
			}
			beatlag = 0;	
		}
		count++;	
			
	}
	ofile.close();
	
	
	
	
	











}

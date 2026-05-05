#include <iostream>
#include <vector>

using namespace std;

//túlterhelés - korai kötés - statikus kötés
//közös fv neve, de eltérő a paraméterezése

int absolute(int i){
	if (i < 0){
		return -i;
	}
	return i;
}

float absolute(float i){
	if (i < 0.0f){
		return -i;
	}
	return i;
}

int test(){return 0;}
int test(int a){return 0;}
float test(double d){return 0;}
int test(int a, int b){return 0;}

//test()
//test(1)
//test(3.2)
//test(1, 2)

//double test(int b){return 0;}
//test(1);
//double b = test(1);

void kiir(int i){
	cout << i << endl;
}

void kiir(double i){
	cout << i << endl;
}

void kiir(int i, double j){
	cout << i << " " << j <<endl;
}

/**
	Nem túlterhelezők:
		sizeof
		typeid
		scope resolution(::)
		osztálytag hozzáférés (.   .*)
		ternáris operátor(:?)

*/

/*void operator<<(vector<int>& v, int i){
	v.push_back(i);
}*/

vector<int>& operator<<(vector<int>& v , int i){
	v.push_back(i);
	return v;
}

vector<int> operator+(const vector<int> a, const vector<int> b){
	vector<int> o;
	for(int i : a){
		o.push_back(i);
	}
	for(int i : b){
		o.push_back(i);
	}	
	return o;
}

void operator++(vector<int> v){
	for(int i : v){
		cout << i << " " ;
	}
	cout << endl;
}

struct szemely{
	string nev;
	int kor;
	
	void operator()(string n, int e){
		nev = n;
		kor = e;
	}
};

ostream& operator<<(ostream& os, szemely sz){
	os << sz.nev << " " << sz.kor;
	return os;
}

void operator>>(istream& is, szemely& sz){
	is >> sz.nev >> sz.kor;
}


int main(){

	absolute(1);
	absolute(-1.23f);
	
	int a = 2;
	double d = 3.21;
	
	kiir(a);
	kiir(d);
	kiir(a,d);
	
	vector<int> vi = {0,1,2};
	vi.push_back(3);
	
	vi << 4;
	
	for(int i : vi){
		cout << i << " " ;
	}
	cout << endl;
	
	vi << 5 << 6 << 7 << 8;
	
	for(int i : vi){
		cout << i << " " ;
	}
	cout << endl;
	
	vector<int> v1 = {0,1,2,3};
	vector<int> v2 = {4,5,6,7};
	vector<int> o = v1 + v2;
	
	++o;
	
	szemely sz1;
	sz1.nev = "Árpád";
	sz1.kor = 33;
	
	szemely sz2;
	sz2("Kitti", 32);
	
	cout << sz1 << " " << sz2 << endl;
	
	int x, y;
	
	cout << "Adj meg egy egész számot!"<<endl;
	cin >> x;
	
	cout << "Adj meg egy egész számot!"<<endl;
	cin >> y;
	
	cout << "A két szám összege: " << x+y << endl;
	
	szemely sz3;
	cin >> sz3;
	cout << sz3 << endl;

	//FELADAT




}

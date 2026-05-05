#include <iostream>
#include <vector>

using namespace std;
//túlterhelés --statikus kötés -- korai kötés
//ugyanazzal a névvel, eltérő paraméterezéssel

int absolute(int i){
	if ( i < 0){
		return -i;
	}
	return i;
}

float absolute(float i){
	if ( i < 0.0f){
		return -i;
	}
	return i;
}

int test(){return 0;}
int test(int a){return 0;}
float test(double a){return 0;}
int test(int a, int b){return 0;}

//double test(int b){return 0;}

void kiir(int i){
	cout << i << endl;
}

void kiir(double i){
	cout << i << endl;
}
void kiir(int i, double j){
	cout << i << " " << j << endl;
}

/**
	nem túlterhelhetők:
	sizeof
	typeid
	scope resolution(::)
	osztálytag hozzáférés( .  .*)
	ternáris operátor (?:)   

*/

/*void operator<<(vector<int>& a, int b){
	a.push_back(b);
}*/

vector<int>& operator<<(vector<int>& a, int b){
	a.push_back(b);
	return a;
}

vector<int> operator+(vector<int> a, vector<int> b){
	vector<int> o;
	for(int i : a){
		o << i;
	}
	for(int i : b){
		o << i;
	}
	return o;
}

struct Person{
	string name;
	int age;
	
	void operator()(string n, int e){
		name = n;
		age = e;
	}
};

ostream& operator<<( ostream& os, const Person p){
	os << p.name << " " << p.age;
	return os;
}

void operator>>( istream& is, Person& p){
	is >> p.name >> p.age;
}

int main(){

	absolute(1);
	absolute(-1.2f);
	
	//test(2);
	
	int a = 5;
	double d = 1.23;
	
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
	
	vi << 5 << 6 << 7;
	
	for(int i : vi){
		cout << i << " " ;
	}
	cout << endl;
	
	vector<int> v1 = {1,2,3,4};
	vector<int> v2 = {5,6,7,8};
	
	vector<int> o = v1 + v2;
	
	for(int i : o){
		cout << i << " " ;
	}
	cout << endl;
	
	Person p1;
	p1.name = "Ricsi";
	p1.age = 32;
	
	Person p2;
	p2("Angéla", 25);
	
	cout << p1 << " " << p2 << endl;
	
	int x, y;
	int sum;
	
	cout << "Adj meg egy egész számot!" << endl;
	cin >> x;

	cout << "Adj meg egy egész számot!" << endl;
	cin >> y;
	
	cout << "A két szám összege: " << x+y << endl;
	
	Person p3;
	cout << "Add meg a személy nevét és korát" << endl;
	cin >> p3;
	cout << p3;
	
	//FELADAT



}






#include <iostream>
#include <vector>

using namespace std;

//túlterhelés - korai kötés - statikus kötés - fordítás idejű polimorfizmus - függvénypolimorfizmus
//azonos név, eltérő paraméterezés(számosság, típus)

int absolute(int i){
	if(i < 0){
		return -i;
	}
	return i;
}

float absolute(float f){
	if(f < 0.0f){
		return -f;
	}
	return f;
}

int test(){return 0;};
int test(int a){return 0;}
int test(float a){return 0;}
float test(double d){return 0;}
int test(int a, int b){return 0;}

//test()
//test(1)
//test(1.2f)
//test(2.1)
//test(-1,-2)

//double test(int b){return 0;}
//test(4)
//double d = test(2);

/**
	Nem túlterhelhető:
		sizeof
		typeid
		scope resolution(::)
		osztálytag( .    .*)
		ternáris operátor(?:)

*/

/*void operator<<(vector<int>& v, int i){
	v.push_back(i);
}*/

vector<int>& operator<<(vector<int>& v , int i){
	v.push_back(i);
	return v;
}

vector<int> operator+(const vector<int> v, const vector<int> w){
	vector<int> ossz;
	for(int i : v){
		ossz<<i;
	}

	for(int i : w){
		ossz<<i;
	}
	
	return ossz;
}

void operator++(vector<int> v){
	for(int i : v){
		cout << i << " ";
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

int main(){

	absolute(2);
	absolute(2.14f);
	
	vector<int> v = {0,1,2};
	
	v.push_back(3);
	
	v << 4;
	
	for(int i : v){
		cout << i << " " ;
	}
	cout << endl;
	
	v << 5 << 6 << 7;
	
	++v;
	
	szemely sz1;
	sz1.nev = "Kitti";
	sz1.kor = 33;
	
	szemely sz2;
	sz2("András",24);
	
	cout << sz1 << " " << sz2 << endl;
	
	














}

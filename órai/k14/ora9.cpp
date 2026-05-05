#include <iostream>
#include <list>
#include <set>
#include <vector>
#include <map>


using namespace std;

int main(){

//container library
//adattárolás módja
//adatok elérhetősége
//tárterület
	list<int> l;
	
	for(int i = 0; i<20; i++){
		l.push_back(i*2);
		l.push_front(i);
	}
	
	//cout << l[0] << endl;
	
	/*for(int i : l){
		cout << i << " " << &i << endl;
	}
	
	for(auto it = l.begin(); it != l.end(); it++){
		cout << *it << " " ;
	}
	cout << endl;*/
	
	list<int>::iterator it;
	for(it = l.begin(); it != l.end(); it++){
		cout << *it << " " ;
	}
	cout << endl;
	
	l.pop_back();
	l.pop_front();
	
	it = ++(++(++(++l.begin())));
	
	l.erase(it);
	
	for(it = l.begin(); it != l.end(); it++){
		*it = *it*2;
		cout << *it << " " ;
	}
	
	l.sort();
	
	
	set<int> s;
	
	s.insert(50);
	s.insert(10);
	s.insert(10);
	s.insert(60);
	s.insert(25);
	s.insert(15);
	s.insert(50);
	s.insert(50);
	
	cout << "SET: " << endl;
	
	for(int i : s){
		cout << i << " " << &i << endl;
	}
	
	set<int>::iterator itr;
	
	for(itr = s.begin(); itr != s.end(); itr++){
		//*itr = 2;
		cout << *itr << endl;
	}
	
	s.erase(50);
	cout << s.contains(10) << endl;
	cout << *s.find(15) << endl;
	
	vector<int> v = {1,234,5436,657434,5,234,4356,2,1,1,3,2,56,45,34,67,45};
	
	set<int> sv(v.begin(), v.end());
	
	v.clear();
	
	v.assign(sv.begin(), sv.end());
	
	for(int i : v){
		cout << i << " " ;
	}
	cout << endl;
	//map<kulcs, érték>
	
	map<string, string> nevek;
	
	nevek.insert({"Pista", "István"});
	nevek.insert({"Z", "Zoé"});
	nevek["Kopasz"] = "Tamás";
	nevek["Zoli"] = "Zoltán";
	
	/**
		map<int, string> x;
		x[2] = "a";
		x[11] = "e";
	*/
	
	cout << nevek["Z"] << endl;
	
	//for(auto a : nevek)
	for(std::pair<string, string> a : nevek){
		cout << a.first << " " << a.second << endl;
	}
	
	std::map<string, string>::iterator mit;
	
	for(mit = nevek.begin(); mit != nevek.end(); mit++){
		cout << mit->first << " " << mit->second << endl;
	}
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
}

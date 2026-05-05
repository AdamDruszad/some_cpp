#include <iostream>
#include <list>
#include <set>
#include <map>
#include <vector>

using namespace std;

int main(){

	//container library
	//adattárolás módjában
	//adatok elérhetősége
	//tárterület
	std::list<int> l;
	
	for(int i = 0; i<10; i++){
		l.push_back(i*2);
		l.push_front(i);
	}
	
	//cout << l[10] << endl;
	
	for(int i : l){
		cout << i << " " << &i << endl;
	}
	
	/*for(auto it = l.begin(); it != l.end(); it++){
		cout << *it << " ";
	}
	cout << endl;*/
	
	std::list<int>::iterator lit;
	for(lit = l.begin(); lit != l.end(); lit++){
		cout << *lit << " ";
	}
	cout << endl;
	
	l.pop_back();
	l.pop_front();
	
	//std::advance, std::next
	lit = ++(++(++(++(l.begin()))));
	l.erase(lit);
	
	l.sort();
	
	for(lit = l.begin(); lit != l.end(); lit++){
		*lit = *lit*2;
		cout << *lit << " ";
	}
	cout << endl;
	
	set<int> s;
	
	s.insert(50);
	s.insert(10);
	s.insert(10);
	s.insert(25);
	s.insert(10);
	s.insert(50);
	s.insert(40);
	s.insert(35);
	s.insert(50);
	
	for(int i : s){
		cout << i << " " << &i << endl;
	}
	
	set<int>::iterator sit;
	for(sit = s.begin(); sit != s.end(); sit++){
		//*sit = *sit*2;
		cout << *sit << " " ;
	}
	cout << endl;
	
	s.erase(50);
	cout << s.contains(50) <<endl;
	cout << *s.find(25) << endl;
	
	vector<int> v = {1, 1, 1, 3, 4, 45, 65, 56, 34, 34, 56 ,67,678, 99, 44, 55, 65, 34, 34, 1, 3, 4, 45};
	
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
	nevek.insert({"Z","Zoé"});
	nevek["Kopasz"] = "Tamás";
	nevek["Zoli"] = "Zoltán";
	
	cout << nevek["Z"] << endl;
	
	//for(auto a: nevek){
	for(std::pair<string, string> a : nevek){
		cout << a.first << "  " << a.second << endl;
	}
	
	std::map<string, string>::iterator mit;
	
	for(mit = nevek.begin(); mit != nevek.end(); mit++){
		cout << mit->first << " " << mit->second << endl;
	}
	
	nevek["Z"] = "Zalán";
	
	cout << nevek["Z"] << endl;
	
	
	









}

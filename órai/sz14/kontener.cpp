#include <iostream>
#include <list>
#include <set>
#include <vector>
#include <map>
#include <fstream>

using namespace std;

int main(){

	list<int> l;
	
	for(int i=0; i<10; i++){
		l.push_front(i*2);
		l.push_back(i);
	}
	
	//cout << l[0] << endl;
	cout << l.front() << " " << l.back() << endl;

	for(int i : l){
		cout << i << " " << &i << endl;
	}
	
	/*for(auto it = l.begin(); it!= l.end(); it++){
		cout << *it << " ";
	}
	cout << endl;*/
	
	list<int>::iterator lit;
	for( lit = l.begin(); lit!= l.end(); lit++){
		cout << *lit << " ";
	}
	cout << endl;
	
	l.pop_front();
	l.pop_back();
	
	lit = ++(++(++(++(l.begin())))); //std::advance, std::next
	l.erase(lit);
	
	for( lit = l.begin(); lit!= l.end(); lit++){
		cout << *lit << " ";
	}
	cout << endl;
	
	l.sort();
	
	for( lit = l.begin(); lit!= l.end(); lit++){
		*lit = *lit*2;
		cout << *lit << " ";
	}
	cout << endl;
	
	set<int> s;
	
	s.insert(50);
	s.insert(10);
	s.insert(20);
	s.insert(10);
	s.insert(50);
	s.insert(25);
	s.insert(50);
	s.insert(35);
	s.insert(50);
	
//	cout << s[0] << endl --hiba, nem létezik

	for(int i : s){
		cout << i << " "  << &i << endl;
	}
	
	set<int>::iterator sit;
	
	for(sit = s.begin(); sit != s.end(); sit++){
		//*sit = *sit*2;
		cout << *sit << " ";
	}
	cout << endl;
	
	s.erase(50);
	cout << s.contains(50) << endl;
	cout << *s.find(20) << endl;
	
	vector<int> v = {1, 1, 1, 6, 5, 4,44, 33, 66, 77, 33, 55, 77, 88, 6, 5, 22, 11, 44, 55, 88, 66};
	
	set<int> sv(v.begin(), v.end());
	
	v.clear();
	
	v.assign(sv.begin(), sv.end());
	
	for(int i : v){
		cout << i << " " ;
	}
	cout << endl;
	
	//map<key, value>
	map<string, string> m;
	
	m.insert({"Pista", "István"});
	m.insert({"Z", "Zoé"});
	m["Zoli"] = "Zoltán";
	
	m["Z"] = "Zalán";
	
	//for(auto a : m){
	for(std::pair<string, string> a : m){
		cout << a.first << " " << a.second << endl;
	}

	std::map<string, string>::iterator mit;
	
	for(mit = m.begin(); mit != m.end(); mit++){
		mit->second = "xyz";
		//mit->first = "x";
		cout << mit->first << " " << mit->second << endl;
	}
	
	ifstream ifile("gyumik.txt");
	string gyumi;
	map<string, int> gyumolcsok;
	
	while(ifile >> gyumi){
		//gyumolcsok[gyumi]++
		if(gyumolcsok.contains(gyumi)){
			gyumolcsok[gyumi] = gyumolcsok[gyumi]+1;
		} else {
			gyumolcsok[gyumi] = 1;
		}
	}
	
	ifile.close();
	
	for(std::pair<string, int> a : gyumolcsok){
		cout << a.first << " " << a.second << endl;
	}







}

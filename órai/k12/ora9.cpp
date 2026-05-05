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

	list<int> qlist;
	
	for(int i = 0; i<20; i++){
		qlist.push_back(i*2);
		qlist.push_front(i);
	}
	
	//cout << qlist[0] << endl;
	
	cout << qlist.front() << endl;
	cout << qlist.back() << endl;
	
	/*for(int a : qlist){
		cout << a << " " << &a << endl;
	}
	cout << endl;
	
	for(auto it = qlist.begin(); it!= qlist.end(); it++){
		cout << *it << endl;
	}*/
	
	list<int>::iterator it;
	for(it = qlist.begin(); it!= qlist.end(); it++){
		cout << *it << endl;
	}
	
	//eltávolítás
	qlist.pop_back();
	qlist.pop_front();
	
	it = ++(++(++(++qlist.begin())));
	
	qlist.erase(it);
	
	qlist.sort();
	
	for(it = qlist.begin(); it!= qlist.end(); it++){
		*it = *it*2;
		cout << *it << endl;
	}
	
	
	set<int> s;
	
	s.insert(50);
	s.insert(10);
	s.insert(20);
	s.insert(50);
	s.insert(1);
	s.insert(15);
	s.insert(20);
	s.insert(35);
	
	cout << "SET: " << endl;
	
	for(int i: s){
		cout << i << " " << &i << endl;
	}
	
	set<int>::iterator itr;
	for(itr = s.begin(); itr!= s.end(); itr++){
		cout << *itr << " " ;
	}
	cout << endl;
	
	s.erase(20);
	cout << s.contains(20) << endl;
	cout << *s.find(10) << endl;
	
	
	std::vector<int> v = {1,2,4,5,7,14,74,5,54,54,54,564,54,54,548,48,468,11,22,33,44,55};
	
	set<int> vs(v.begin(), v.end()); //vektor értékeivel feltöltöm a setet
	v.clear();
	v.assign(vs.begin(), vs.end());
	
	for(int i : v){
		cout << i << " " ;
	}
	cout << endl;
	
	//map<kulcs típusa, érték típusa>
	map<int, string> nevek;
	
	nevek.insert({0, "Ádám"});
	nevek.insert({1,"Béla"});
	nevek[5]="Éva";
	nevek[11]="Ibolya";
	
	cout << nevek[5] << endl;
	//m["alma"] = 5;
	
	//for(auto a : nevek)
	for(std::pair<int, string> a : nevek){
		cout << a.first << " " << a.second << endl;
	}
	
	nevek[5] = "Krisztina";
	
	std::map<int, string>::iterator mit;
	
	for(mit = nevek.begin(); mit != nevek.end(); mit++){
		cout << mit->first << " " << mit->second << endl;
	}
	
	
	

	







}




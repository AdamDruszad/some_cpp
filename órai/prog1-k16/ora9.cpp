#include <iostream>
#include <vector>
#include <list>
#include <set>
#include <map>

using namespace std;

int main(){

	//container library
	//adattárolás módja
	//adatok elérhetősége
	//tárterület
	
	list<int> l;
	
	for(int i = 0; i<10; i++){
		l.push_back(i*10);
		l.push_front(i);
	}
	
	//cout << l[0] << endl;
	
	cout  << l.front() <<  " " << l.back() << endl;
	
	for(int i : l){
		cout << i << " " << &i << endl;
	}
	
	/*for(auto it = l.begin(); it != l.end(); it++){
		cout << *it << " ";
	}
	cout << endl;*/
	list<int>::iterator it;
	for(it = l.begin(); it != l.end(); it++){
		cout << *it << " ";
	}
	cout << endl;
	
	l.pop_back();
	l.pop_front();
	
	it = ++(++(++(++(l.begin()))));
	
	l.erase(it);
	
	
	
	l.sort();
	
	for(it = l.begin(); it != l.end(); it++){
		*it = *it*2;
		cout << *it << " ";
	}
	cout << endl;
	
	
	set<int> s;
	
	s.insert(50);
	s.insert(15);
	s.insert(10);
	s.insert(50);
	s.insert(20);
	s.insert(20);
	s.insert(10);
	s.insert(30);
	
	cout << "SET: " << endl;
	
	for(int i : s){
		cout << i << " " ;
	}
	cout << endl;
	
	set<int>::iterator sit;
	for(sit = s.begin(); sit != s.end(); sit++){
		//*sit = *sit*2;
		cout << *sit << " " ;
	}
	cout << endl;
	
	s.erase(20);
	cout << s.contains(20) << endl;
	cout << *s.find(30) << endl;
	
	vector<int> v = {55, 11,55, 1, 2, 2, 9, 9, 3, 6, 2, 1, 33, 55, 66, 11 ,33 ,44 ,55 ,77};
	
	set<int> sv(v.begin(), v.end());

	v.clear();
	
	v.assign(sv.begin(), sv.end());
	
	for(int i : v){
		cout << i << " " ;
	}
	cout << endl;
	
	
	//map<kulcs típusa, érték típusa>
	map<string, string> nevek;
	
	nevek.insert({"sün","Zoltán"});
	nevek.insert({"répa", "Kristóf"});
	nevek["z"] = "Zoé";
	nevek["a"] = "Aladár";
	
	nevek["a"] = "Attila";
	
	cout << nevek["a"] << endl;
	
	for(std::pair<string,string> a : nevek){
		cout << a.first << " " << a.second << endl;
	}
	
	std::map<string, string>::iterator mit;
	
	for(mit = nevek.begin(); mit != nevek.end(); mit++){
		cout << mit->first << " " << mit->second << endl;
	}
	
	list<int> f = {90, 80, 70, 60, 50, 40, 30, 20, 4, 9, 1};
	
	auto fi = ------f.end();
	cout << *fi << endl;
	
	f.remove_if([fi](int n){ return (n % *fi) ==0; });
	
	/*for(auto it = f.begin() ; it != f.end(); it++){
		if(*it % *fi == 0){
			f.erase(it);
		}
	}*/
	
	for(int i : f){
		cout << i << " " ;
	}
	cout << endl;
	
	
	
	
	
	
	
	
	
	
}

#include <iostream>
#include <list>
#include <set>
#include <vector>
#include <map>
#include <fstream>

using namespace std;

int main(){

    list<int> l;

    for(int i = 0; i < 10; i++){
        l.push_front(i*2);
        l.push_back(i);
    }
    
    
    //cout << l[0] << endl;
    cout << l.front() << endl;
    cout << l.back() << endl;

    // 1.
    for(int i : l){
        cout << i << " " << &i << endl;
    }

    // 2.

    /*
        for(auto it = l.begin(); it!=l.end(); it++){
        cout << *it << " ";
        }
        cout <<endl;
    */

//=================

    list<int>::iterator lit;
    for(lit = l.begin(); lit!=l.end(); lit++){
        cout << *lit << " ";
    }
    cout <<endl;

    l.pop_front();
    l.pop_back();

    lit = ++(++(++(++(l.begin()))));// std::advance, std::next --tekkel lehet szépen lépegetni
    l.erase(lit);

    for(auto it = l.begin(); it!=l.end(); it++){
        cout << *it << " ";
    }
    cout <<endl;

    l.sort();

    for(auto it = l.begin(); it!=l.end(); it++){
        *it = *it*2;
        cout << *it << " ";
    }
    cout <<endl;

    set<int> s;
    s.insert(50);
    s.insert(10);
    s.insert(30);
    s.insert(20);
    s.insert(60);
    s.insert(40);
    s.insert(70);
    s.insert(80);
    s.insert(90);

    //cout << s[0] << endl; --- hiba, nincs ilye

    for(int i : s){
        cout << i << " " << &i << endl;
    }

    set<int>::iterator sit;
    
    for(sit = s.begin(); sit != s.end(); sit++){
        cout << *sit << " ";
    }
    cout << endl;

    s.erase(50);
    //cout << s.contains() << endl;
    cout << *s.find(20) << endl;

    vector<int> v = {1,1,2,3,6,11,4,155,12,344,16,6,11,3,25,724,22,867,432,11,55,5,5,55,4,44,2,2,22,3};

    set<int> sv(v.begin(), v.end());

    v.clear();

    v.assign(sv.begin(), sv.end());

    for(int i : v){
        cout << i << " ";
    }
    cout << endl;

    //map<key, value>
    map<string, string> m;

    m.insert({"PIsta", "István"});
    m.insert({"Z", "Zoé"});
    m["Zoli"] = "Zoltán";

    m["Z"] = "Zalán";

    for(pair<string, string> a : m){
        cout << a.first << " " << a.second << endl;
    }
    cout << endl;

    map<string, string>::iterator mit;

    for(mit = m.begin(); mit != m.end(); mit++){
        mit->second = "xyz";
        //mit->first = "x"; -- nem lehet a kulcsot átírni
        cout << mit->first << " " << mit->second << endl;
    }

    map<string, int> gyumolcsok;
    
    ifstream infile("C:\\Users\\student\\C++\\gyumikk.txt");
    
    if (!infile) {
    cerr << "Hiba: A gyumik.txt nem talalhato a program mellett!" << endl;
    }

    string gyumolcs;
    while(infile >> gyumolcs){
        gyumolcsok[gyumolcs]++;
    }

    infile.close();

    for(auto a : gyumolcsok) {
    cout << a.first << ": " << a.second << " db" << endl;
    }



}
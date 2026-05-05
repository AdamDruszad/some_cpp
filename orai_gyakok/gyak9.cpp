#include <iostream>
#include <list>

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

}
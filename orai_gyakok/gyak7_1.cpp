#include <iostream>
#include <vector>

using namespace std;


// túlterhelés ---  azonos nevű, eltérő paraméterezésű fv.-k

int test(){return 0;}

int test(int a){return 0;}

float test(double d){return 0;}

int test(int a, double d){return 0;}

//double test(int a){return 0;} --- nem lehet egyforma nevű, más visszatérés értékű fv.

int absolute(int a){
    if(a < 0){return -a;}
    return a;
}

float absolute(float a){
    if(a < 0.0f){return -a;}
    return a;
}


vector<int>& operator<<(vector<int>& u, int i){
    u.push_back(i);
    return u;
} 

vector<int> operator+(vector<int> a, vector<int> b){
    for(int i : b){
        a.push_back(i);
    }
    return a;
}

int main(){

    test();
    test(1);
    test(1.0);
    test(1, 1.2);

    cout << absolute(-1) << " " << absolute(-2.1f) << endl;


    vector<int> v = {1,2,3};

    v.push_back(4);

    //v << 5;
    // void hozzaad(vector<int> v, int a){
    //          v.pushback(a);
    //  }


    v << 5;

    for(int i : v){
        cout << i << " ";
    }
    cout << endl;

    v << 6 << 7 << 8;

    for(int i : v){
        cout << i << " ";
    }
    cout << endl;


    vector<int> va={1,2,3,4};
    vector<int> vb={5, 6,7,8};

    vector<int> o = va+vb;
}
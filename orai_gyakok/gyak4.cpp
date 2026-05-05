#include <iostream>
#include <algorithm>

using namespace std;

int main(){
    
    struct{ // anonim struktúra
        int szulEv;
        string nev;
    } szemely1, szemely2;

    szemely1.szulEv = 2006;
    szemely1.nev = "Dávid";

    szemely2 = {2008, "Viki"};

    cout << szemely1.nev << " " << szemely1.szulEv << endl;

    szemely2 = szemely1;

    szemely1.nev = "Dom";
    
    cout << szemely1.nev << " " << szemely2.nev << endl;

    struct jarmu{
        string marka;
        string tipus;
        short int evjarat;
    };

    jarmu j1 = {"Suzuki", "Swift", 2004};
    jarmu j2 = {"Kia", "Ceed", 2020};

    if(j1.evjarat > j2.evjarat){
        cout << j1.marka << " " << j1.tipus << " fiatalabb" << endl; 
    }
    else if(j1.evjarat == j2.evjarat){
        cout << "egyidősek\n";
    }
    else{
        cout << j2.marka << " " << j2.tipus << " fiatalabb\n";
    }


    // Referencia --- Pointer:

    //referencia:
    //  típus& (név)

    string st = "narancs";
    string& gyumolcs = st;
    // string& st        string & st         string &st  -----  ugyanaz

    gyumolcs = "alma";

    cout << st << " " << gyumolcs << endl;

    //ez hibás, mert az "1"-nek nincs címe
    //int& i = 1;

    //memória cím lekérdezés:
    //  &név
    cout << &st << " " << &gyumolcs << endl;

    cout << &szemely1 << " " << &szemely1.szulEv << " - " << &szemely1.nev << "            " << &szemely2 << endl;

    //pointer:
    //az értéke mindig memória cím!
    //int* b        int * b         int *b ---ugyanaz

    int a = 10;
    int* b = &a;

    cout << a << " " << &a << " ----- " << b << " " << &b << endl;

    cout << sizeof(b) << endl;

    // dereference/referencia feloldás:
    //  *b
    cout << *b << endl;

    *b = 15;

    cout << a << endl;

    int z = 1;
    int * zptr = &z;
    int ** zpptr = &zptr;
    int *** zppptr = &zpptr;

    //nem lehet
    //int ***yptr = &z;

    cout << z  << " " << *zptr << " " << **zpptr << " " << ***zppptr << endl;


    int t[5] = {1,2,3,4,5};    

    //így memóriacímet ad
    cout << t << endl;

    int* tptr = t;

    //így is
    cout << t << " - " << &t[0] << " - " << tptr << endl;

    cout << t[4] << " - " << (&t[0])[4] << " - " << tptr[4] << endl;

    //kamu iterátoros bejárás
    for(int* ptr = &t[0] ; ptr <= &t[4] ; ptr++){
        cout << *ptr << " <- " <<  ptr << endl;
    }
    cout << "\n";

    tptr = &t[4];

    while(tptr >= t){
        cout << *tptr << " <- " << tptr-- << endl;
    }
    cout << endl;

    *(t+4) = 500; // *(&t[0] + 4) = 500  <====>  t[4] = 500

    for(int i = 0; i < 5; i++){
        *(t+i) = 5-i;
        if(*(t+i) == 1){
            *(t+i) = 5;
            cout << *(t+i) << " ";
        }
        else if(*(t+i) == 5){
            *(t+i) = 1;
            cout << *(t+i) << " ";
        }
        else{
            cout << *(t+i) << " ";
        }
    }
    cout << endl;

    //std::swap()

    int tomb2[5] = {1, 3, 5, 7, 9};
    int mtomb[5];

    int * kezdo_ptr = tomb2;
    int * veg_ptr = &tomb2[4];
    int * cel_ptr = mtomb;
    

    cout << "----------\n";


    int c = 1;
    while(veg_ptr < 5){
        veg_ptr += 1;
    }


    





















}
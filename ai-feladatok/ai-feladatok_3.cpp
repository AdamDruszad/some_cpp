#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>
#include <map>
#include <algorithm>

using namespace std;

int lnko(int a, int b){
    if(b == 0) return a;
    return lnko(b, a % b);
}

int lkkt(int a, int b){
    return (a * b)/lnko(a, b);
}

vector<int> foatlo(int tomb[5][5]){
    vector<int> elemek;
    for(int i = 0; i < 5; i++){
        elemek.push_back(tomb[i][i]);
    }
    return elemek;
}

struct Termek{
    string nev;
    int ar;
    int darab;
};

ostream& operator<<(ostream& os, Termek& t){
    os << "Nev: " << t.nev << ", Ar: " << t.ar << ", Darab: " << t.darab << endl;
    return os;
}

class Alakzat{
    public:
        string szin;
        Alakzat(string szin):szin(szin){}
        Alakzat(){}
        virtual double terulet() = 0;
        virtual void info(){
            cout << "Szin: " << szin << ", Terulet: " << terulet() << endl;
        }
};

class Kor : public Alakzat {
    public:
        double sugar;
        Kor(string szin, double sugar):Alakzat(szin), sugar(sugar){}
        double terulet(){
            return sugar * sugar * 3.14;
        }
};

class Teglalap : public Alakzat {
    public:
        int szelesseg;
        int magassag;
        Teglalap(string szin, int szelesseg, int magassag):Alakzat(szin), magassag(magassag), szelesseg(szelesseg){}
        double terulet(){
            return szelesseg * magassag;
        }
};

int main(){
    cout << "--------------------\n";
    //-------------ELSO--------------
    int a = lkkt(4, 6);
    int b = lkkt(15, 25);
    cout << a << " - " << b << endl;
    cout << "--------------------\n";
    //-------------MASODIK-----------
    int tomb[5][5] = {{1,2,3,4,5}, {6,7,8,9,10}, {11,12,13,14,15}, {16,17,18,19,20}, {21,22,23,24,25}};
    vector<int> t = foatlo(tomb);
    for(int x : t){
        cout << x << " ";
    }
    cout << endl;
    cout << "--------------------\n";
    //-------------HARMADIK----------
    ifstream infile("termekek.txt");
    vector<Termek> termekek;
    string adat;
    while(getline(infile, adat)){
        Termek term;
        stringstream ss(adat);
        ss >> term.nev >> term.ar >> term.darab;
        termekek.push_back(term);
    }
    sort(termekek.begin(), termekek.end(), [](Termek& a, Termek& b){
        return a.ar < b.ar;
    });
    for(auto i : termekek){
        if((i.ar * i.darab) > 10000){
            cout << i;
        }
    }
    infile.close();
    cout << "--------------------\n";
    //-------------NEGYEDIK----------
    Alakzat* k = new Kor("zold", 2);
    Alakzat* te = new Teglalap("piros", 2, 4);
    k-> info();
    te->info();
    cout << "--------------------\n";
    //-------------OTODIK------------
    ifstream inf("szovegek.txt");
    string szo;
    map<string, int> szavak;
    int db = 0;
    double atlag = 0;
    int adb = 0;
    while(inf>>szo){
        if(szavak[szo] < 1){
            db += 1;
        }
        szavak[szo] += 1;
        adb += 1;
        atlag += szo.size();
    }
    cout << "Ennyi kulonbozo szo van: " << db << ":" << endl;
    int legnagyobb = 0;
    for(auto x : szavak){
        if(x.second > legnagyobb){
            legnagyobb = x.second;
        }
        cout << x.first << " ";
    }
    cout << endl;
    for(auto i : szavak){
        if(i.second == legnagyobb){
            cout << "A leggyakrabb szo: \n";
            cout << i.first << ", szerepelt: " << i.second << "x" << endl;
        }
    }
    cout << "Atlagos szohossz: "<< atlag/adb << endl;

    return 0;
}
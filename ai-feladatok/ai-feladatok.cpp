#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>
#include <list>

using namespace std;


int lnko(int a, int b){
    while (a != b){
        if(a > b){
            a -= b;
        }
        if(b > a){
            b -= a;
        }
    }
        return a;
}

vector<float> oszlopAtlag(int tomb[5][5]){
    vector<float> atlagok;
    for(int i = 0; i < 5; i++){
        float atlag = 0;
        for(int j = 0; j < 5; j++){
            atlag += tomb[j][i];
        }
        atlag /= 5.0;
        atlagok.push_back(atlag);
    }
    return atlagok;
}

struct Diak{
    string nev;
    string neptun;
    float atlag;
};

class Teglalap{      
    public:
        int magassag;
        int szelesseg;
        Teglalap(){}
        Teglalap(int magassag, int szelesseg): magassag(magassag), szelesseg(szelesseg){}
        int terulet() const{
            return magassag * szelesseg;
        }
};

ostream& operator<<(ostream& os, Teglalap& t){
    os << "Szelesseg: " <<  t.szelesseg << ", Magassag: " << t.magassag << ", Terulet: " << t.terulet() << endl;
    return os;
}

int main(){
    cout << "--------------------\n";
    //-------------ELSO--------------
    int legn = lnko(48, 18);
    cout << legn << endl;
    cout << "--------------------\n";
    //------------MASODIK------------
    int tomb[5][5] = {{1,2,3,4,5}, {6,7,8,9,10}, {11,12,13,14,15}, {16,17,18,19,20}, {21,22,23,24,25}};
    for(float x : oszlopAtlag(tomb)){
        cout << x << " ";
    }
    cout << endl;
    cout << "--------------------\n";
    //------------HARMADIK-----------
    ifstream infile("diakok.txt");
    vector<Diak> diakok;
    string line;
    while(getline(infile, line)){
        Diak diak;
        stringstream ss(line);
        ss >> diak.nev >> diak.neptun >> diak.atlag;
        diakok.push_back(diak);
    }
    for(auto x : diakok){
        if(x.atlag > 3.5){
            cout << "Nev: " << x.nev << " - NK:" << x.neptun << " - Atlag: " << x.atlag << endl;
        }
    }
    infile.close();
    cout << "--------------------\n";
    //------------NEGYEDIK-----------
    for(int i = 1; i < 4; i++){
        Teglalap tegla(i+2, i+4);
        cout << tegla;
    }
    cout << "--------------------\n";
    //------------OTODIK-------------
    ifstream innfile("szavak.txt");
    ofstream outfile("palindromok.txt");
    string szo;
    while(innfile >> szo){
        stringstream ss(szo);
        ss >> szo;
        string forditott(szo.rbegin(), szo.rend());
        bool palindrom = (szo == forditott);
        if(palindrom){
            outfile << "szo: IGEN\n";
        }else {
            outfile << "szo: NEM\n";
        }
    }
    innfile.close();
    outfile.close();
}
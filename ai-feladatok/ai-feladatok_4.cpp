#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>
#include <list>

using namespace std;

struct Dolgozo{
    string nev;
    string reszleg;
    int fizetes;
};

vector<Dolgozo> premium(string nev){
    ifstream infile(nev);
    vector<Dolgozo> dolgozok;
    string adat;
    while(getline(infile, adat)){
        stringstream ss(adat);
        Dolgozo d;
        ss >> d.nev >> d.reszleg >> d.fizetes;
        dolgozok.push_back(d);
    }
    infile.close();
    ofstream outfile("premium.txt");
    double atlag = 0;
    for(auto x : dolgozok){
        atlag += x.fizetes;
    }
    atlag /= dolgozok.size();
    for(auto x : dolgozok){
        if(x.fizetes > atlag){
            outfile << x.nev << ": " << "Igen\n";
        }else{
        outfile << x.nev << ": " << "Nem\n";
        }
    }
    outfile.close();
    return dolgozok;
}

int paros(vector<int> v){
    int db = 0;
    for(int x : v){
        if(x % 2 == 1){
            db += 1;
        }
    }
    return db;
}

vector<int> kivalogatas(vector<int> v){
    vector<int> uj;
    for(int x : v){
        if(x > 10){
            uj.push_back(x);
        }
    }
    return uj;
}

void szetvalogatas(vector<int> v){
    vector<int> uj;
    vector<int> uj1;
    for(int x : v){
        if(x >= 0){
            uj.push_back(x);
        }
        if(x < 0){
            uj1.push_back(x);
        }
    }
    cout <<"Pozitivak: \n";
    for(int i : uj){
        cout << i << ' ';
    }
    cout << endl;
    cout <<"Negativak: \n";
    for(int i : uj1){
        cout << i << ' ';
    }
    cout << endl;
}

class Jarmu{
    public:
        string rendszam;
        int gyartasiEv;
        Jarmu(){}
        Jarmu(string rendszam, int gyartasiEv): rendszam(rendszam), gyartasiEv(gyartasiEv){}
        virtual int kor(){ return 2025-gyartasiEv;}
        virtual string tipus() = 0;
};

class Szemelyauto : public Jarmu {
    public:
        int ferohely;
        Szemelyauto(){}
        Szemelyauto(string rendszam, int gyartasiEv, int ferohely): Jarmu(rendszam, gyartasiEv), ferohely(ferohely){}
        string tipus(){
            return "szemelyauto";
        }
};

class Tehergepkocsi : public Jarmu {
    public:
        int teherbiras;
        Tehergepkocsi(){}
        Tehergepkocsi(string rendszam, int gyartasiEv, int teherbiras): Jarmu(rendszam, gyartasiEv), teherbiras(teherbiras){}
        string tipus(){
            return "tehergepkocsi";
        }
};

int main(){
    cout << "--------------------\n";
    //-------------ELSO--------------
    string nev = "dolgozok.txt";
    premium(nev);
    cout << "Elso kesz\n";
    cout << "--------------------\n";
    //-------------MASODIK-----------
    vector<int> teszt = {-5, 12, 3, -8, 17, 4, -1, 22, 9, -14};
    int a = paros(teszt);
    cout << a << endl;
    vector<int> b = kivalogatas(teszt);
    for(int x : b){
        cout << x << " ";
    }
    cout << endl;
    szetvalogatas(teszt);
    cout << "--------------------\n";
    //-------------HARMADIK----------
    vector<Jarmu*> jarmuvek;
    Jarmu* kocsi = new Szemelyauto("123KAL", 2022, 4);
    Jarmu* teher = new Tehergepkocsi("423ESG", 2014, 3);
    Jarmu* kocsi1 = new Szemelyauto("K4J9L8", 2017, 2);
    Jarmu* teher1 = new Tehergepkocsi("G567SD", 2004, 3);
    jarmuvek.push_back(kocsi);
    jarmuvek.push_back(kocsi1);
    jarmuvek.push_back(teher1);
    jarmuvek.push_back(teher);
    for(auto x : jarmuvek){
        cout << "Rendszam: " << x->rendszam << ", Tipus: " << x->tipus() << ", Kor: " << x->kor() << endl;
    }
    cout << "--------------------\n";
    //-------------NEGYEDIK----------
    ifstream in("szamok.txt");
    vector<vector<int>> szamok;
    string szam;
    while(getline(in, szam)){
        vector<int> sor;
        stringstream ss(szam);
        for(int i; ss >> i;){
            sor.push_back(i);
        }
        szamok.push_back(sor);
    }
    bool let = false;
    for(int i = 0; i < szamok.size(); i++){
        vector<int> uj(szamok[i].begin(), szamok[i].end());
        int min = uj[0];
        for(int j = 0; j < uj.size(); j++){
            if(uj[j] < min){
                min = uj[j];
            }
            if(uj[j] > 37){
                let = true;
            }
        }
        cout << "Minimum: " << min << endl;
    }
    if(let){
        cout << "Van ilyen\n";
    }else{
        cout << "Nincs ilyen\n";
    }
    cout << "--------------------\n";
    //-------------OTODIK------------
    int n;
    cout << "Hany szamot fogsz megadni? ";
    cin >> n;
    vector<int> v;
    for(int i = 0; i < n; i++){
        int sz;
        cout << "Add meg a számot: ";
        cin >> sz;
        v.push_back(sz);
    }
    for(int i = 0; i < v.size()-1; i++){
        if(v[i] > v[i+1]){
            int csere = v[i+1];
            v[i+1] = v[i];
            v[i] = csere;
        }
    }
    cout << "Melyik szamot keressuk meg? ";
    int k;
    cin >> k;
    int i = v.size()/2;
    while(true){
        if(k == v[i]){
            cout << "Meg van ezen az indexen: " << v[i]-1 << endl;
            break;
        } else if(k < v[i]){
            i /= 2;
        }else{
            i += i/2;
        }
    }
}
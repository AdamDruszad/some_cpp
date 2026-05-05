#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <fstream>
#include <sstream>
#include <map>

using namespace std;

int lnko(int a, int b){
    while(a != b){
        if(a > b) a -= b;
        if(a < b) b -= a;
    }
    return a;
}

int lkkt(int a, int b){
    return (a*b)/lnko(a, b);
}

vector<int> kulonbseg(int t[3][3]){
    vector<int> mm;
    for(int i = 0; i < 3; i++){
        vector<int> sor;
        for(int j = 0; j < 3; j++){
            sor.push_back(t[i][j]);
        }
        sort(sor.begin(), sor.end());

        int kul = sor[2]-sor[0];
        mm.push_back(kul);
    }
    return mm;
}

void csere(int& a, int& b, int& c){
    int* min_ptr = &a;
    if(b < *min_ptr) min_ptr = &b;
    if(c < *min_ptr) min_ptr = &c;

    int* max_ptr = &a;
    if(b > *max_ptr) max_ptr = &b;
    if(c > *max_ptr) max_ptr = &c;

    *min_ptr = 0;
    *max_ptr = 0;

    int temp = a;
    a = c;
    c = temp;

    int temp1 = b;
    b = a;
    a = temp1;
}

struct Banan{
    double suly;
    string minoseg;
    bool bio;
};

ostream& operator<<(ostream& os, Banan t){
    os << "Suly: "<< t.suly << ", Minoseg: " << t.minoseg << ", Bio-e: " << t.bio;
    return os;
}

void feladat4(){
    Banan bananok[5] = {
        {120.5, "A", true},
        {105.0, "B", false},
        {130.2, "A", true},
        {95.5, "B", false},
        {110.0, "A", true}
    };

    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 4; j++){
            if(bananok[j].suly > bananok[j+1].suly){
                Banan temp = bananok[j];
                bananok[j] = bananok[j+1];
                bananok[j+1] = temp;
            }
        }
    }

    for(int i = 0; i < 5; i++){
        cout << bananok[i] << endl;
    }
    cout << endl;
}

void feladat5(){
    ifstream infile("sorok.txt");
    vector<string> sok;
    string sor;
    while(getline(infile, sor)){
        sok.push_back(sor);
    }
    map<char, int> betuk;
    int nagybetuk = 0;
    for(string x : sok){
        for(char y : x){
            if(isalpha(y)){
                betuk[y] += 1;
            }
            if(isupper(y)){
                nagybetuk += 1;
            }
        }
    }
    vector<pair<char, int>> rendezett(betuk.begin(), betuk.end());
    sort(rendezett.begin(), rendezett.end(), [](auto& a, auto& b){
        return a. second < b.second;
    });
    cout << "Legritkabban elofordulo betu: "<< rendezett[0].first << ", Szamossaga: " << rendezett[0].second << endl;
    cout << "Nagybetuk szama: " << nagybetuk << endl;
}

int main(){
    //------------------------------------------
    //---------ELSO------------
    //------------------------------------------
    cout << "Elso feladat: \n";
    int k = lkkt(6, 18);
    cout << "LKKT(6, 18): " << k << endl << endl;
    //------------------------------------------
    //---------MASODIK------------
    //------------------------------------------
    cout << "Masodik feladat: \n";
    int teszt[3][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    vector<int> test = kulonbseg(teszt);
    cout << "Sorok kulonbsege: " << test[0] << ", " << test[1] << ", " <<test[2] << endl << endl;
    //------------------------------------------
    //---------HARMADIK------------
    //------------------------------------------
    cout << "Harmadik feladat: \n";
    int a = 10, b = 5, c = 20;
    cout << "3. feladat elotte: a=" << a << ", b=" << b << ", c=" << c << "\n";
    csere(a, b, c);
    cout << "3. feladat utana:  a=" << a << ", b=" << b << ", c=" << c << "\n\n";
    //------------------------------------------
    //---------NEGYEDIK------------
    //------------------------------------------
    cout << "Negyedik feladat: \n";
    feladat4();
    //------------------------------------------
    //---------OTODIK------------
    //------------------------------------------
    cout << "Otodik feladat: \n";
    feladat5();
}

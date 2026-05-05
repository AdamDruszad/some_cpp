#include <iostream>
#include <vector>
#include <list>
#include <cmath>
#include <algorithm>
#include <string>
#include <fstream>
#include <sstream>
#include <map>

using namespace std;

int lnko(int a, int b){
    while(a != b){
        if(a > b){
            a -= b;
        }else{
            b -= a;
        }
    }
    return a;
}

int lkkt(int a, int b){
    return (a*b)/lnko(a, b);
}

double median(vector<int> v){
    sort(v.begin(), v.end());
    int n = v.size();
    if(n % 2 == 0){
        return (v[n/2 - 1] + v[n/2]) / 2.0;
    }else{
        return v[n/2];
    }
}

struct Csapat{
    string nev;
    int gyozelmek;
    int veresegek;
    int dontetlenek;
};

ostream& operator<<(ostream& os, Csapat& cs){
    os << "Csapatnev: " << cs.nev << ", Gyozelmek: " << cs.gyozelmek << ", Veresegek: " << cs.veresegek << ", Dontetlenek: " << cs.dontetlenek << " == Osszpont: " << cs.gyozelmek*3 + cs.dontetlenek << endl;
    return os;
}

int main(){
    cout << "--------------------\n";
    //-------------ELSO--------------
    int a = lkkt(12, 18);
    cout << a << endl;
    cout << "--------------------\n";
    //-------------MASODIK-----------
    vector<int> v = {3, 1, 4, 1, 5, 9, 2, 6};
    double b = median(v);
    cout << b << endl;
    cout << "--------------------\n";
    //-------------HARMADIK----------
    ifstream infile("csapatok.txt");
    vector<Csapat> csapatok;
    string csapat;
    while(getline(infile, csapat)){
        Csapat cs;
        stringstream ss(csapat);
        ss >> cs.nev >> cs.gyozelmek >> cs.veresegek >> cs.dontetlenek;
        csapatok.push_back(cs);
    }
    for(auto x : csapatok){
        if((x.gyozelmek*3 + x.dontetlenek)>10){
            cout << x;
        }
    }
    infile.close();
    cout << "--------------------\n";
    //-------------NEGYEDIK----------
    ifstream infile2("mondat.txt");
    map<string, int> gyumik;
    string gyumi;
    while(infile2 >> gyumi){
        gyumik[gyumi] += 1;
    }
    vector<pair<string, int>> gyumik_v(gyumik.begin(), gyumik.end());
    sort(gyumik_v.begin(), gyumik_v.end(), [](auto& a, auto& b){
        return a. second > b.second;
    });
    for(auto x : gyumik_v){
        cout << x.first << " - " << x.second << endl;
    }

}
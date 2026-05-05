#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <array>
#include <algorithm>
#include <sstream>

int ketSzamKoztFibo(int &a, int b);
std::array<double, 4> egydim(int t[4][4]);
void karakter(char &a, char t[10], char b);
void szavak();

class Doboz{
    public:
    Doboz(){}
    int szelesseg;
    int magassag;
    int melyseg;
    Doboz(int szelesseg, int magassag, int melyseg): szelesseg(szelesseg), magassag(magassag), melyseg(melyseg){}
};

int main(){
    /*
    int a = 1;
    ketSzamKoztFibo(a, 10);
    std::cout << std::endl;
    */

    int temp[4][4] = {{1,2,3,4}, {5,6,7,8}, {9,10,11,12}, {13,14,15,16}};

    for(double x : egydim(temp)){
        std::cout << x << " ";
    }
    std::cout << std::endl;

    szavak();

    std::cout << std::endl;

    Doboz dt[5] = {{1,1,1}, {2,2,2}, {3,3,3}, {4,4,4}, {5,5,5}};

    int magassag = 0;
    for(int i = 0; i < 5; i++){
        magassag += dt[i].magassag;
    }

    std::cout << "A magassaga, ha egymasra pakoljuk oket: "<< magassag << "."<< std::endl;

    std::ifstream infile("randomok.txt");
    std::ofstream outfile("kisebb1.txt");

    std::vector<std::vector<int>> adatok;
    std::string sor;
    while(getline(infile, sor)){
        std::stringstream ss(sor);
        std::vector<int> egysor;
        int szam;

        while(ss >> szam){
            egysor.push_back(szam);
        }
        adatok.push_back(egysor);
    }

    for(int i = 0; i < adatok.size(); i++){
        int osszeg = 0;

        for(int j = 0; j < adatok[i].size(); j++){
            osszeg += adatok[i][j];
        }
    
        double atlag = (double) osszeg / adatok[i].size();
        
        if(atlag < 37){
            outfile << "Igen" << std::endl;
        } else {
            outfile << "Nem" << std::endl;
        }
    }
    infile.close();
    outfile.close();
    

}

int ketSzamKoztFibo(int a, int b){
    int legnagyobbFibo = -1;
    int elozo = 0;
    int jelenlegi = 1;

    while(jelenlegi <= b){
        if(jelenlegi >= a){
            legnagyobbFibo = jelenlegi;
        }

        int kov = elozo + jelenlegi;
        elozo = jelenlegi;
        jelenlegi = kov;
    }

    return legnagyobbFibo;
}
/*

    
int* egydim(int t[4][4]){
    int* ujtomb = new int[4];
    for(int i = 0; i < 4; i++){
        int atlag = 0;
        for(int j = 0; j < 4; j++){
            atlag += t[i][j];
        }
        atlag /= 4;
        ujtomb[i] = atlag;
    }
}

*/

std::array<double, 4> egydim(int t[4][4]){
    std::array<double, 4> ujtomb;
    for(int i = 0; i < 4; i++){
        int atlag = 0;
        for(int j = 0; j < 4; j++){
            atlag += t[i][j];
        }
        ujtomb[i] = (double)atlag/4.0;
    }
    return ujtomb;
}

void karakter(char &a, char t[10], char b){
    a = t[b];
}

void szavak(){
    int n;
    std::cout << "Hany szo lesz? ";
    std::cin >> n;
    std::cout << "Ird ide a szot: ";
    std::string szavak[n];

    for(int i = 0; i < n; i++){
        std::cin >> szavak[i];
    }

    std::string rovid = szavak[0];
    std::string hosszu = szavak[0];

    for(int i = 0; i < n; i++){
        if(szavak[i].length() > hosszu.length()){
            hosszu = szavak[i];
        }
        if(szavak[i].length() < rovid.length()){
            rovid = szavak[i];
        }
    }
    std::cout << "Rövid: " << rovid << " hosszú: " << hosszu << std::endl;
}

//fibonacci, palindrom, rekurziv, primszam, lkkt, lnko stb
// szambeolvasas eltarolva, szöveges beolvasás(szavak/sorok átlagos hossza, hany szo van benne, stb kreativ dolgok)
//lehetnek szokozok azokat kiszedni és még sok más
//structuraba eltarolas ilyen sorokbol:   réka 10 20 20
//                                        tamás 32 12 10
//esetleg ezeknél adatok alalpján megfelel e az egyik adat alapjan valaminek, 
// rakjuk sorba azokat



//programozasi tetelek,     szit.hu
//lehet mindengéle átlag, medián, oszlopok, sorok, kerersztbe stb
//esetleges beolvasott szavak hossza, majd azokbol melyik ami hosszabb, rovidebb annal, és még egy csomó mód, amit ki lehet talalni,  
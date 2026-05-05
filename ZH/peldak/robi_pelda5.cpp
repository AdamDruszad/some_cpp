#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <map>
#include <cctype>

using namespace std;

// ---------------------------------------------------------
// 1. Feladat: Két szám legkisebb közös többszöröse (LKKT)
// ---------------------------------------------------------
// Segédfüggvény a legnagyobb közös osztóhoz (LNKO)
int lnko(int a, int b) {
    while (b != 0) {
        int t = b;
        b = a % b;
        a = t;
    }
    return a;
}

int lkkt(int a, int b) {
    if (a == 0 || b == 0) return 0;
    // a * b / lnko(a, b) - a túlcsordulás elkerülése miatt az osztást érdemes előre venni
    return (a / lnko(a, b)) * b;
}

// ---------------------------------------------------------
// 2. Feladat: 3x3-as tömb soronkénti maximum-minimum különbsége
// ---------------------------------------------------------
int* sorKulonbseg(int matrix[3][3]) {
    int* kulonbsegek = new int[3];

    for (int i = 0; i < 3; i++) {
        int maxVal = matrix[i][0];
        int minVal = matrix[i][0];

        for (int j = 1; j < 3; j++) {
            if (matrix[i][j] > maxVal) maxVal = matrix[i][j];
            if (matrix[i][j] < minVal) minVal = matrix[i][j];
        }

        kulonbsegek[i] = maxVal - minVal;
    }

    return kulonbsegek;
}

// ---------------------------------------------------------
// 3. Feladat: 3 integer manipulációja (referenciákkal)
// ---------------------------------------------------------
void feladat3_manipulal(int& a, int& b, int& c) {
    // Referenciákat (pointereket) használunk, hogy pontosan
    // egy legkisebb és egy legnagyobb értéket írjunk felül 0-ra,
    // akkor is, ha vannak egyenlő értékek.
    int* min_ptr = &a;
    if (b < *min_ptr) min_ptr = &b;
    if (c < *min_ptr) min_ptr = &c;

    int* max_ptr = &a;
    if (b > *max_ptr) max_ptr = &b;
    if (c > *max_ptr) max_ptr = &c;

    *min_ptr = 0;
    *max_ptr = 0;

    // (a) és (c) felcserélése
    int temp = a;
    a = c;
    c = temp;

    // (b) és (a) felcserélése
    temp = b;
    b = a;
    a = temp;
}

// ---------------------------------------------------------
// 4. Feladat: Banán struktúra és rendezés
// ---------------------------------------------------------
struct Banan {
    double sulya;
    string minosege;
    bool bio_e;
};

void feladat4() {
    Banan bananok[5] = {
        {120.5, "A", true},
        {105.0, "B", false},
        {130.2, "A", true},
        {95.5, "B", false},
        {110.0, "A", true}
    };

    // Buborékrendezés súly szerint növekvő sorrendbe
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4 - i; j++) {
            if (bananok[j].sulya > bananok[j + 1].sulya) {
                Banan temp = bananok[j];
                bananok[j] = bananok[j + 1];
                bananok[j + 1] = temp;
            }
        }
    }

    // Kiírás ellenőrzéshez
    for (int i = 0; i < 5; i++) {
        cout << "Suly: " << bananok[i].sulya
             << "g, Minoseg: " << bananok[i].minosege
             << ", Bio: " << (bananok[i].bio_e ? "Igen" : "Nem") << "\n";
    }
}

// ---------------------------------------------------------
// 5. Feladat: Fájl beolvasása, legritkább betű és nagybetűk
// ---------------------------------------------------------
void feladat5() {
    ifstream be("sorok.txt");
    ofstream ki("gyakori.txt"); // A kiírandó fájl neve maradt a feladat szerint

    if (!be.is_open()) {
        cout << "Nem sikerult megnyitni a sorok.txt fajlt!\n";
        return;
    }

    map<char, int> betuGyakorisag;
    int nagybetuDb = 0;
    char c;

    // Karakterenként olvassuk a fájlt
    while (be.get(c)) {
        // Csak az alfabetikus karakterekkel (betűkkel) foglalkozunk
        if (isalpha(c)) {
            if (isupper(c)) {
                nagybetuDb++;
            }
            // Kisbetűssé alakítjuk a statisztikához
            char kisbetu = tolower((unsigned char)c);
            betuGyakorisag[kisbetu]++;
        }
    }

    // Megkeressük a legkisebb előfordulású betűt
    if (!betuGyakorisag.empty()) {
        char legritkabbBetu = betuGyakorisag.begin()->first;
        int minElofordulas = betuGyakorisag.begin()->second;

        for (auto const& par : betuGyakorisag) {
            if (par.second < minElofordulas) {
                minElofordulas = par.second;
                legritkabbBetu = par.first;
            }
        }

        ki << "Legritkabban elofordulo betu: '" << legritkabbBetu << "' (" << minElofordulas << " db)\n";
        ki << "A nagy betuk szama: " << nagybetuDb << "\n";
    }

    be.close();
    ki.close();
    cout << "A gyakori.txt fajl elkeszult.\n";
}

// ---------------------------------------------------------
// Főprogram (Main) - A teszteléshez
// ---------------------------------------------------------
int main() {
    // 1. Feladat tesztje
    int szam1 = 12, szam2 = 15;
    cout << "1. feladat (12 es 15 LKKT-je): " << lkkt(szam1, szam2) << "\n\n";

    // 2. Feladat tesztje
    int matrix[3][3] = {
        {10, 2, 8},   // max(10)-min(2) = 8
        {5, 20, 15},  // max(20)-min(5) = 15
        {1, 1, 1}     // max(1)-min(1) = 0
    };
    int* diffs = sorKulonbseg(matrix);
    cout << "2. feladat (Sorok kulonbsege): "
         << diffs[0] << ", " << diffs[1] << ", " << diffs[2] << "\n\n";
    delete[] diffs;

    // 3. Feladat tesztje
    int a = 10, b = 5, c = 20;
    cout << "3. feladat elotte: a=" << a << ", b=" << b << ", c=" << c << "\n";
    feladat3_manipulal(a, b, c);
    cout << "3. feladat utana:  a=" << a << ", b=" << b << ", c=" << c << "\n\n";

    // 4. Feladat tesztje
    cout << "4. feladat:\n";
    feladat4();
    cout << "\n";

    // 5. Feladat tesztje
    // cout << "5. feladat...\n";
    // feladat5();

    return 0;
}
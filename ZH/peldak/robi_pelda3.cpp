#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>
#include <algorithm>

using namespace std;

// ---------------------------------------------------------
// 1. Feladat: Két szám közötti legnagyobb Fibonacci szám
// ---------------------------------------------------------
int maxFibonacci(int a, int b) {
    int start = min(a, b);
    int end = max(a, b);

    int f1 = 0, f2 = 1, f3 = 1;
    int max_fib = -1; // Olyan kezdőérték, ami jelzi, ha esetleg nincs a tartományban

    // Ha a 0 benne van a tartományban, az már egy érvényes Fibonacci szám
    if (start <= 0 && end >= 0) {
        max_fib = 0;
    }

    while (f3 <= end) {
        if (f3 >= start) {
            max_fib = f3; // Folyamatosan felülírjuk az eddigi legnagyobbal
        }
        f1 = f2;
        f2 = f3;
        f3 = f1 + f2;
    }

    return max_fib;
}

// ---------------------------------------------------------
// 2. Feladat: 10x10-es tömb soronkénti átlagai
// ---------------------------------------------------------
double* sorAtlag(int matrix[10][10]) {
    // Dinamikusan foglalunk egy 10 méretű double tömböt az átlagoknak
    double* atlagok = new double[10];

    for (int i = 0; i < 10; i++) {
        double sum = 0;
        for (int j = 0; j < 10; j++) {
            sum += matrix[i][j];
        }
        atlagok[i] = sum / 10.0;
    }

    return atlagok;
}

// ---------------------------------------------------------
// 3. Feladat: Stringek bekérése és a legkisebb/legnagyobb kiválasztása
// ---------------------------------------------------------
void feladat3() {
    int n;
    cout << "Kerek egy egesz szamot (n): ";
    cin >> n;

    if (n <= 0) {
        cout << "Nincs bekerendo string.\n";
        return;
    }

    string s, legrovidebb, leghosszabb;
    cout << "Kerek " << n << " db szokoz nelkuli stringet:\n";

    // Első beolvasás a kezdőértékek beállításához
    cin >> s;
    legrovidebb = s;
    leghosszabb = s;

    // A maradék n-1 darab beolvasása
    for (int i = 1; i < n; i++) {
        cin >> s;
        if (s.length() < legrovidebb.length()) {
            legrovidebb = s;
        }
        if (s.length() > leghosszabb.length()) {
            leghosszabb = s;
        }
    }

    cout << "A legrovidebb string: " << legrovidebb << "\n";
    cout << "A leghosszabb string: " << leghosszabb << "\n";
}

// ---------------------------------------------------------
// 4. Feladat: Doboz struktúra és torony magassága
// ---------------------------------------------------------
struct Doboz {
    double szelesseg;
    double magassag;
    double melyseg;
};

void feladat4() {
    // 5 méretű tömb feltöltése (tetszőleges adatokkal)
    Doboz dobozok[5] = {
        {10.0, 5.5, 10.0},
        {8.0, 3.2, 8.0},
        {15.0, 10.0, 15.0},
        {5.0, 2.5, 5.0},
        {12.0, 7.3, 12.0}
    };

    double osszMagassag = 0;
    for (int i = 0; i < 5; i++) {
        osszMagassag += dobozok[i].magassag;
    }

    cout << "A torony magassaga: " << osszMagassag << "\n";
}

// ---------------------------------------------------------
// 5. Feladat: Fájl beolvasása adatszerkezetbe, átlag vizsgálat
// ---------------------------------------------------------
void feladat5() {
    ifstream be("randomok.txt");
    ofstream ki("kisebb.txt");

    if (!be.is_open()) {
        cout << "Nem sikerult megnyitni a randomok.txt fajlt!\n";
        return;
    }

    // A feladat kéri, hogy olvassuk be "tetszőleges adatszerkezetbe"
    // Ez a vektorok vektora egy jó választás kétdimenziós adatokhoz
    vector<vector<int>> adatok;
    string sor;

    // 1. Fázis: Beolvasás az adatszerkezetbe
    while (getline(be, sor)) {
        if (sor.empty()) continue;

        stringstream ss(sor);
        vector<int> aktualisSor;
        int szam;

        while (ss >> szam) {
            aktualisSor.push_back(szam);
        }
        adatok.push_back(aktualisSor);
    }

    // 2. Fázis: Adatszerkezet feldolgozása és fájlba írás
    for (size_t i = 0; i < adatok.size(); i++) {
        double sum = 0;
        for (size_t j = 0; j < adatok[i].size(); j++) {
            sum += adatok[i][j];
        }

        double atlag = sum / adatok[i].size();

        if (atlag < 37.0) {
            ki << "Igen\n";
        } else {
            ki << "Nem\n";
        }
    }

    be.close();
    ki.close();
    cout << "A kisebb.txt fajl elkeszult.\n";
}

// ---------------------------------------------------------
// Főprogram (Main) - A teszteléshez
// ---------------------------------------------------------
int main() {
    // 1. Feladat tesztje
    cout << "1. feladat (10 es 50 kozotti max Fibonacci): " << maxFibonacci(10, 50) << "\n\n";

    // 2. Feladat tesztje
    int matrix[10][10] = {0};
    // Adjunk meg egy-két értéket, hogy ne csak nulla legyen
    matrix[0][0] = 50; matrix[0][1] = 100; // 0. sor átlaga 15 lesz
    matrix[1][5] = 20;                     // 1. sor átlaga 2 lesz

    double* atlagok = sorAtlag(matrix);
    cout << "2. feladat (0. es 1. sor atlaga): " << atlagok[0] << ", " << atlagok[1] << "\n\n";
    delete[] atlagok; // Memóriafelszabadítás

    // 3. Feladat tesztje (Interaktív, a feladat szövege alapján)
    cout << "3. feladat:\n";
    feladat3();
    cout << "\n";

    // 4. Feladat tesztje
    cout << "4. feladat:\n";
    feladat4();
    cout << "\n";

    // 5. Feladat tesztje (Létre kell hozni mellé a randomok.txt-t a teszteléshez)
    // cout << "5. feladat...\n";
    // feladat5();

    return 0;
}
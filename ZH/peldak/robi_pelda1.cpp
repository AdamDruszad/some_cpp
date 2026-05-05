#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>
#include <algorithm>

using namespace std;

// ---------------------------------------------------------
// 1. Feladat: Prímszámok száma két integer között
// ---------------------------------------------------------
bool isPrime(int n) {
    if (n <= 1) return false;
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) return false;
    }
    return true;
}

int primDb(int a, int b) {
    int start = min(a, b);
    int end = max(a, b);
    int count = 0;

    // A "két szám közötti" általában nyílt intervallumot (start+1 -től end-1 -ig)
    // vagy zárt intervallumot jelent. Itt a zárt [start, end] intervallumot vizsgáljuk.
    for (int i = start; i <= end; i++) {
        if (isPrime(i)) {
            count++;
        }
    }
    return count;
}

// ---------------------------------------------------------
// 2. Feladat: 10x10-es tömb soronkénti maximumai
// ---------------------------------------------------------
// C++-ban a legegyszerűbb dinamikusan foglalt tömbbel visszatérni,
// hogy az a függvény lefutása után is megmaradjon a memóriában.
int* sorMax(int matrix[10][10]) {
    int* maxok = new int[10];
    for (int i = 0; i < 10; i++) {
        int maxVal = matrix[i][0];
        for (int j = 1; j < 10; j++) {
            if (matrix[i][j] > maxVal) {
                maxVal = matrix[i][j];
            }
        }
        maxok[i] = maxVal;
    }
    return maxok;
}

// ---------------------------------------------------------
// 3. Feladat: Érték másolása tömbből integerbe
// ---------------------------------------------------------
// Az 'a' paramétert referenciaként (int&) kell átadni,
// másképp a belemásolt érték elveszne a függvény végén.
void masol(int& a, int t[10], int b) {
    if (b >= 0 && b < 10) { // Index túlcsordulás elleni védelem
        a = t[b];
    }
}

// ---------------------------------------------------------
// 4. Feladat: Alma struktúra és tömbök kezelése
// ---------------------------------------------------------
struct Alma {
    string fajta;
    string szin;
};

void feladat4() {
    // 5 méretű vegyes tömb
    Alma almak[5] = {
        {"Gala", "piros"},
        {"Granny Smith", "zöld"},
        {"Idared", "piros"},
        {"Mutsu", "zöld"},
        {"Jonagold", "piros"}
    };

    Alma pirosak[5];
    Alma zoldek[5];
    int pDb = 0, zDb = 0;

    // Szétválogatás
    for (int i = 0; i < 5; i++) {
        if (almak[i].szin == "piros") {
            pirosak[pDb] = almak[i];
            pDb++;
        } else if (almak[i].szin == "zöld") {
            zoldek[zDb] = almak[i];
            zDb++;
        }
    }

    // Kiíratás
    cout << "Piros almak: ";
    for (int i = 0; i < pDb; i++) cout << pirosak[i].fajta << (i == pDb-1 ? "" : ", ");

    cout << "\nZold almak: ";
    for (int i = 0; i < zDb; i++) cout << zoldek[i].fajta << (i == zDb-1 ? "" : ", ");
    cout << "\n";
}

// ---------------------------------------------------------
// 5. Feladat: Fájl beolvasása, soronkénti rendezés és kiírás
// ---------------------------------------------------------
void feladat5() {
    ifstream be("randomok.txt");
    ofstream ki("rendezett.txt");

    if (!be.is_open()) {
        cout << "Nem sikerult megnyitni a randomok.txt fajlt!" << "\n";
        return;
    }

    string sor;
    // Soronkénti beolvasás
    while (getline(be, sor)) {
        if (sor.empty()) {
            ki << "\n";
            continue;
        }

        stringstream ss(sor);
        vector<int> szamok;
        int szam;

        // Az aktuális sor számainak betöltése a vektorba (tetszőleges adatszerkezet)
        while (ss >> szam) {
            szamok.push_back(szam);
        }

        // Rendezzük az adott sort növekvő sorrendbe
        sort(szamok.begin(), szamok.end());

        // Kiírás a rendezett.txt-be
        for (size_t i = 0; i < szamok.size(); i++) {
            ki << szamok[i] << (i == szamok.size() - 1 ? "" : " ");
        }
        ki << "\n";
    }

    be.close();
    ki.close();
    cout << "A rendezett.txt fajl elkeszult.\n";
}

// ---------------------------------------------------------
// Főprogram (Main) - A megoldások tesztelésére
// ---------------------------------------------------------
int main() {
    // 1. Feladat hívása
    cout << "1. feladat (10 es 20 kozotti primek): " << primDb(10, 20) << "\n\n";

    // 2. Feladat hívása
    int matrix[10][10] = {0};
    matrix[0][5] = 42;
    matrix[1][2] = 17;
    int* maxok = sorMax(matrix);
    cout << "2. feladat (0. es 1. sor max): " << maxok[0] << ", " << maxok[1] << "\n\n";
    delete[] maxok; // Memóriaszivárgás elkerülése

    // 3. Feladat hívása
    int t[10] = {0, 10, 20, 30, 40, 50, 60, 70, 80, 90};
    int a = 0;
    masol(a, t, 5);
    cout << "3. feladat (a erteke az 5. index utan): " << a << "\n\n";

    // 4. Feladat hívása
    cout << "4. feladat:\n";
    feladat4();
    cout << "\n";

    // 5. Feladat hívása (Létre kell hozni mellé a randomok.txt-t a teszteléshez)
    // cout << "5. feladat (Fajlmuveletek)...\n";
    // feladat5();

    return 0;
}
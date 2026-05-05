#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>

using namespace std;

// ---------------------------------------------------------
// 1. Feladat: % operátor túlterhelése (string % char)
// ---------------------------------------------------------
int operator%(const string& str, char c) {
    int darab = 0;
    for (char ch : str) {
        if (ch == c) {
            darab++;
        }
    }
    return darab;
}

// ---------------------------------------------------------
// 2. Feladat: 3x3-as tömb oszlopainak maximum-minimum különbsége
// ---------------------------------------------------------
int* oszlopKulonbseg(int matrix[3][3]) {
    int* kulonbsegek = new int[3];
    
    for (int j = 0; j < 3; j++) {
        int maxVal = matrix[0][j];
        int minVal = matrix[0][j];
        
        for (int i = 1; i < 3; i++) {
            if (matrix[i][j] > maxVal) maxVal = matrix[i][j];
            if (matrix[i][j] < minVal) minVal = matrix[i][j];
        }
        
        kulonbsegek[j] = maxVal - minVal;
    }
    
    return kulonbsegek;
}

// ---------------------------------------------------------
// 3. Feladat: Műveletvégző függvény (referencia paraméterrel)
// ---------------------------------------------------------
// Az 'a' paramétert referenciaként (int&) kell átadni, hogy 
// a függvény módosítani tudja az eredeti változó értékét.
void muv(int& a, string muvelet, int b) {
    if (muvelet == "növel") {
        a += b;
    } else if (muvelet == "csökkent") {
        a -= b;
    } else if (muvelet == "szoroz") {
        a *= b;
    } else if (muvelet == "oszt") {
        if (b != 0) { // Nullával való osztás elkerülése
            a /= b;
        } else {
            cout << "Hiba: nullaval valo osztas!\n";
        }
    }
}

// ---------------------------------------------------------
// 4. Feladat: Kutya struktúra és a legfiatalabb kutya
// ---------------------------------------------------------
struct Kutya {
    string fajtasa;
    string merete;
    int szuletesi_eve;
};

void feladat4() {
    // Létrehozunk egy tetszőleges tömböt kutyákkal
    Kutya kutyak[4] = {
        {"Németjuhász", "Nagy", 2018},
        {"Puli", "Közepes", 2015},
        {"Tacskó", "Kicsi", 2022},
        {"Golden Retriever", "Nagy", 2020}
    };

    // Kezdetben feltételezzük, hogy az első a legfiatalabb 
    // (a legfiatalabbnak van a legnagyobb születési éve)
    Kutya legfiatalabb = kutyak[0];
    
    for (int i = 1; i < 4; i++) {
        if (kutyak[i].szuletesi_eve > legfiatalabb.szuletesi_eve) {
            legfiatalabb = kutyak[i];
        }
    }

    cout << "A legfiatalabb kutya adatai:\n";
    cout << "Fajta: " << legfiatalabb.fajtasa << "\n";
    cout << "Meret: " << legfiatalabb.merete << "\n";
    cout << "Szuletesi ev: " << legfiatalabb.szuletesi_eve << "\n";
}

// ---------------------------------------------------------
// 5. Feladat: Mátrix átlóinak vizsgálata fájlból
// ---------------------------------------------------------
void feladat5() {
    ifstream be("randomok.txt");
    ofstream ki("nagyobb.txt");

    if (!be.is_open()) {
        cout << "Nem sikerult megnyitni a randomok.txt fajlt!\n";
        return;
    }

    // A fájl tartalma alapján egy 5x5-ös mátrixról van szó
    int matrix[5][5];
    string sor;
    int i = 0;

    // Fájl beolvasása a 2D tömbbe
    while (getline(be, sor) && i < 5) {
        if (sor.empty()) continue;
        stringstream ss(sor);
        for (int j = 0; j < 5; j++) {
            ss >> matrix[i][j];
        }
        i++;
    }

    // Mivel a szorzatok nagyon nagyok lehetnek, érdemes long long-ot használni
    long long szorzat1 = 1; // Főátló (bal fentől jobb le)
    long long szorzat2 = 1; // Mellékátló (jobb fentől bal le)

    vector<int> atlo1_elemek;
    vector<int> atlo2_elemek;

    for (int k = 0; k < 5; k++) {
        // Főátló elemei: sor index == oszlop index
        atlo1_elemek.push_back(matrix[k][k]);
        szorzat1 *= matrix[k][k];

        // Mellékátló elemei: sor index + oszlop index == n - 1 (ahol n a méret, most 5)
        atlo2_elemek.push_back(matrix[k][4 - k]);
        szorzat2 *= matrix[k][4 - k];
    }

    // Eldöntjük, melyik a nagyobb, és kiírjuk a megfelelő elemeket
    if (szorzat1 > szorzat2) {
        for (int elem : atlo1_elemek) {
            ki << elem << " ";
        }
    } else if (szorzat2 > szorzat1) {
        for (int elem : atlo2_elemek) {
            ki << elem << " ";
        }
    } else {
        ki << "A ket atlo szorzata egyenlo.";
    }

    be.close();
    ki.close();
    cout << "A nagyobb.txt fajl elkeszult.\n";
}

// ---------------------------------------------------------
// Főprogram (Main) - A teszteléshez
// ---------------------------------------------------------
int main() {
    // 1. Feladat tesztje
    string szoveg = "programozas";
    char keresett = 'o';
    // Az operátor hívása így történik: string % char
    int db = szoveg % keresett; 
    cout << "1. feladat ('" << keresett << "' betuk szama a '" << szoveg << "'-ban): " << db << "\n\n";

    // 2. Feladat tesztje
    int matrix[3][3] = {
        {1, 9, 4},
        {5, 2, 8},
        {3, 7, 6}
    };
    /* Oszlopok min-max különbsége:
       0. oszlop: max(5)-min(1) = 4
       1. oszlop: max(9)-min(2) = 7
       2. oszlop: max(8)-min(4) = 4 */
    int* diffs = oszlopKulonbseg(matrix);
    cout << "2. feladat (Oszlopok min-max kulonbsegei): " 
         << diffs[0] << ", " << diffs[1] << ", " << diffs[2] << "\n\n";
    delete[] diffs; // Ne felejtsük el felszabadítani a memóriát!

    // 3. Feladat tesztje
    int a = 10;
    cout << "3. feladat: Eredeti ertek: " << a << "\n";
    muv(a, "szoroz", 2);
    cout << "Muvelet (szoroz 2) utan: " << a << "\n\n";

    // 4. Feladat tesztje
    cout << "4. feladat:\n";
    feladat4();
    cout << "\n";

    // 5. Feladat tesztje (Fájlművelet)
    // cout << "5. feladat...\n";
    // feladat5();

    return 0;
}
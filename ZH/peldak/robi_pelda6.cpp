#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>

using namespace std;

// ---------------------------------------------------------
// 1. Feladat: % operátor túlterhelése (string % int)
// ---------------------------------------------------------
string operator%(const string& str, int n) {
    if (n <= 0) return "";
    // Ha n nagyobb vagy egyenlő a hosszával, visszaadjuk az egészet
    if (n >= str.length()) return str; 
    return str.substr(0, n);
}

// ---------------------------------------------------------
// 2. Feladat: 3x3-as tömb oszlopainak mediánja
// ---------------------------------------------------------
int* oszlopMedianok(int matrix[3][3]) {
    int* medianok = new int[3];
    
    for (int j = 0; j < 3; j++) {
        // Kigyűjtjük az adott oszlop 3 elemét
        int oszlop[3] = {matrix[0][j], matrix[1][j], matrix[2][j]};
        
        // Egy 3 elemű tömb rendezése egyszerű cserékkel
        if (oszlop[0] > oszlop[1]) swap(oszlop[0], oszlop[1]);
        if (oszlop[1] > oszlop[2]) swap(oszlop[1], oszlop[2]);
        if (oszlop[0] > oszlop[1]) swap(oszlop[0], oszlop[1]);
        
        // A rendezés után a középső (1-es indexű) elem a medián
        medianok[j] = oszlop[1];
    }
    
    return medianok;
}

// ---------------------------------------------------------
// 3. Feladat: Műveletvégző függvény
// ---------------------------------------------------------
void muv(int& a, string muvelet, int b) {
    if (muvelet == "növel") {
        a += b;
    } else if (muvelet == "csökkent") {
        a -= b;
    } else if (muvelet == "szoroz") {
        a *= b;
    } else if (muvelet == "oszt") {
        if (b != 0) {
            a /= b;
        } else {
            cout << "Hiba: nullaval valo osztas!\n";
        }
    }
}

// ---------------------------------------------------------
// 4. Feladat: Kutya struktúra bekérése és szétválogatása
// ---------------------------------------------------------
struct Kutya {
    string neve;
    string fajtaja;
    string merete;
    int szuletesi_eve;
};

void feladat4() {
    Kutya kutyak[5];
    vector<Kutya> kicsi_kutyak;
    vector<Kutya> nagy_kutyak;

    cout << "Kerek 5 kutya adatat:\n";
    for (int i = 0; i < 5; i++) {
        cout << i + 1 << ". kutya neve: ";
        cin >> kutyak[i].neve;
        cout << "Fajtaja: ";
        cin >> kutyak[i].fajtaja;
        cout << "Merete (kicsi/nagy): ";
        cin >> kutyak[i].merete;
        cout << "Szuletesi eve: ";
        cin >> kutyak[i].szuletesi_eve;

        // Rögtön a bekérés után szét is válogatjuk őket a két vektorba
        if (kutyak[i].merete == "kicsi") {
            kicsi_kutyak.push_back(kutyak[i]);
        } else if (kutyak[i].merete == "nagy") {
            nagy_kutyak.push_back(kutyak[i]);
        }
    }

    cout << "\nKicsi kutyak szama: " << kicsi_kutyak.size() << "\n";
    cout << "Nagy kutyak szama: " << nagy_kutyak.size() << "\n";
}

// ---------------------------------------------------------
// 5. Feladat: Mátrix átlóinak vizsgálata maximum alapján
// ---------------------------------------------------------
void feladat5() {
    ifstream be("randomok.txt");
    ofstream ki("nagyobb.txt");

    if (!be.is_open()) {
        cout << "Nem sikerult megnyitni a randomok.txt fajlt!\n";
        return;
    }

    int matrix[5][5];
    string sor;
    int i = 0;

    // Fájl beolvasása (az 5x5-ös méretet a mintafájl alapján feltételezzük)
    while (getline(be, sor) && i < 5) {
        if (sor.empty()) continue;
        stringstream ss(sor);
        for (int j = 0; j < 5; j++) {
            ss >> matrix[i][j];
        }
        i++;
    }

    int max1 = -999999; // Főátló maximuma
    int max2 = -999999; // Mellékátló maximuma
    vector<int> atlo1_elemek;
    vector<int> atlo2_elemek;

    for (int k = 0; k < 5; k++) {
        // Főátló
        int val1 = matrix[k][k];
        atlo1_elemek.push_back(val1);
        if (val1 > max1) max1 = val1;

        // Mellékátló
        int val2 = matrix[k][4 - k];
        atlo2_elemek.push_back(val2);
        if (val2 > max2) max2 = val2;
    }

    // Kiírás a fájlba a nagyobb maximum alapján
    if (max1 > max2) {
        for (size_t j = 0; j < atlo1_elemek.size(); j++) {
            ki << atlo1_elemek[j] << (j == atlo1_elemek.size() - 1 ? "" : " ");
        }
    } else if (max2 > max1) {
        for (size_t j = 0; j < atlo2_elemek.size(); j++) {
            ki << atlo2_elemek[j] << (j == atlo2_elemek.size() - 1 ? "" : " ");
        }
    } else {
        ki << "A ket atlo maximuma egyenlo.";
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
    string szoveg = "alma";
    cout << "1. feladat (\"alma\" % 2): " << (szoveg % 2) << "\n\n";

    // 2. Feladat tesztje
    int matrix[3][3] = {
        {10, 5, 2},
        {1, 20, 8},
        {5, 1, 15}
    };
    /* Mediánok:
       0. oszlop: 1, 5, 10 -> medián: 5
       1. oszlop: 1, 5, 20 -> medián: 5
       2. oszlop: 2, 8, 15 -> medián: 8 */
    int* medianok = oszlopMedianok(matrix);
    cout << "2. feladat (Oszlopok medianjai): " 
         << medianok[0] << ", " << medianok[1] << ", " << medianok[2] << "\n\n";
    delete[] medianok;

    // 3. Feladat tesztje
    int a = 10;
    muv(a, "szoroz", 2);
    cout << "3. feladat (10 szorozva 2-vel): " << a << "\n\n";

    // 4. Feladat tesztje
    // cout << "4. feladat:\n";
    // feladat4();
    // cout << "\n";

    // 5. Feladat tesztje
    // cout << "5. feladat...\n";
    // feladat5();

    return 0;
}
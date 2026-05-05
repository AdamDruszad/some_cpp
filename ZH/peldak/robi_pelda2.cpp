#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <algorithm>
#include <map>
#include <cctype>

using namespace std;

// ---------------------------------------------------------
// 1. Feladat: Két szám közötti legkisebb 3-mal és 5-tel (azaz 15-tel) osztható szám
// ---------------------------------------------------------
int legkisebbOszthato(int a, int b) {
    int start = min(a, b);
    int end = max(a, b);

    for (int i = start; i <= end; i++) {
        // A 3-mal és 5-tel való oszthatóság egyenértékű a 15-tel való oszthatósággal
        if (i % 15 == 0 && i != 0) { // A 0 technikailag osztható, de általában nem ezt keressük
            return i;
        }
    }
    return 0; // Ha nem létezik ilyen
}

// ---------------------------------------------------------
// 2. Feladat: 3x3-as tömb 25-nél nagyobb elemei egy 9 méretű tömbben
// ---------------------------------------------------------
int* nagyobbMint25(int matrix[3][3]) {
    // Dinamikusan foglalunk egy 9 méretű tömböt, 0-kal inicializálva
    int* eredmeny = new int[9]{0};
    int index = 0;

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (matrix[i][j] > 25) {
                eredmeny[index] = matrix[i][j];
                index++;
            }
        }
    }
    return eredmeny;
}

// ---------------------------------------------------------
// 3. Feladat: 3 integer rendezése pointeres paraméterátadással
// ---------------------------------------------------------
void rendez(int* a, int* b, int* c) {
    // Egyszerű buborékrendezés logikája 3 elemre pointereken keresztül
    if (*a > *b) swap(*a, *b);
    if (*b > *c) swap(*b, *c);
    if (*a > *b) swap(*a, *b); // Még egyszer ellenőrizni kell az első kettőt
}

// ---------------------------------------------------------
// 4. Feladat: Stringek hosszának vizsgálata átlag alapján
// ---------------------------------------------------------
void feladat4() {
    int a;
    string s[5];

    cout << "Kerek egy egesz szamot (a): ";
    cin >> a;

    cout << "Kerek 5 db szokoz nelkuli stringet:\n";
    int osszHossz = 0;
    for (int i = 0; i < 5; i++) {
        cin >> s[i];
        osszHossz += s[i].length();
    }

    double atlag = (double)osszHossz / 5.0;
    double hatarErtek = a + atlag;

    cout << "A feltetelnek megfelelo stringek (hossz < " << hatarErtek << "):\n";
    for (int i = 0; i < 5; i++) {
        if (s[i].length() < hatarErtek) {
            cout << s[i] << "\n";
        }
    }
}

// ---------------------------------------------------------
// 5. Feladat: Fájl beolvasása, betűk statisztikája
// ---------------------------------------------------------
void feladat5() {
    ifstream be("sorok.txt");
    ofstream ki("gyakori.txt");

    if (!be.is_open()) {
        cout << "Nem sikerult megnyitni a sorok.txt fajlt!\n";
        return;
    }

    map<char, int> betuGyakorisag;
    char c;
    int a_db = 0, b_db = 0;

    // Karakterenkénti beolvasás (a szóközöket és újsorokat is olvassa a get)
    while (be.get(c)) {
        // Csak a nem üres karakterekkel foglalkozunk
        if (!isspace(c)) {
            // Kisbetűssé alakítjuk, hogy a kis- és nagybetűk ne számítsanak külön
            // (Megjegyzés: az ékezetes karaktereket a sima tolower/char nem kezeli tökéletesen,
            // de alap egyetemi feladatoknál ez általában elvárt egyszerűsítés).
            char kisbetu = tolower((unsigned char)c);
            betuGyakorisag[kisbetu]++;

            if (kisbetu == 'a') a_db++;
            if (kisbetu == 'b') b_db++;
        }
    }

    char leggyakoribbBetu = '\0';
    int maxElfordulas = 0;

    for (auto const& par : betuGyakorisag) {
        if (par.second > maxElfordulas) {
            maxElfordulas = par.second;
            leggyakoribbBetu = par.first;
        }
    }

    ki << "Leggyakrabban elofordulo betu: '" << leggyakoribbBetu << "' (" << maxElfordulas << " db)\n";
    ki << "Az 'a' betuk szama: " << a_db << "\n";
    ki << "A 'b' betuk szama: " << b_db << "\n";

    be.close();
    ki.close();
    cout << "A gyakori.txt fajl elkeszult.\n";
}

// ---------------------------------------------------------
// Főprogram (Main) - A teszteléshez
// ---------------------------------------------------------
int main() {
    // 1. Feladat tesztje
    cout << "1. feladat (10 es 40 kozott a legkisebb 15-tel oszthato): " << legkisebbOszthato(10, 40) << "\n\n";

    // 2. Feladat tesztje
    int matrix[3][3] = {
        {10, 26, 5},
        {30, 20, 50},
        {1, 99, 25} // A 25 nem nagyobb, mint 25
    };
    int* eredmenyTomb = nagyobbMint25(matrix);
    cout << "2. feladat (25-nel nagyobb elemek): ";
    for (int i = 0; i < 9; i++) {
        if (eredmenyTomb[i] != 0) {
            cout << eredmenyTomb[i] << " ";
        }
    }
    cout << "\n\n";
    delete[] eredmenyTomb; // Memóriafelszabadítás

    // 3. Feladat tesztje
    int x = 50, y = 10, z = 30;
    rendez(&x, &y, &z);
    cout << "3. feladat (rendezett ertekek): " << x << ", " << y << ", " << z << "\n\n";

    // 4. Feladat tesztje (Kommentezd ki, ha nem akarsz gépelni a konzolba)
    // cout << "4. feladat:\n";
    // feladat4();
    // cout << "\n";

    // 5. Feladat tesztje
    // cout << "5. feladat...\n";
    // feladat5();

    return 0;
}
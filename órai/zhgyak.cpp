#include <iostream>
#include <string>
#include <array>
#include <vector>
#include <fstream>
#include <sstream>

using namespace std;

/*
    1. feladat
    Függvény, amely két egész szám között megkeresi a legnagyobb Fibonacci-számot.
    Ha nincs ilyen, akkor -1-et ad vissza.
*/
int legnagyobbFibonacci(int a, int b)
{
    int also, felso;

    if (a < b)
    {
        also = a;
        felso = b;
    }
    else
    {
        also = b;
        felso = a;
    }

    int legnagyobb = -1;

    long long x = 0;
    long long y = 1;

    while (x <= felso)
    {
        if (x >= also)
        {
            legnagyobb = (int)x;
        }

        long long kov = x + y;
        x = y;
        y = kov;
    }

    return legnagyobb;
}

/*
    2. feladat
    Függvény, amely egy 4x4-es tömb soronkénti átlagait adja vissza.
*/
array<double, 4> sorAtlagok(int tomb[4][4])
{
    array<double, 4> atlagok;

    for (int i = 0; i < 4; i++)
    {
        int osszeg = 0;

        for (int j = 0; j < 4; j++)
        {
            osszeg += tomb[i][j];
        }

        atlagok[i] = osszeg / 4.0;
    }

    return atlagok;
}

/*
    3. feladat
    A függvény bemásolja a tömb b-edik elemét az 'a' karakterbe.
    Azért referencia (&), hogy a függvény tényleg módosítsa az eredeti változót.
*/
void masolKarakter(char &a, const char tomb[10], int b)
{
    if (b >= 0 && b < 10)
    {
        a = tomb[b];
    }
    else
    {
        cout << "Hibas index! Az indexnek 0 es 9 kozott kell lennie." << endl;
    }
}

/*
    5. feladat
    Doboz struktúra
*/
struct Doboz
{
    double szelesseg;
    double magassag;
    double melyseg;
};

/*
    6. feladat
    randomok.txt beolvasása, sorátlag vizsgálata,
    majd Igen/Nem kiírása a kisebb.txt fájlba.
*/
void fajlFeldolgozas()
{
    ifstream be("randomok.txt");
    ofstream ki("kisebb.txt");

    if (!be.is_open())
    {
        cout << "Nem sikerult megnyitni a randomok.txt fajlt!" << endl;
        return;
    }

    if (!ki.is_open())
    {
        cout << "Nem sikerult letrehozni a kisebb.txt fajlt!" << endl;
        return;
    }

    string sor;

    while (getline(be, sor))
    {
        stringstream ss(sor);
        vector<int> szamok;
        int szam;

        while (ss >> szam)
        {
            szamok.push_back(szam);
        }

        if (!szamok.empty())
        {
            int osszeg = 0;

            for (int i = 0; i < szamok.size(); i++)
            {
                osszeg += szamok[i];
            }

            double atlag = (double)osszeg / szamok.size();

            if (atlag < 37)
            {
                ki << "Igen" << endl;
            }
            else
            {
                ki << "Nem" << endl;
            }
        }
    }

    be.close();
    ki.close();

    cout << "A fajl feldolgozasa kesz. Az eredmeny a kisebb.txt fajlba kerult." << endl;
}

int main()
{
    // --------------------------------------------------
    // 1. feladat
    // --------------------------------------------------
    cout << "1. feladat - Legnagyobb Fibonacci-szam ket szam kozott" << endl;
    int a1, b1;
    cout << "Adjon meg ket egesz szamot: ";
    cin >> a1 >> b1;

    int fib = legnagyobbFibonacci(a1, b1);

    if (fib == -1)
    {
        cout << "Nincs Fibonacci-szam a ket szam kozott." << endl;
    }
    else
    {
        cout << "A legnagyobb Fibonacci-szam: " << fib << endl;
    }

    cout << endl;

    // --------------------------------------------------
    // 2. feladat
    // --------------------------------------------------
    cout << "2. feladat - 4x4-es tomb soronkénti atlagai" << endl;

    int matrix[4][4] =
    {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {2, 2, 2, 2},
        {10, 20, 30, 40}
    };

    array<double, 4> atlagok = sorAtlagok(matrix);

    cout << "A sorok atlagai:" << endl;
    for (int i = 0; i < 4; i++)
    {
        cout << i + 1 << ". sor atlaga: " << atlagok[i] << endl;
    }

    cout << endl;

    // --------------------------------------------------
    // 3. feladat
    // --------------------------------------------------
    cout << "3. feladat - Karakter masolasa tombbol" << endl;

    char a = '?';
    char tomb[10] = {'p', 'r', 'o', 'g', 'r', 'a', 'm', 'o', 'z', 'a'};
    int index;

    cout << "Adjon meg egy indexet 0 es 9 kozott: ";
    cin >> index;

    masolKarakter(a, tomb, index);

    cout << "Az 'a' karakter uj erteke: " << a << endl;

    cout << endl;

    // --------------------------------------------------
    // 4. feladat
    // --------------------------------------------------
    cout << "4. feladat - Legrövidebb es leghosszabb szo" << endl;

    int n;
    cout << "Hany darab szot szeretne megadni? ";
    cin >> n;

    if (n > 0)
    {
        string szo;
        string legrovidebb, leghosszabb;

        cout << "Adja meg a szavakat:" << endl;

        cin >> szo;
        legrovidebb = szo;
        leghosszabb = szo;

        for (int i = 1; i < n; i++)
        {
            cin >> szo;

            if (szo.length() < legrovidebb.length())
            {
                legrovidebb = szo;
            }

            if (szo.length() > leghosszabb.length())
            {
                leghosszabb = szo;
            }
        }

        cout << "Legrovidebb szo: " << legrovidebb << endl;
        cout << "Leghosszabb szo: " << leghosszabb << endl;
    }
    else
    {
        cout << "A darabszamnak pozitivnak kell lennie." << endl;
    }

    cout << endl;

    // --------------------------------------------------
    // 5. feladat
    // --------------------------------------------------
    cout << "5. feladat - Dobozok tornyanak magassaga" << endl;

    Doboz dobozok[5];

    for (int i = 0; i < 5; i++)
    {
        cout << i + 1 << ". doboz adatai:" << endl;
        cout << "Szelesseg: ";
        cin >> dobozok[i].szelesseg;
        cout << "Magassag: ";
        cin >> dobozok[i].magassag;
        cout << "Melyseg: ";
        cin >> dobozok[i].melyseg;
        cout << endl;
    }

    double toronyMagassag = 0;

    for (int i = 0; i < 5; i++)
    {
        toronyMagassag += dobozok[i].magassag;
    }

    cout << "A torony teljes magassaga: " << toronyMagassag << endl;

    cout << endl;

    // --------------------------------------------------
    // 6. feladat
    // --------------------------------------------------
    cout << "6. feladat - Fajl feldolgozasa" << endl;
    fajlFeldolgozas();
	
	 ifstream be("randomok.txt");
    ofstream ki("kisebb.txt");

    if (!be.is_open())
    {
        cout << "Nem sikerult megnyitni a randomok.txt fajlt!" << endl;
        return 1;
    }

    if (!ki.is_open())
    {
        cout << "Nem sikerult letrehozni a kisebb.txt fajlt!" << endl;
        return 1;
    }

    vector<vector<int>> adatok;
    string sor;

    while (getline(be, sor))
    {
        stringstream ss(sor);
        vector<int> egySor;
        int szam;

        while (ss >> szam)
        {
            egySor.push_back(szam);
        }

        if (!egySor.empty())
        {
            adatok.push_back(egySor);
        }
    }

    for (int i = 0; i < adatok.size(); i++)
    {
        int osszeg = 0;

        for (int j = 0; j < adatok[i].size(); j++)
        {
            osszeg += adatok[i][j];
        }

        double atlag = (double)osszeg / adatok[i].size();

        if (atlag < 37)
        {
            ki << "Igen" << endl;
        }
        else
        {
            ki << "Nem" << endl;
        }
    }

    be.close();
    ki.close();

    cout << "A feldolgozas kesz, az eredmeny a kisebb.txt fajlba kerult." << endl;

    return 0;
}
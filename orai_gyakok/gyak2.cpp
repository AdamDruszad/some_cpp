#include <iostream>

using namespace std;

int main() {
    //összehasonlító operátorok
    // ==    <=    >=    <    >    !=

    //logikai operátorok
    // &&    ||     ! -- és,vagy,negáció

    bool b = 60 < 5;

    cout << !b << " " << (b && true) << " " << ((60 < 5) || true) << endl;

    //bitműveletek
    //operátorai:   &   |  ^  <<  >>  -- bitenénti és, vagy, XOR, eltolás balra, jobbra

    int A = 60;
    int B = 13;

    cout << (A & B) << " " << (A | B) << " " << A << 2 << endl;
    cout << (A & B) << " " << (A | B) << " " << (A << 2) << endl;

    //értékadó operátorok:
    // =   +=  -=   *=   %=   &=   |=   ^=
    // A += 10              A = A + 10
    // B *= 2               B = B * 2

    int tomb[5] = {1, 2, 3, 4, 5};
    tomb[0] = 15;

    cout << tomb[0] << " " << tomb[4] << endl;
    cout << tomb[15] << endl;

    char sztring[] = "Hello World!";
    sztring[0] = 'h';

    cout << sztring << endl;
    //    sztring = 'hello';

    //std::string
    string s = "Hello World!";
    s[0] = 'h';
    cout << s << endl;
    s = "hello,hello,hello,hello,hello,hello";

    //típuskonverzió
    //implicit          -- amikor el tudja végezni, akkor el is végzi

    int n = 75;
    double d = n;
    /*
        int   -   double
        75  --->   75.0
        75  <---   75.123
     */

    d = 75.123;
    n = d;

    //explicit

    d = 75.123;
    n = int(d);

    cout << char(n) << " " << int('X') << endl;

    //feltételes/elágazó utasítás

    if(10 < 11) {
        cout << "igaz" << endl;
    }

    if (21 < 10) {
        cout << "kisebb" << endl;
    } else {
        cout << "nagyobb, vagy egyenlő" << endl;
    }

    if (21<10) {
        cout << "kisebb" << endl;
    } else if (21==10) {
        cout << "egyenlő" << endl;
    } else {
        cout << "nagyobb" << endl;
    }

    if (0) {
        cout << "hamis" << endl;
    }

    if (false) {
        cout << "hamis" << endl;
    }

    if (1) {
        cout << "igaz" << endl;
    }

    if (110) {
        cout << "igaz" << endl;
    }

    if ( A = 2 ) {
        cout << "igaz" << endl;
    }

    //ternáris operátor
    //   ?:
    // feltétel ? ha, igaz ez legyen : ha, hamis ez legyen;

    bool bl = A==B ? true : false;
    cout << bl << endl;

    int x1 = 24;
    int x2 = 25;

    string eredmeny = x1 > x2 ? "nagyobb" : (x1 < x2 ? "kisebb" : "egyenlő");

    cout << eredmeny << endl;

    int nap = 6;

    switch (nap) {
        case 1:
            cout << "hétfő" << endl;
            break;
        case 2:
            cout << "kedd" << endl;
            break;
        case 3:
            cout << "szerda" << endl;
            break;
        case 4:
            cout << "csütörtök" << endl;
            break;
        case 5:
            cout << "péntek" << endl;
            break;
        case 6:
            cout << "szombat" << endl;
            break;
        case 7:
            cout << "vasárnap" << endl;
            break;
        default:
            cout << "nincs 7+ nap" << endl;
    }

    //ciklusszervező utasítás

    //előltesztelő ciklus

    int i = 1;
    while (i <= 10){
        cout << i << endl;
        i++;
    }

    float f = 10.0;

    while (f > 4.9) {
        cout << f << "\n";
        f -= 0.1f; // -- azért van az az f, hogy biztosan tudja a fordító, hogy float
    }


    cout << endl;

    int a = 65;

    while (a < 91) {
        cout << char(a) << "\n";
        a += 2;
    }

















}
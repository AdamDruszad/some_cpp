#include <iostream>

using namespace std;
int main() {

    //hátultesztelő ciklus 1...n alkalommal fut le
    //do-while

    int i = 10;

    do {
        cout << i++ << endl;
    }while (i < 10);

    //meghatározott/előírt lépésszámú ciklus
    //for
    //for(ciklusváltozó megmondása; futási feltétel; ciklusváltozó értékváltozása){   }

    for (int i = 0; i < 10; i++) {
        cout << i << " ";
    }
    cout << endl;

    for (char i = 'Z'; i >= 'A'; i--) {
        cout << char(i) << " ";
        cout << char(tolower(char(i))) << " ";
    }
    cout << endl;

    //végtelen ciklusok

    /*
        while(true){
            cout << "végtelen ciklus\n";
        }
    */

    /*
        for(;;){
            cout << "végtelen ciklus\n";
        }    
    */

    for(int i = 0;;){
        cout << ++i << endl;
        if(i == 5){
            cout << endl;
            break;
        }
    }

    for(int i = 0; i < 10; i++){
        if((i%2==0) || (i%3==0)){
            continue;
        }
        cout << i << " "; 
    }
    cout << endl;

    //foreach
    //for(konténer_1_elemének típusa változónév : konténer neve){   }

    int meret = 5;
    int szamok[meret] = {1,2,3,4,5};

    for(int szam : szamok){
        cout << szam << " "; 
    }
    cout << endl;

//  =====

    for(int i = 0; i<meret; i++){
        cout << szamok[i] << " ";
    }
    cout << endl;

//  =====

    // sizeof(szamok) ==> 20byte ==> (int)4byte * 5
    //sizeof(int) ==> 4byte

    for(int i = 0; i < sizeof(szamok)/sizeof(int); i++){
        cout << szamok[i] << " ";
    }
    cout << endl;


    int szamok2d[3][3] = {
        {1, 2,  4},
        {4, 5,  7},
        {7, 8, 10}
    };

    /*
        for(int i = 0; i < 3; i++){
            for(int j = 0; j < 3; j++){
                cout << "szamok2d[" << i << "][" << j << "]: " << szamok2d[i][j];
            }
        }
        cout << endl;

        for(int i = 0; i < 3; i++){
            for(int j = 0; j < 3; j++){
                cout << szamok2d[i][j] << " ";
            }
        cout << endl;
        }
    */
    

    //sorátlag
    /*
    int osszeg;
    for(int i = 0; i < 3; i++){
        osszeg = 0;
        for(int j = 0; j < 3; j++){
            osszeg += szamok2d[i][j];
        }
        cout << osszeg/3.0f << endl;
    }
    cout << endl;*/

    int osszeg = 0;
    for(int i = 0, j = 0; i < 3, j<3; i++, j++){
        cout << szamok2d[i][j] << endl;
        osszeg += szamok2d[i][j];
        
        
    }
    cout << osszeg/3.0f<< endl;
    cout << endl;

    int osszegj = 0;
    for(int i = 0, j = 2; i < 3; i++, j--){
        cout << szamok2d[i][j] << endl;
        osszegj += szamok2d[i][j];
        
        
    }
    cout << osszegj/3.0f<< endl;
    cout << endl;














}
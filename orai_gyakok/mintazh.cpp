#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>

using namespace std;

int fiboszamokkozt(int a, int b);
vector<float> egydimenzioba(int Arr[4][4]);
void bazaba(char &a, char tomb[10], char b);
void kicsiNagy();

class Doboz{
    public:
    Doboz(){}
    int szelesseg;
    int magassag;
    int melyseg;
    Doboz(int szelesseg, int magassag, int melyseg): szelesseg(szelesseg), magassag(magassag), melyseg(melyseg){}
};

int main(){
    cout << fiboszamokkozt(0, 0);
    cout << endl;
    //----------------------------------
    int twoDimArr[4][4] = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12},
        {13, 14, 15, 16}
    };
    for(float i : egydimenzioba(twoDimArr)){
        cout << i << " ";
    }
    cout << endl;
    //-----------------------------------
    char a = '1';
    char b = '5';
    char tomb[10] = {'s','d', 'h', 'e', 'q', 'z','l','a','b','x'};
    bazaba(a, tomb, b);
    cout << a << endl;
    //--------------------------------
    kicsiNagy();
    //------------------------------------
    Doboz dobozok[5];
    for(int i = 0; i <5 ; i++){
        Doboz d(i+1, i+3, i+4);
        dobozok[i] = d;
    }
    int magassag = 0;
    for(Doboz i : dobozok){
        magassag += i.magassag;
    }
    cout << "Ha egymásra pakoljuk őket, akkor ilyen magas lesz: " << magassag;
    //--------------------------------------------------------------------------
    ifstream infile("randomok.txt");
    string line;
    vector<string> lines;

    while(getline(infile, line)){
        lines.push_back(line);
    }

    infile.close();
    
    ofstream outfile("kisebb.txt");

    for(string i : lines){
        int avg = 0;
        istringstream iss(i);
        int szam;
        int c = 0;
        while(iss >> szam){
            c++;
            avg += szam;
        }
        avg /= c;
        if(avg<37){
            outfile << "Igen\n";
        }else{
            outfile << "Nem\n";
        }
    }
}

int fiboszamokkozt(int a, int b){
    if(b <= 0){ return 0; }

    int legnagyobbfibo = 0;

    int elozo = 0;
    int jelenlegi = 1;

    while(jelenlegi <= b){
        if(jelenlegi >= a){
            legnagyobbfibo = jelenlegi;
        }

        int kovetkezo = jelenlegi + elozo;
        elozo = jelenlegi;
        jelenlegi = kovetkezo;
    }
    return legnagyobbfibo;
}

vector<float> egydimenzioba(int Arr[4][4]){
    vector<float> avgArr;
    for(int i = 0; i < 4; i++){
        float avg = 0;
        for(int j = 0; j < 4; j++){
            avg += Arr[i][j];
        }
        avgArr.push_back(avg/4);
    }
    return avgArr;
}

void bazaba(char &a, char tomb[10], char b){
    a = tomb[b-'0'-1];
}

void kicsiNagy(){
    int n;
    cout << "Hány szó lesz? ";
    cin >> n;

    if(n <= 0){
        std::cout << "Hiba";
        return;
    }

    vector<string> tomb;
    string szo;
    for(int i = 0; i < n; i++){
        cout << "Add meg a szót: ";
        cin >> szo;
        tomb.push_back(szo);
    }
    string legkisebb = tomb[0];
    string legnagyobbb = tomb[0];
    for(string i : tomb){
        if(i.length() > legnagyobbb.length()){
            legnagyobbb = i;
        }
        if(i.length()< legkisebb.length()){
            legkisebb = i;
        }
    }
    cout << "Legkisebb " << legkisebb << endl;
    cout << "Legnagyobb " << legnagyobbb << endl;
}
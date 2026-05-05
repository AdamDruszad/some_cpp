#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <fstream>

using namespace std;

/*
Szarvas Péter
C2V5KL
K16
*/

int first(int a, int b) {

    int n;
    vector <int> nums = {0, 1, 1};

    for (int i = 3; i < b; i++) {
        n = nums[i-1] + nums[i-2];
        nums.push_back(n);
        if (nums[nums.size()-1] >= b) {
            break;
        }
    }

    return nums[nums.size()-2];
}

void second(int arr[4][4]) {

    float avgArr[4];
    float avg;

    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            avg += arr[i][j];
        }
        avg = avg/4;
        avgArr[i] = avg;
    }

    for (int i = 0; i < 4; i++) {
        cout << avgArr[i] << " ";
    }

    cout << endl;
}

void third(char a, char arr[10], int b) {

    a = arr[b];
    cout << a << endl;

}

void fourht(int a) {

    vector <string> v;
    string s;
    cout << "Kérem adjon meg " << a << " db szót: " << endl;

    for (int i = 0; i < a; i++) {
        cin >> s;
        v.push_back(s);
    }

    int maxi = v[0].size();
    string maxs = v[0];

    int mini = v[0].size();
    string mins = v[0];

    for (int i = 0; i < v.size(); i++) {
        if (v[i].size() > maxi) {
            maxs = v[i];
            maxi = v[i].size();
        }
    }

    for (int i = 0; i < v.size(); i++) {
        if (v[i].size() < mini) {
            mins = v[i];
            mini = v[i].size();
        }
    }

    cout << "Legrövidebb: " << mins << endl;
    cout << "Leghosszabb: " << maxs << endl;

}

class Doboz {

    public:
        int lenght;
        int width;
        int height;

    Doboz(int lenght, int width, int height):lenght(lenght), width(width), height(height){}

};

void operator<<(ostream& o, Doboz& d) {
    o << d.lenght << " " << d.width << d.height << endl;
}

int main() {

    cout << first(0, 14) <<endl;
    int twoDimArr[4][4] = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12},
        {13, 14, 15, 16}
    };

    second(twoDimArr);

    char chArray[10] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j'};
    char a = 'z';
    third(a, chArray, 5);

    int n;
    cout << "Kérem adjon meg egy számot: " << endl;
    cin >> n;

    fourht(n);

    Doboz d0 = Doboz(1, 2, 3);
    Doboz d1 = Doboz(4, 5, 6);
    Doboz d2 = Doboz(7, 8, 9);
    Doboz d3 = Doboz(10, 11, 12);
    Doboz d4 = Doboz(13, 14, 15);
    Doboz dobozok[5] ={d0, d1, d2, d3, d4};

    int sumOfHeight;

    for (int i = 0; i<5; i++) {
        sumOfHeight += dobozok[i].height;
    }

    cout << "A teljes magassága a dobozoknak: " << sumOfHeight << endl;

    ifstream inFile("randomok.txt");
    string line;
    vector <string> lines;

    while (getline(inFile, line)) {
		lines.push_back(line);
    }

    inFile.close();

    int avg;

    ofstream outFile("kisebb.txt");
    
    if (avg < 37) {
        outFile << "Igen";
    } else {
        outFile <<
         "Nem";
    }

    outFile.close();

    return 0;
}
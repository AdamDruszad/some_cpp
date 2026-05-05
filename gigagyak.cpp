#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

int oneToHundredSumInEff() {

    int sum;

    for (int i = 0; i <= 100; i++) {
        sum += i;
    }

    return sum;

}

int oneToHundredSumEff() {
    
    int sum;

    for (int i = 0; i < 50; i++) {
        sum += 101;
    }

    return sum;

}

/*
    Írjon függvényt, amelynek 2 integer paramétere van,
    és kiírja 100-ig azokat a számokat, amelyek oszthatóak a megadott 2 számmal.
*/

void twoDivideHundredOR(int n1, int n2) {
    
    for (int i = 1; i < 101; i++) {
        if (i % n1 == 0 || i % n2 == 0) {
            cout << i << " ";
        }
    }

    cout << endl;

}

void twoDivideHundredAND(int n1, int n2) {
    
    for (int i = 1; i < 101; i++) {
        if (i % n1 == 0 && i % n2 == 0) {
            cout << i << " ";
        }
    }

    cout << endl;

}

/*
    Írjon függvényt, amelynek egy 10 méretű integer tömb a paramétere, és visszaadja a leggyakoribb elemet.
*/

int mostCommon(int arr[10]) {
    
    unordered_map <int, int> map;

    for (int i = 0; i < 10; i++) {
        map[arr[i]]++;
    }

    int counter = 0;
    int common = 0;

    for (auto p:map) {
        if (p.second > counter) {
            counter = p.second;
            common = p.first;
        }
    }

    return common;

}

/*
    Írjon függvényt, amelynek egy 10 méretű integer tömb és egy egész szám a paramétere,
    majd rendezi a második paramétertől a tömböt.
    Pl 5, akkor a tömb 5.elemétől rendezi.
*/

void sortFrom(int arr[10], int num) {

    cout << "Unsorted: " << endl;

    for (int i = 0; i < 10; i++) {
        cout << arr[i] << " ";
    }

    cout << endl;

    sort(arr+num, arr+10);

    cout << "Sorted: " << endl;

    for (int i = 0; i < 10; i++) {
        cout << arr[i] << " ";
    }

    cout << endl;

}

void sortDesc(int arr[10]) {

    cout << "Unsorted: " << endl;

    for (int i = 0; i < 10; i++) {
        cout << arr[i] << " ";
    }

    cout << endl;

    sort(arr, arr+10, greater<int>());

    cout << "Sorted: " << endl;

    for (int i = 0; i < 10; i++) {
        cout << arr[i] << " ";
    }

    cout << endl;

}

int decr(int *num){
    return *num-1;
}

/*
    Hozzon létre egy osztályt vagy struktúrát labda néven, amelynek mérete és színe van. 
    Töltsön fel egy 5 méretű tömböt labdákkal.
    Írja ki a képernyőre, hogy hány piros és hány kék labdánk van.
*/

class Ball {
    
    public:
        int size;
        string color;

        Ball(int size, string color):size(size), color(color){}

};

void operator<<(ostream& o, Ball& b) {
    o << b.size << " " << b.color << endl;
}


int main() {

    cout << oneToHundredSumEff() << endl;
    twoDivideHundredOR(2, 5);
    twoDivideHundredAND(2, 5);
    
    int arr[10] = {1, 3, 2, 4, 5, 4, 7, 3, 4, 2};

    cout << mostCommon(arr) << endl;
    sortFrom(arr, 5);
    sortDesc(arr);

    int num = 70;
    int *ptr = &num;
    cout << decr(ptr) << endl;

    Ball b0 = Ball(1, "Piros");
    Ball b1 = Ball(2, "Kék");
    Ball b2 = Ball(3, "Zöld");
    Ball b3 = Ball(4, "Piros");
    Ball b4 = Ball(5, "Kék");
    Ball balls[5] ={b0, b1, b2, b3, b4};

    unordered_map <string, int> ballsMap;

    for (int i = 0; i<5; i++) {
        if (balls[i].color == "Kék" || balls[i].color == "Piros") {
            ballsMap[balls[i].color]++;
        }

    }

    for (auto b:ballsMap) {
        cout << b.first << " " << b.second << endl;
    }

    return 0;

}
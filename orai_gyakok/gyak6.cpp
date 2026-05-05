#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;
bool isPrime(int n);

int main(){

    std::vector<int> v; //{}

    //push_back --- beszúrja a vektor végére az elemeket

    for(int i = 0; i < 10; i++){
        v.push_back(i*10);
        cout << v[i] << " " << v.at(i) << " " << v.capacity() << " " << v.data() << endl;
    }
 
    //cout << v[50] << endl;  ---- ez túllép a vektor méretén
    //cout << v.at(50) << endl; ---- ez ellenőrzi és hibát az ha nincs ilyen elem

    //v[0] = 15;
    //v.at(9) = 10;
    //cout << v[0] << " " << v[9] << endl;
    
    //v[12] = 150;
    //cout << v[12] << endl;
    //cout << v.at(12) << endl;

    for(int i : v){
        cout << i << " ";
    }
    cout << endl;
    
    v.shrink_to_fit();
    cout << v.capacity() << " " << v.size() << endl;

    v.clear();

    v = {2, 4, 3, 2, 5, 7, 3, 2, 5, 1};

    //rendezzük növekvő sorrenden

    sort(v.begin(), v.end());
    cout << endl;

    //lehetnek ezek a feladatok vizsgába/zh-ba:

    //egyenlő a felső és alsó rendező algritmus
    for (size_t i = 0; i < v.size(); i++) {
        for (size_t j = 0; j < v.size() - 1; j++) {
            if (v[j] > v[j + 1]) {
                // Csere, ha az aktuális elem nagyobb a következőnél
                int temp = v[j];
                v[j] = v[j + 1];
                v[j + 1] = temp;
            }
        }
    }

    for(int i : v){
        cout << i << " ";
    }
    cout << endl;

    //maximum kiválasztás pozicióval
    int max = v[0];
    int maxind = 0;
    for(int i = 0; i < v.size(); i++){
        if(v[i] > max){
            max = v[i];
            maxind = i;
        }
    }
    cout << "A vektor maximuma: " << max << ", a poziciója: " << maxind << endl;

    //megszámlálás tétele:
    //hány xy feltételnek megfelelő elem van a konténerben
    //feltétel érték = 2

    int count = 0;

    for(int i : v){
        if(i == 2){
            count++;
        }
    }
    cout << "A konténerben " << count << " db 2-es van\n";

    //szétválogtás
    //válogassuk külön azokat az elemeket, amelyek megdfelelnek/nem felelnek meg egy adott feltételnek
    //válogassuk szét az átlagtól kisebb é snagyobb elemeket

    int atlag = 0;
    for(int i : v){
        atlag += i;
    }
    atlag /= v.size();

    vector<int> kisebb;
    vector<int> nagyobb;

    for(int i : v){
        if(i < atlag){
            kisebb.push_back(i);
        }
        if(i > atlag){
            nagyobb.push_back(i);
        }
    }
    cout << "Átlag: " << atlag << endl;
    cout << "Átlagtól kisebb:\n";
    for(int i : kisebb){
        cout << i << " ";
    }
    cout << endl;
    for(int i : nagyobb){
        cout << i << " ";
    }
    cout << endl;


    // számoljuk meg a vektorban található primszámokat:

    

    int db = 0;
    for(int i : v){
        if(isPrime(i)){
            db++;
        }
    }

    cout << "Primszámok száma: " << db << endl;
    for(int i : v){
            cout << i << " ";
        }
        cout << endl;

    //2D vektor

    //zh-n lehet nagy méretű adatokat beolvasni és így is lehet
    vector<vector<int>> v2d;

    for(int i = 0; i < 5; i++){
        vector<int> v1d;
        for(int j = 0; j < 5; j++){
            v1d.push_back(i+j*2);
        }
        v2d.push_back(v1d);
    }

    for(int i = 0; i < v2d.size(); i++){
        for(int j = 0; j < v2d[i].size(); j++){
            cout << v2d[i][j] << " ";
        }
        cout << endl;
    }


}

bool isPrime(int n) {
    if (n <= 1) return false;
    for (int i = 2; i <= sqrt(n); i++) {
        if (n % i == 0) return false;
    }
    return true;
}

//medián még lehet zh-ba
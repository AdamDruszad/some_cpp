#include <iostream>

using namespace std;

void print(int a, int b);
int multiply(int a, int b);
void csere(int a, int b);
void cserecim(int& a, int& b);
void cserepointer(int* a, int* b);
void szoroz(int& a, int b);
void tombkiir(int t[5]);
int minimum(int* t, int meret);
int fa(int n);
int fakt(int n);
int fibo(int n);

int main() {
    cout << "----------------------------------5. GYAKORLAT----------------------------------\n";

    //stack memória
    int a = 1;
    int b[5];

    //heap memória
    //pointer-változó név = new típus
    //c malloc és free
    //c++ new és delete

    int* x = new int;
    int * tp = new int[5];

    int * p2 = new(nothrow) int;
    if(!p2){
        cout << "Nem sikerült a memória allokáció\n";
    }else {
        *p2 = 10;
    }


    float *f = new float(11.12);
    *x = 5;

    for(int i = 0; i < 5; i++){
        tp[i] = i*2-1;
        cout << tp[i] << " ";
    }
    cout << endl;

    delete x;
    delete[] tp; //tömböt []-lel kell felszabadítani
    delete p2;
    delete f;

    //függvények
    // void <==> eljárás
    // int/float/stb. <==> függvény

    int y = 2, z = 4;
    
    //cout << y << " " << z << endl;
    print(y, z);
    cout << multiply(y, z) << endl;
    csere(y, z);
    print(y, z);
    cout << endl;
    cserecim(y, z);
    print(y, z);
    cout << endl;
    cserepointer(&y, &z);
    print(y, z);
    cout << endl;
    szoroz(y, z);
    print(y, z);

    int t[5] = {1, 2, 3, 4, 5};

    tombkiir(t);
    cout << endl;
    tombkiir(t);
    cout << endl;
    cout << minimum(t, 5) << endl;

    cout << endl;
    cout << fa(5);
    cout << endl;
    cout << fakt(5);
    cout << endl;
    cout << fibo(1);
    cout << endl;
    cout << fibo(2);
    cout << endl;
    cout << fibo(3);
    cout << endl;
    cout << fibo(4);

}

//eljárás
void print(int a, int b){
    cout << a << " " << b << endl;
}

//függvény
int multiply(int a, int b){
    return a * b;
}

//lokális
void csere(int a, int b){
    int temp = a;
    a = b;
    b = temp;
    print(a, b);
}

//referencia szerinti paraméterátadás
void cserecim(int& a, int& b){
    int temp = a;
    a = b;
    b = temp;
    print(a, b);
}

//pointeres paraméterátadás
void cserepointer(int* a, int* b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

void szoroz(int& a, int b){
    a = a * b++;
}

void tombkiir(int t[5]){
    for(int i = 0; i < 5; i++){
        cout << t[i]++ << " ";
    }
}

int minimum(int* t, int meret){
    int min = t[0];
    for(int i = 1; i < meret; i++){
        if(t[i] < min){
            min = t[i];
        }
    }
    return min;
}

int fa(int n){
    int m = 1;
    for(int i = 1; i <= n; i++){
        m = m * i;
    }
    return m;
}

int fakt(int n){
    if(n > 1){
        return n * fakt(n-1);
    }else{
        return 1;
    }
}

int fibo(int n){
    if(n <= 1){
        return 1;
    }else {
        return fibo(n-1) + fibo(n-2);
    }
}
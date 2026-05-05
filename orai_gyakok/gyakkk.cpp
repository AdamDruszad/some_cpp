#include <iostream>
#include <vector>

int fibo1(int n);
int fibof(int n);
int bigfibo(int a, int b);
std::vector<float> egydim(int arr[4][4]);
void beKer();

class Doboz{
        public:
        Doboz(){}
        int lenght = 0;
        int width = 0;
        int height = 0;
        Doboz(int length, int width, int height): lenght(lenght), width(width), height(height){}
    };

int main(){
    std::cout << bigfibo(1, 10) <<std::endl;
    //--------------------------
    int twoDimArr[4][4] = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12},
        {13, 14, 15, 16}
    };
    egydim(twoDimArr);
    for(float i : egydim(twoDimArr)){
        std::cout << i << " ";
    }
    std::cout << std::endl;
    //------------------
    beKer();
    //----------------------------
    Doboz dobozok[5];
    for(int i = 0; i < 5; i++){
        Doboz d(i+1, i+4, i+2);
        dobozok[i] = d;
    }
    int magassag = 0;
    for(Doboz i : dobozok){
        magassag += i.height;
    }
    std::cout << "Ilyen magas: " << magassag << std::endl;

}

int fibo1(int n){
    if(n == 0){
        return 0;
    }
    if(n == 1){
        return 1;
    }
    return fibo1(n-1)+fibo1(n-2);
}

int fibof(int n){
    std::vector<int> t;
    t.reserve(n);

    int n1 = 0;
    int n2 = 1;
    for(int i = 0; i < n; i++){
        std::cout << n1 << ' ';

        int kov = n1 + n2;
        n1 = n2;
        n2 = kov;
    }
    return 0;
}

int bigfibo(int a, int b) {
    if (b < 0) return -1;

    int legnagyobb_fibo = -1;

    int elozo = 0;
    int jelenlegi = 1;
    

    if (a <= 0 && b >= 0) {
        legnagyobb_fibo = 0;
    }

    while (jelenlegi <= b) {
        if (jelenlegi >= a) {
            legnagyobb_fibo = jelenlegi; 
        }
        
        int kovetkezo = elozo + jelenlegi;
        elozo = jelenlegi;
        jelenlegi = kovetkezo;
    }

    return legnagyobb_fibo;
}

std::vector<float> egydim(int arr[4][4]){
    std::vector<float> avgArr;
    for(int i = 0; i < 4; i++){
        float avg = 0;
        for(int j = 0; j < 4; j++){
            avg += arr[i][j];
        }
        avg = avg/4;
        avgArr.push_back(avg);
    }
    return avgArr;
}

void beKer(){
    int n;
    std::cout << "Hány szót szeretnél beírni: ";
    std::cin >> n;
    if(n <= 0){
        std::cout << "Hiba";
        return;
    }

    std::vector<std::string> sztring;
    std::string ch;
    for(int i = 0; i < n; i++){
        std::cout << "Add meg a szót: ";
        std::cin >> ch;
        sztring.push_back(ch);
    }
    std::string legkisebb = sztring[0];
    std::string legnagyobb;
    for(std::string i : sztring){
        if(i.length()>legnagyobb.length()){
            legnagyobb = i;
        }
        if(i.length()<legkisebb.length()){
            legkisebb = i;
        } 
    }
    std::cout << "Legkisebb: " << legkisebb << " Legnagyobb: " << legnagyobb << std::endl;
}
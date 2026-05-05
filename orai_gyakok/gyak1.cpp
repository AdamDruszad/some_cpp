#include <iostream>

int g = 10;         //globális változó

#define LENGTH 10

using namespace std; //bárhova ahol std::"bármi" van ott elég lesz "bármi"-t írni

int main(){
    std::cout << "Hi!!!\n";
    std::cout << "Halooo\n";

    std::cout << "a" << " " << "bc" << std::endl;

    char c = 'c';
    int i = 1;
    short int si = 10;
    long int li = 100;
    float f = 11.1;
    double d = 11.1;
    bool b = true;

    std::string s = "xyz";

    std::cout << "float " << sizeof(float) << std::endl;
    std::cout << "double " << sizeof(double) << std::endl;

    int i1 = 1, i2 = 2;
    char x, y;
    int k;
    
    std::cout << x << " " << y << " " << k << std::endl;

    typedef int egesz;
    egesz e = 1;

    {
        //blokk
    }

    std::cout << g << std::endl;

    {
        std::cout << g << std::endl;
        int g = 11;     //lokális változó
        std::cout << g << std::endl;
    }

    const int a = 10;

    std::cout << "length" << std::endl;
    std::cout << LENGTH << std::endl;
    //std::cout << 10; << std::endl;

    //Unáris operátorok:
    // ++   --
    /*
        a = 1
        a++ --> a = a + 1   -- ez később végzi el
        ++a     -- ez előtte végzi el
    */

    //Bináris operátorok:
    // +    -   *   /   %

    //Tenáris operátorok:
    // ?    :

    int mod = 10 % 3;

    std::cout << mod << std::endl;
    std::cout << ++mod << std::endl;
    std::cout << mod++ << std::endl;
    std::cout << mod << std::endl;

    //Példa:
    /*
        int num1 = 3;
        int num2 = 3;
        int num3 = 3;

        num1 = num2++;
        num2 = --num3;

        std::cout << num1 << num2 << num3;
    */
    




}
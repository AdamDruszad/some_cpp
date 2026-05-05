#include <iostream>

int g = 10; //globális változó

#define LENGTH 10

int main(){

	std::cout<< "Hello, world\n";
	std::cout<< "Hello, world" << std::endl;
	
	std::cout<< "a" << " " << "b" << "c" << std::endl;
	
	char c = 'c'; //'c' karakter literál
	int i = 0;
	short int si = 10;
	long int li = 50;
	float f = 10.2;
	double d = 10.2;
	bool b = false;
	
	std::string s = "xyz"; //"xyz" string literál
	
	std::cout << "char " << sizeof(char) << std::endl;
	std::cout << "int " << sizeof(int) << std::endl;
	std::cout << "short int " << sizeof(short int) << std::endl;
	std::cout << "long int " << sizeof(long int) << std::endl;
	std::cout << "float " << sizeof(float) << std::endl;
	std::cout << "double " << sizeof(double) << std::endl;
	std::cout << "bool " << sizeof(bool) << std::endl;
	
	int z1 = 1, z2 = 2;
	char x, y;
	int p;
	
	std::cout << x << " " << y << " " << p << std::endl;
	
	//egysoros komment
	
	/*
		Többsoros
		komment.
	
	*/
	
	typedef int egesz;
	egesz e = 1;
	
	std::cout << g << std::endl;
	
	{
		std::cout << g << std::endl;
		int g = 15; //lokális változó
		std::cout << g << std::endl;
	}
	
	std::cout << g << std::endl;
	
	std::cout << LENGTH << std::endl;
	
	const int width = 11;

	//width = 12;
	
	//operátorok: + - * / % ++ --
	
	int mod = 10 % 3; //maradékos osztás.
	
	std::cout << mod << std::endl;
	std::cout << ++mod << std::endl;
	std::cout << mod++ << std::endl;
	std::cout << mod << std::endl;
	
	int num1 = 6;
	int num2 = 4;
	int num3 = 3;
	
	num1 = num2++;
	num2 = --num3;
	
	std::cout << num1 << num2 << num3 << std::endl;
}





 


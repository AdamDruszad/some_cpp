#include <iostream>

int g = 10; //globális

#define LENGTH 10

using namespace std;

int main(){

	std::cout<< "Hello, world\n";
	std::cout<< "Hello, world" << std::endl;
	
	std::cout << "a" << " " << "b" << "c" << std::endl;
	
	char a = 'c'; //'c' karakteres literál
	int i = 0;
	short int si = 1;
	long int li = 50;
	float f = 10.2;
	double d = 10.2;
	bool b = false;
	
	std::string s = "abc"; //"abc" string literál
	
	std::cout<<"char: " << sizeof(char)<< std::endl;
	std::cout<<"int: " << sizeof(int)<< std::endl;
	std::cout<<"short int: " << sizeof(short int)<< std::endl;
	std::cout<<"long int: " << sizeof(long int)<< std::endl;
	std::cout<<"float: " << sizeof(float)<< std::endl;
	std::cout<<"double: " << sizeof(double)<< std::endl;
	std::cout<<"bool: " << sizeof(bool)<< std::endl;
	
	int z1 = 1, z2 = 2;
	char x, y;
	int n;
	
	std::cout << x << " " << y << " " << n << std::endl;
	
	//egysoros komment
	
	/*
		többsoros komment
	
	*/
	
	typedef int egesz;
	
	egesz e = 0;
	
	std::cout << g << std::endl;
	
	{
		std::cout << g << std::endl;
		int g = 5; //lokális változó
		std::cout << g << std::endl;
	}
	
	std::cout << g << std::endl;
	
	std::cout << LENGTH << std::endl;
	
	const int width = 11;
	
	//width = 12;
	
	//operátorok + - * / % ++ --
	
	int mod = 10 % 3; //maradékos osztás, eredménye 1
	
	//++ increment, -- dec
	
	std::cout << mod << std::endl;
	std::cout << ++mod << std::endl;
	std::cout << mod++ << std::endl;
	std::cout << mod << std::endl;
	
	int num1 = 5;
	int num2 = 3;
	int num3 = 2;
	
	num1 = num2++;
	num2 = --num3;
	std::cout << num1 << num2 << num3 << std::endl;
	
	
	cout << num1 << num2 << num3 << endl;
	
	
	
	

}

#include <iostream>

int g = 10; //globális változó

#define LENGTH 10

int main(){

	std::cout<<"Hello, world\n";
	std::cout<<"Hello, world"<<std::endl;
	
	std::cout<< "a" << " " << "b"<< "c" <<std::endl;
	
	char c = 'c'; //'c' karakteres literál
	int i = 0;
	short int si = 10;
	long int li = 50;
	float f = 10.2;
	double d = 10.2;
	bool b = false;
	
	std::string s = "abx"; //"abx" string literál
	
	std::cout << "float " << sizeof(float) << std::endl;
	std::cout << "double " << sizeof(double) << std::endl;
	
	
	int i1 = 3, i2 = 2;
	char x, y;
	int p;
	
	std::cout << x << " " << y << " " << p << std::endl;
	
	//egysoros komment
	
	/*
		Többsoros
		komment
	*/
	
	typedef int egesz;
	egesz e = 1;
	
	std::cout << g << std::endl;
	
	{
		std::cout << g << std::endl;
		float g = 10.1; //lokális
		std::cout << g << std::endl;
		float l1 = 1.1;
	}
	std::cout << g << std::endl;
	//std::cout << l1 << std::endl;
	
	std::cout << LENGTH << std::endl;
	//std::cout << 10; << std::endl;
	
	const int width = 11;
	
	//width = 12 ;
	
	//operátorok: + - * / % ++ --
	
	int mod = 10 % 3; //maradékos osztás, eredmény 1
	
	std::cout << mod << std::endl;
	std::cout << ++mod << std::endl;
	std::cout << mod++ << std::endl;
	std::cout << mod << std::endl;
	
	
	int num1 = 6;
	int num2 = 3;
	int num3 = 5;
	
	num1 = num2++;
	num2 = --num3;
	
	std::cout << num1 << num2 << num3 << std::endl;
	
	

}

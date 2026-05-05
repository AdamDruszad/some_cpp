#include <iostream>

using namespace std;

int g = 10; //globális változó

#define LENGTH 10

int main(){

	std::cout<< "Hello, world\n";
	std::cout<< "Hello, world" << std::endl;
	
	std::cout<< "a" << " "<< "bc "<< std::endl;
	
	char c = 'c'; //'c' karakteres literál
	int i = 0;
	short int si = 10;
	long int li = 100;
	float f = 10.2;
	double d = 10.2;
	bool b = false;
	
	std::string s = "xyz"; //"xyz" string literál
	
	cout << "float " << sizeof(float) << endl;
	cout << "double " << sizeof(double) << endl;
	
	int z1 = 1, z2 = 2;
	char x, y;
	int k;	
	
	cout << x << " " << y << " " << k << endl;
	
	//egysoros komment
	
	/*
			Többsoros
			komment
	*/
	
	typedef int egesz;
	egesz e = 1;
	
	
	{
		//Blokk
	}
	
	cout << g << endl;
	
	{
		cout << g << endl;
		float g = 10.11; //lokális változó
		cout << g << endl;
		float f1 = 1.1;
	}
	
	//cout << f1 << endl;
	cout << g << endl;
	
	cout << LENGTH << endl; // cout << 10; << endl;
	
	const int co = 76;
	
	//co = 11;
	
	//operátorok + - * / % ++ --
	
	int mod = 10 % 3;//maradékos osztás, eredménye 1
	
	//a++    a = a+1;  	a--   a = a-1;
	//assignment of read-only variable ‘co’

	cout << mod << endl;
	cout << ++mod << endl;
	cout << mod++ << endl;
	cout << mod << endl; 
	
	int num1 = 7;
	int num2 = 3;
	int num3 = 6;
	
	num1 = num2++;
	num2 = --num3;
	
	cout << num1 << num2 << num3 << endl;
	
	
	
	

}







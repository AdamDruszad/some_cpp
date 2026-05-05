#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


bool isPrime(int n) {
    bool isPrime = true;

    // 0 and 1 are not prime numbers
    if (n == 0 || n == 1) {
        isPrime = false;
    }
    else {
        for (int i = 2; i <= n / 2; ++i) {
            if (n % i == 0) {
                isPrime = false;
                break;
            }
        }
    }
    return isPrime;
}


int main(){

	std::vector<int> v; //={};
	for(int i = 0; i<10; i++){
		v.push_back(i*10);
		cout << v[i] << " " << v.at(i) << " " << v.capacity() << endl;
	}
	
	cout << v[50] << endl;
	//cout << v.at(50) << endl;
	
	/*v[15] = 500;
	for(int i : v){
		cout << i << " " ;
	}
	cout << endl;*/
	
	v.shrink_to_fit();
	cout << v.capacity() << endl;
	
	cout << v.front() << " " << v.back() << endl;
	
	v.pop_back();
	cout << v.back() << endl;
	v.pop_back();
	cout << v.back() << endl;
	
	v.clear();
	
	v = {2, 5, 6, 3, 2, 9, 7 , 10, 1};
	//RENDEZZÜK NÖVEKVŐBE
	
	std::sort(v.begin(), v.end());
	
	for(int i : v){
		cout << i << " " ;
	}
	cout << endl;
	
	
	//maximum kiválasztás pozícióval
	int max = v[0];
	int maxind = 0;
	
	for(int i = 0; i< v.size(); i++){
		if( v[i] > max){
			max = v[i];
			maxind = i;
		}
	}
	
	cout << "A vektor maximuma: "<<max << " , pozíciója: " << maxind << endl;
	
	//szétválogatás
	//5-nél nagyobb
	
	vector<int> nagyobb;
	vector<int> kisebb;
	
	for(int i : v){
		if(i > 5){
			nagyobb.push_back(i);
		} else {
			kisebb.push_back(i);
		}
	}
	
	for(int i: nagyobb){
		cout << i << " " ;
	}
	cout << endl;
	
	for(int i: kisebb){
		cout << i << " " ;
	}
	cout << endl;
	
	//Megszámlálás
	//Hány darab 2-es szám van a vektorban?
	
	int count = 0;
	for(int i : v ){
		if ( i == 2 ){
			count++;
		}
	}
	cout << count << " db 2-es szám van a vektorban" << endl;
	
	//Hány darab prímszám van a vektorban?
	
	count = 0;
	
	for(int i : v){
		if( isPrime(i)){
			count++;
		}
	}
	cout << count << endl;
	
}









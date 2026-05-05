#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool isPrime(int n) {
    bool isPrime = true;

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

	std::vector<int> v; //{};
	
	for(int i = 0; i<10; i++){
		v.push_back(i*10);
		cout << v[i] << " " << v.at(i) << " " << v.capacity() << " " << v.data() << endl;
	}
	
	cout << v[50] << endl;
	//cout << v.at(50) << endl;
	v[0] = 15;
	cout << v.at(0) << endl;
	//Csak már létező elemre használható a []
	//v.capacity() === 16
	//v[15] = 150;
	//cout << v.at(15) << endl;
	
	v.shrink_to_fit();
	cout << v.capacity() << endl;
	
	cout << v.front() << " " << v.back() << endl;
	
	v.pop_back();
	cout << v.back() << endl;
	v.pop_back();
	cout << v.back() << endl;
	
	v.clear();
	
	
	//RENDEZZÜK NÖVEKVŐBE, majd írjuk ki
	v = {2, 5, 6, 3, 2, 9, 7, 10, 1};
	
	std::sort(v.begin(), v.end());
	
	for(int i : v){
		cout << i << " " ;
	}
	cout << endl;
	
	//maximum kiválasztás pozícióval
	int max = v[0];
	int maxind = 0;
	
	for(int i = 0; i< v.size(); i++){
		if(v[i] > max){
			max = v[i];
			maxind = i;
		}
	}
	
	cout << "A vektor maximuma: " << max << " , pozíciója: "<< maxind << endl; 
	
	//szétválogatás
	//Válogassuk szét az 5-nél nagyobb és kisebb számokat
	
	vector<int> nagyobb;
	vector<int> kisebb;
	
	for(int i : v){
		if(i > 5){
			nagyobb.push_back(i);
		} else {
			kisebb.push_back(i);
		}
	}
	
	for(int i : nagyobb){
		cout << i << " " ;
	}
	cout << endl;
	
	for(int i : kisebb){
		cout << i << " " ;
	}
	cout << endl;
	
	//megszámlálás
	//a vektorban található 2-esek száma
	
	int count = 0;
	for(int i : v){
		if(i == 2){
			count++;
		}
	}
	
	cout << "A vektorban " << count << " db 2-es található." << endl;
	
	//SZÁMOLJUK MEG A VEKTORBAN TALÁLHATÓ PRÍMSZÁMOKAT
	count = 0;
	
	for(int i : v){
		if( isPrime(i)){
			count++;
		}
	}
	cout << count << endl;
	
	std::vector<std::vector<int>> v2d; //= {}
	
	for(int i = 0; i < 5; i++){
		vector<int> v1d;
		for(int j= 0; j<5; j++){
			v1d.push_back(i+j*2);
		}
		v2d.push_back(v1d);
	}
	
	for(int i = 0; i< 5; i++){
		for(int j = 0; j< 5; j++){
			cout << v2d[i][j] << " " ;
		}
		cout << endl;
	}
	
	for(vector<int> v : v2d){
		for(int i : v){
			cout << i << " ";
		}
		cout << endl;
	}
	
	//RAKJUK CSÖKKENŐ SORRENDBE SORONKÉNT
	
	/*for(vector<int> v : v2d){
		sort(v.begin(), v.end(), std::greater<int>());
	}*/
	
	for(int i = 0; i< 5; i++){
		sort(v2d[i].begin(), v2d[i].end(), std::greater<int>());
		
	}
	
	for(vector<int> v : v2d){
		for(int i : v){
			cout << i << " ";
		}
		cout << endl;
	}
	
	



}









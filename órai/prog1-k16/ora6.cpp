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

	std::vector<int> v;//{1,2,3};
	
	for(int i = 0; i < 10; i++){
		v.push_back(i*10);
		cout << v[i] << " " << v.at(i) << " " << v.capacity() << " " << v.data() << endl;
	}
	
	cout << v[50] << endl; 
	//cout << v.at(50) << endl;
	
	//Létező elem módosítása
	v[0] = 15;
	cout << v[0] << endl;
	v.at(0) = 11;
	cout << v[0] << endl;
	
	v[15] = 10;
	//cout << v.at(15) << endl;
	cout << v[15] << endl;
	
	for(int i : v){
		cout << i << " " ;
	}
	cout << endl;
	
	v.shrink_to_fit();
	cout << v.capacity() << endl;	
	
	v.pop_back();
	cout << v.back() << endl;
	v.pop_back();
	cout << v.back() << endl;
	
	v.clear();
	
	//RENDEZZÜK NÖVEKVŐ SORRENDBE, írjuk ki
	v = {2, 5, 6, 7, 2, 9, 7, 10 ,1};	
	
	std::sort(v.begin(), v.end());
	
	for(int i : v){
		cout << i << " " ;
	} cout << endl;
	
	
	
	//SZÁMOLJUK MEG A VEKTORBAN TALÁLHATÓ PRÍMSZÁMOKAT
	
	
	int count = 0;
	
	for(int i : v){
		if( isPrime(i)){
			count++;
		}
	}
	cout << count << endl;
	
	std::vector<std::vector<int>> v2d;
	
	for(int i = 0; i< 5; i++){
		vector<int> v1d;
		for(int j = 0; j<5; j++){
			v1d.push_back(i+j*2);
		}
		v2d.push_back(v1d);
	}
	
	//RAKJUK CSÖKKENŐ SORRENDBE SORONKÉNT
	for(vector<int> v : v2d){
		for(int i : v){
			cout << i << " ";
		}
		cout << endl;
	}
	
	for(int i = 0; i< 5; i++){
		sort(v2d[i].begin(), v2d[i].end(), std::greater<int>());
		
	}
	
	for(vector<int> v : v2d){
		for(int i : v){
			cout << i << " ";
		}
		cout << endl;
	}
	
	//Maximum kiválasztás
	
	int max = v[0];
	int maxind = 0;
	
	for(int i = 0; i<v.size(); i++){
		if(v[i] > max){
			max = v[i];
			maxind = i;
		}
	}
	
	cout << "A vektor maximuma: "<< max << " a "<<maxind << ". pozíción található"<<endl; 
	
	//megszámlálás
	//Hány darab olyan elem található a vektorban, amely megfelel xy feltétel
	
	count = 0;
	for(int i = 0; i< v.size(); i++){
		if(v[i] == 2){
			count++;
		}
	}
	cout << count <<" db. 2-es van a vektorban."<<endl;
	
	//szétválogatás
	//válogassuk ki a 5-től nagyobb és kisebb elemeket egy-egy vektorba
	
	vector<int> sza;
	vector<int> szb;
	
	for(int i = 0; i< v.size(); i++){
		if(v[i] > 5){
			sza.push_back(v[i]);
		}
		if(v[i] < 5){
			szb.push_back(v[i]);
		}
	}
	cout << "5-től nagyobb: " << endl;
	for(int i : sza){
		cout << i << " " ;
	}
	cout << endl;
	
	cout << "5-től kisebb: " << endl;
	for(int i : szb){
		cout << i << " " ;
	}
	cout << endl;
	
}














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

	std::vector<int> v; //{}
	
	for(int i = 0; i<10; i++){
		v.push_back(i*10);
		cout << v[i] << " " << v.at(i) << " " << v.capacity() << " " << v.data() << endl;
	}
	
	cout << v[50] << endl;
	//cout << v.at(50) << endl;
	
	v[0] = 15;
	v.at(9) = 10;
	cout << v[0] << " " << v[9] << endl;
	
	v[12] = 150;
	cout << v[12] << endl;
	//cout << v.at(12) << endl;
	for(int i : v){
		cout << i << " " ;
	}
	cout << endl;
	
	v.shrink_to_fit();
	cout << v.capacity() << " " << v.size() << endl;
	
	v.clear();
	
	v = {2, 2, 3, 1, 2, 5, 7, 4, 8, 3};
	
	//RENDEZZÜK NÖVEKVŐ SORRENDBE, ÍRJUK KI
	
	std::sort(v.begin(), v.end());
	
	for(int i : v){
		cout << i << " " ;
	}
	cout << endl;
	
	//maximum kiválasztás pozícióval
	
	int max = v[0];
	int maxind = 0;
	
	for(int i = 0; i< v.size(); i++){
		if(max < v[i]){
			max = v[i];
			maxind = i;
		}
	}
	
	cout << "A vektor maximuma: " << max << ", pozíciója: " << maxind << endl;
	
	//megszámlálás:
	//hány xy feltételnek megfelelő elem található a konténerben
	//feltétel érték = 2
	
	int count = 0;
	for(int i : v){
		if(i == 2){
			count++;
		}
	}
	
	cout << "A konténerben " << count << "db 2-es található. " << endl;
	
	//szétválogatás:
	//válogassuk külön azokat az elemeket, amelyek megfelelnek/ nem felelnek meg egy feltétel
	//válogassuk szét az átlagtól kisebb és nagyobb elemeket
	
	int atlag =0;
	for(int i : v){
		atlag += i;
	}
	atlag /= v.size();
	
	vector<int> kisebb;
	vector<int> nagyobb;
	
	for(int i : v){
		if(i < atlag){
			kisebb.push_back(i);
		}
		if(i > atlag){
			nagyobb.push_back(i);
		}
	}
	cout << "Átlag: " << atlag << endl;
	cout << "Átlagtól kisebb:" << endl;
	for(int i:kisebb){
		cout << i << " " ;
	} cout << endl;
	
	cout << "Átlagtól nagyobb:" << endl;
	for(int i:nagyobb){
		cout << i << " " ;
	} cout << endl;
	
	//SZÁMOLJUK MEG A VEKTORBAN TALÁLHATÓ PRÍMSZÁMOKAT
	
	count = 0;
	
	for(int i : v){
		if( isPrime(i)){
			count++;
		}
	}
	cout << count << endl;
	
	//2D Vektor
	
	vector<vector<int>> v2d;
	
	for(int i = 0; i < 5; i++){
		vector<int> v1d;
		for(int j = 0; j< 5; j++){
			v1d.push_back(i+j*2);
		}
		v2d.push_back(v1d);
	}
	
	for(int i = 0; i< v2d.size(); i++){
		for(int j = 0; j < v2d[i].size(); j++){
			cout << v2d[i][j] << " " ;
		}
		cout << endl;
	}
	
	
	
	
	
	
	




}

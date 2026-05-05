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
		cout << v[i] << "  "<< v.at(i) << " " << v.capacity() << " " << v.data() << endl;
	}
	
	cout << v[50] << endl;
	//cout << v.at(50) << endl;
	
	v[0] = 15;
	cout << v[0] << endl;
	v.at(0) = 10;
	cout << v.at(0) << endl;
	
	v[15] = 10;
	cout << v[15] << endl;
	
	//cout << v.at(15) << endl;
	
	for(int i : v){
		cout << i << " " ;
	}
	cout << endl;
	
	v.shrink_to_fit();
	
	cout << v.capacity() << endl;
	
	v.clear();
	
	//RENDEZZÜK NÖVEKVŐ SORRENDBE, ÍRJUK KI
	v = {2, 5, 6, 2, 7, 9, 3, 2};
	
	std::sort(v.begin(), v.end());
	
	for(int i : v){
		cout << i << " ";
	}
	cout << endl;
	
	//maximum kiválasztás, pozícióval
	
	int max = v[0];
	int maxind = 0;
	
	for(int i = 0; i< v.size(); i++){
		if( v[i] > max){
			max = v[i];
			maxind = i;
		}
	}
	
	cout <<"A vektor maximuma: " << max << ", pozíciója: " << maxind << endl;
	
	//megszámlálás tétele:
	//számoljuk össze az xy feltételnek megfelelő elemeket a vektorban
	//feltétel: érték = 2;
	
	int count = 0;
	
	for(int i : v){
		if(i == 2){
			count++;
		}
	}
	
	cout << "A vektorban " << count << " db feltételnek megfelelő elem található." << endl;
	
	//szétválogatás:
	//feltétel mentén külön konténerekbe gyűjtés
	//válogassuk szét az átlagtól nagyobb és kisebb elemeket
	
	vector<int> kisebb;
	vector<int> nagyobb;
	
	int atlag = 0;
	
	for(int i: v){
		atlag+=i;
	}
	atlag/=v.size();
	cout << "Átlag: "<<atlag << endl;
	
	for(int i : v){
		if(i > atlag){
			nagyobb.push_back(i);
		}
		if(i < atlag){
			kisebb.push_back(i);
		}
	}
	cout << "kisebb: " << endl;
	for(int i: kisebb){
		cout << i << " " ;
	} cout << endl;
	cout << "nagyobb: " << endl;
	for(int i: nagyobb){
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
	
	vector<vector<int>> v2d;
	
	for(int i = 0; i<5; i++){
		vector<int> vt;	
		for(int j = 0; j<5; j++){
			vt.push_back(i+j*2);
		}
		v2d.push_back(vt);	
	}
	
	
	for(int i = 0; i< v2d.size(); i++){
		for(int j = 0; j< v2d[i].size(); j++){
			cout << v2d[i][j] << " " ;
		}
		cout << endl;
	}
	
	//RAKJUK CSÖKKENŐ SORRENDBE SORONKÉNT
	
	for(int i = 0; i< 5; i++){
		sort(v2d[i].begin(), v2d[i].end(), std::greater<int>());
		
	}
	cout << "Rendezés után: " << endl;
	
	for(vector<int> v : v2d){
		for(int i : v){
			cout << i << " ";
		}
		cout << endl;
	}








}

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

vector<string> unio(vector<string> a, vector<string> b){
    vector<string> uj;
    for(string i : a){
        uj.push_back(i);
    }
    for(string i : b){
        uj.push_back(i);
    }
    sort(uj.begin(), uj.end());
    for(int i = 0; i < uj.size()-1; i++){
        if(uj[i] == uj[i+1]){
            uj[i].erase();
        }
    }
    return uj;
}

int main(){
    vector<string> a = {"Anna", "Béla", "Csaba", "Dóra"};
    vector<string> b = {"Béla", "Erika", "Csaba", "Fanni"};
    vector<string> uj = unio(a, b);
    for(string x : uj){
        cout << x << " ";
    }
}
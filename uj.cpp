#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <fstream>

using namespace std;

int main() {

    string text;
    vector <string> v;

    ifstream File("asd.txt");

    while (getline(File, text)) {
        v.push_back(text);
    }

    cout << v[0] << endl << v[1] << endl;

    for (int i=0; i<sizeof(v[0]); i++) {
        cout << v[0][i] << endl;
    }


    File.close();

    return 0;
}
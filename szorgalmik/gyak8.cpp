#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

struct Allat{
    string nev;
    int kor;
    int suly;
};



int main(){
    
    /*
        ofstream - output filestream -- létrehoz, ír
        ifstream - input filestream -- olvas
        fstream - filestream
    */

//-------------------------------------------------------------------------

    /* 
        1. létrehozás (logikai állomány) (outfile)
        2. összerendelés (logikai-fizikai)
        3. megnyitás
    */
    ofstream outfile("file1.txt");

    /*
        4. feldolgozás
    */

    outfile << "Sikeres írás\n";
    outfile << "Második sor\n";
    outfile << "Harmadik sor\n";
    
    /*
        5. bezárás
    */
   outfile.close();

   ifstream infile("file1.txt");

   string text;

   while(getline(infile, text)){
    cout << text << endl;
   }

   infile.close();


   vector<Allat> allatok;
   int n;
   cout << "Hány állatot akarsz felvenni?";
   cin >> n;
   Allat a;
   for (int i = 0; i < n; i++){
    cout << "Adja meg az állat adatait(név, kor, súly)\n";
    cin >> a.nev >> a.kor >> a.suly;
    allatok.push_back(a);
   }

   ofstream outa("allatok.txt");
   for (Allat a : allatok){
    outa << a.nev << " " << a.kor << " " << a.suly << endl;
   }

   outa.close();

   ifstream ina("allatok.txt");

   vector<Allat> beolvasott;

   Allat olvas;

   while(ina >> olvas.nev >> olvas.kor >> olvas.suly){
    beolvasott.push_back(olvas);
   }

   float atlag = 0.0f;
   for(Allat a : beolvasott){
    atlag += float(a.suly);
   }

   atlag /= beolvasott.size();
   for (Allat a : allatok){
    cout << a.nev << " " << a.kor << " " << a.suly << endl;
   }

   cout << "Átlag: ";
   cout << atlag << endl;

   ina.close();


    return 0;
}